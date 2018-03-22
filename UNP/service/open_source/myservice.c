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
void log_msg(PSERVICE_FD pser_fd, PLISTEN_EVENT listen_event, const char *msg)
{
        MSG             send_log_msg;
        time_t          time_int;
        struct tm       *local_time;
        int             sock_len, time_long;
        char            sock_straddr[INET_ADDRSTRLEN];

        memset(&send_log_msg, 0, sizeof(MSG));
	if(listen_event)
	{
        	inet_ntop(AF_INET, &listen_event->st_addr, sock_straddr, INET_ADDRSTRLEN);	// 提取 IP 地址
        	time_int = time(NULL);								// 事件发生时间
        	local_time =localtime(&time_int);
		time_long = time_int - listen_event->st_time;					// 用户在线时间

		send_log_msg.msg_level = 1;
		sprintf(send_log_msg.msg_text, "%-s : %02d-%02d-%02d : %04d : %s\n", listen_event->st_name, 
						local_time->tm_mon, local_time->tm_mday, local_time->tm_hour, time_long, msg);
	}

	else
	{
		send_log_msg.msg_level = 1;
		sprintf(send_log_msg.msg_text, "service : %s\n", msg);
	}

	pthread_mutex_lock(&msg_mutex);
        if(msgsnd(pser_fd->msg_fd, &send_log_msg, sizeof(send_log_msg), IPC_NOWAIT) == -1)
                err_sys("msgsnd error");
	printf("写入数据\n");
	pthread_mutex_unlock(&msg_mutex);

}

//添加一个 事件
int event_add(PSERVICE_FD pser_fd, int listen_fd, const char *name, const char *dname, unsigned int off)
{
        struct epoll_event      listen_event;
        PLISTEN_EVENT           listen_msg;
        struct sockaddr_in      listen_addr;
        int                     listen_addr_len;

	// 获取对方的 IP
        memset(&listen_addr, 0, sizeof(listen_addr));           
        listen_addr_len = sizeof(struct sockaddr);
        if(getpeername(listen_fd, (struct sockaddr *)&listen_addr, &listen_addr_len) == -1)
                err_sys("getpeername error");

        // 事件注册
        listen_msg = (PLISTEN_EVENT)malloc(sizeof(LISTEN_EVENT));
        memset(listen_msg, 0, sizeof(LISTEN_EVENT));

        listen_msg->st_fd = listen_fd;				// 记录描述符
        if(name != NULL)
                strcpy(listen_msg->st_name, name);		// 记录用户名
        if(dname != NULL)	
                strcpy(listen_msg->st_dnam, dname);		// 记录当前所在目录
        listen_msg->st_time = time(NULL);			// 记录链接的当前时间
        listen_msg->st_off = off;				// 记录用户信息位置
        listen_msg->st_addr = listen_addr.sin_addr.s_addr;	// 记录用户登录 IP
        listen_msg->st_pass = 1;				// 写下用户凭证
	listen_msg->st_next= listen_event_head;			// 接入链表
	// 构造新链表
	pthread_rwlock_wrlock(&epoll_rwlock);
        if(listen_event_head == NULL)
                listen_event_end = listen_msg;
        listen_event_head = listen_msg;
	pthread_rwlock_unlock(&epoll_rwlock);

	// 将此事件放入监听池
        listen_event.events = EPOLLIN | EPOLLERR | EPOLLHUP;
        listen_event.data.ptr = (void *)listen_msg;

        if(epoll_ctl(pser_fd->epoll_fd, EPOLL_CTL_ADD, listen_fd, &listen_event) == -1)
                return -1;
	log_msg(pser_fd, listen_msg, "用户登录");	
        return 0;
}
int event_del(PSERVICE_FD pser_fd, PLISTEN_EVENT cur_event)
{
	PLISTEN_EVENT front_event = NULL;

	if( cur_event != listen_event_head)
	{
		front_event = listen_event_head;
		while(front_event->st_next != cur_event)
			front_event = front_event->st_next;
	}
	
	pthread_rwlock_wrlock(&epoll_rwlock);

	// 从表中摘掉此选项
	if(front_event == NULL)
		listen_event_head = cur_event->st_next;
	else
		front_event->st_next = cur_event->st_next;

	if(cur_event == listen_event_end)
		listen_event_end = front_event;
	
	
	pthread_rwlock_unlock(&epoll_rwlock);

	// 记录消息
	
	// 更改用户信息表
	if(admin_del(cur_event->st_name, cur_event->st_off))
		err_que("admin_del false");

	// 从监听池中删除此事件

	if(epoll_ctl(pser_fd->epoll_fd, EPOLL_CTL_DEL, cur_event->st_fd, NULL) == -1)
		err_sys("epoll_ctl error");

	log_msg(pser_fd, cur_event, "用户注销");

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
        while(listen_event_one != NULL)
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
                listen_event_one = listen_event_one->st_next;
        }
	puts("-----------------------------------------------");
	pthread_rwlock_unlock(&epoll_rwlock);
}

