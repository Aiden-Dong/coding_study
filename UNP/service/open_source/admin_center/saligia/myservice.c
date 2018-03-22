#include "myservice.h"
#include "public_source.h"
#include "admin_user.h"
#include "client_to_service.h"
#include "admin_user.h"
#include <sys/stat.h>
#include <pthread.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//记录要检测日志的列表
 
PLISTEN_EVENT listen_event_head = NULL;
PLISTEN_EVENT listen_event_end = NULL;

static pthread_mutex_t	msg_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_rwlock_t epoll_rwlock = PTHREAD_RWLOCK_INITIALIZER;

extern int pid;

// 日志记录
void log_msg(PSERVICE_FD pser_fd, char *usrname, int sock_fd, const char *msg)
{
        MSG             send_log_msg;
        time_t          time_int;
        struct tm       *local_time;
        int             sock_len;
        char            sock_straddr[INET_ADDRSTRLEN];

        memset(&send_log_msg, 0, sizeof(MSG));

        // 获取时间
        time_int = time(NULL);
        local_time =localtime(&time_int);

        sprintf(send_log_msg.msg_text, "%-10s : %d-%d-%d-%d : %-20s\n", usrname,
                                        local_time->tm_mon, local_time->tm_mday, local_time->tm_hour, local_time->tm_min, msg);
        send_log_msg.msg_level = 1;

	pthread_mutex_lock(&msg_mutex);
        if(msgsnd(pser_fd->msg_fd, &send_log_msg, sizeof(send_log_msg), IPC_NOWAIT) == -1)
                err_sys("msgsnd error");
	pthread_mutex_unlock(&msg_mutex);

}

//添加一个 事件
int event_add(PSERVICE_FD pser_fd, int listen_fd, const char *name, const char *dname, unsigned int off)
{
        struct epoll_event      listen_event;
        PLISTEN_EVENT           listen_msg;
        struct sockaddr_in      listen_addr;
        int                     listen_addr_len;

        // 事件注册
        listen_msg = (PLISTEN_EVENT)malloc(sizeof(LISTEN_EVENT));
        memset(listen_msg, 0, sizeof(LISTEN_EVENT));

        listen_msg->st_fd = listen_fd;

        if(name != NULL)
                strcpy(listen_msg->st_name, name);
        if(dname != NULL)
                strcpy(listen_msg->st_dnam, dname);
        listen_msg->st_time = time(NULL);

        // 获取对方的 IP
        memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr_len = sizeof(struct sockaddr);
        if(pser_fd->sock_fd != listen_fd)
                if(getpeername(listen_fd, (struct sockaddr *)&listen_addr, &listen_addr_len) == -1)
                        err_sys("getpeername error");

        listen_msg->st_off = off;
        listen_msg->st_addr = listen_addr.sin_addr.s_addr;
        listen_msg->st_pass = 1;
       
	// 在链表中注册事件
	listen_msg->st_next= listen_event_head;

	pthread_rwlock_wrlock(&epoll_rwlock);
        if(listen_event_head == NULL)
                listen_event_end = listen_msg;

        listen_event_head = listen_msg;

	pthread_rwlock_unlock(&epoll_rwlock);

        listen_event.events = EPOLLIN | EPOLLERR | EPOLLHUP;
        listen_event.data.ptr = (void *)listen_msg;

        if(epoll_ctl(pser_fd->epoll_fd, EPOLL_CTL_ADD, listen_fd, &listen_event) == -1)
                return -1;

        return 0;
}
int event_del(PSERVICE_FD pser_fd, PLISTEN_EVENT cur_event)
{
	PLISTEN_EVENT front_event = NULL;

	pthread_rwlock_wrlock(&epoll_rwlock);

	if( cur_event != listen_event_head)
	{
		front_event = listen_event_head;
		while(front_event->st_next != cur_event)
			front_event = front_event->st_next;
	}
	
	// 从表中摘掉此选项
	if(front_event == NULL)
		listen_event_head = cur_event->st_next;
	else
		front_event->st_next = cur_event->st_next;

	if(cur_event == listen_event_end)
		listen_event_end = front_event;
	
	
	pthread_rwlock_unlock(&epoll_rwlock);

	// 记录消息
	log_msg(pser_fd, cur_event->st_name, cur_event->st_fd, "用户注销");
	
	// 更改用户信息表
	if(admin_del(cur_event->st_name, cur_event->st_off))
		err_que("admin_del false");

	// 从监听池中删除此事件

	if(epoll_ctl(pser_fd->epoll_fd, EPOLL_CTL_DEL, cur_event->st_fd, NULL) == -1)
		err_sys("epoll_ctl error");

	free(cur_event);

	show_listen_events();

	return 0;
}
void show_listen_events(void)
{
        struct tm       * time_local;
        PLISTEN_EVENT   listen_event_one = listen_event_head;
        char            listen_addr[INET_ADDRSTRLEN];

	pthread_rwlock_rdlock(&epoll_rwlock);
	puts("-----------------------------------------------");
        while(1)
        {
                time_local = localtime(&listen_event_one->st_time);
                puts("===========================");
                printf("用户名         : %s\n", listen_event_one->st_name);
                printf("用户的当前目录 : %s\n", listen_event_one->st_dnam);
                printf("用户绑定的时间 : %d - %d - %d \n", time_local->tm_mday,
                                                               time_local->tm_hour,
                                                               time_local->tm_min);
                printf("用户当前文件位置: %d\n", listen_event_one->st_off);
                printf("用户地址 : %s\n", inet_ntop(AF_INET, (void *)&listen_event_one->st_addr, listen_addr, INET_ADDRSTRLEN));
                if(listen_event_one == listen_event_end)
                        break;
                listen_event_one = listen_event_one->st_next;
        }
	puts("-----------------------------------------------");
	pthread_rwlock_unlock(&epoll_rwlock);
}

void sig_action(int signo)
{
        int status;

        switch(signo)
        {
        case SIGINT:
                kill(pid, SIGINT);
                break;
        case SIGCHLD:
                waitpid(pid, &status, WNOHANG | WUNTRACED | WCONTINUED);
                if(WIFSIGNALED(status))
                {
                        puts("守护进程已经终止");
                        exit(0);
                }
                else if(WIFSTOPPED(status))
                {
                        puts("守护进程已经停止， 正在处理");
                        kill(pid, SIGCONT);
                }
                else if(WIFCONTINUED(status))
                        puts("守护进程已经正常运行");
                else
                {
                        puts("意外的子进程问题");
                        kill(pid, SIGINT);
                        exit(0);
                }
                break;
        default:
                puts("意外的消息");
                kill(pid, SIGINT);
        }
}

