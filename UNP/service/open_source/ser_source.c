#include "myservice.h"
#include "sig_dispose.h"
#include "public_source.h"
#include "admin_user.h"
#include "client_to_service.h"
#include "admin_user.h"
#include <sys/stat.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>
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

// 定义的全局常量区

// 服务程序准备工作

/*
*	 函数接口变量
*/

int pid;

int service_arranged(PSERVICE_FD pser_fd)
{
        struct 		stat file_msg;
        struct 		sockaddr_in serv_addr;
	struct 		sigaction act, oact;
	pthread_attr_t	deta_status;
	pthread_t	serv_tid;
	int		pid_recv;
        int 		buf_len;
	int 		sock_opt = 1;
        char 		buf[50];
	
	// 创建队列消息来存放服务器所发生的一切事件
        if((pser_fd->msg_fd = msgget(MSG_KEY, IPC_CREAT|0600)) == -1)
                err_sys("msgget error");

	log_msg(pser_fd, NULL, "service is opening and now to test main of file");

	//检测服务器主目录 
	if(stat("myself", &file_msg) == -1)
                mkdir("myself", S_IRUSR|S_IWUSR|S_IXUSR);

        else if((file_msg.st_mode & S_IFMT) != S_IFDIR)
        {
                unlink("myself");
                mkdir("myself", S_IRUSR|S_IWUSR|S_IXUSR);
        }

	// 检测用户信息主目录
	if(stat(ADMIN_CENTER, &file_msg) == -1)
		mkdir(ADMIN_CENTER, S_IRUSR|S_IWUSR|S_IXUSR);
	else if((file_msg.st_mode & S_IFMT) != S_IFDIR)
	{
		unlink(ADMIN_CENTER);
		mkdir(ADMIN_CENTER, S_IRUSR|S_IWUSR|S_IXUSR);
	}

	//检测 用户账户信息是否存在， 不存在便创建
	if(stat(ADMIN_NAME, &file_msg) == -1)
		if(creat(ADMIN_NAME, 0600) == -1)
			err_sys("creat error");
	// 创建监听集
	if((pser_fd->epoll_fd = epoll_create(100)) == -1)
		err_sys("epoll_create error");
	// 创建 服务器端 套接字
        if((pser_fd->sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
                err_sys("socket error");

	if(setsockopt(pser_fd->sock_fd, SOL_SOCKET, SO_REUSEADDR, &sock_opt, sizeof(sock_opt)) == -1)
		err_sys("setsockopt error");

        memset(&serv_addr, 0, sizeof(struct sockaddr_in));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(SOCK_PORT);
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

        if(bind(pser_fd->sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1)
                err_sys("bind error");
        if(listen(pser_fd->sock_fd, 100) == -1)
                err_sys("listen error");
	
	// 启动线程监听链接事件
	pthread_attr_init(&deta_status);
	pthread_attr_setdetachstate(&deta_status, PTHREAD_CREATE_DETACHED);
	if((pid_recv = pthread_create(&serv_tid, &deta_status, accept_listen_event, pser_fd)) != 0)
	{
		printf("pthread_create error : %s", strerror(pid_recv));
		return -1;
	}
	pthread_attr_destroy(&deta_status);

	log_msg(pser_fd, NULL, "service is open success");

	return 1;

	// 打开管道来接收来自守护进程的消息， 并判断守护进程是否正常运行
	
}

void *accept_listen_event(void *arg)
{
	PSERVICE_FD 		fd;				// 服务端套接字
	int 			serto_client_fd;		// 与客户端关联的文件套接字
	struct sockaddr_in 	client_addr;			// 用户地址信息
	struct timeval		recv_timeout;
	int 			client_len;			// 用户地址长度
	char			client_dname[DNAM_LEN+1];	// 用户的目录地址
	CLI_TO_SERV 		cli_msg;			// 用户请求信息
	SERV_TO_CLI		ser_msg;			// 服务器返回信息
        int 			check_retu;			// 用户登录返回信息
	int 			admin_retu;			// 用户注册信息返回
	ADMIN_USR		admin_msg;			// 单用户信息
	int			recv_len;			// 接收字符长度


	fd = (PSERVICE_FD) arg;

	recv_timeout.tv_sec  = 0;
	recv_timeout.tv_usec = 100000;
	memset(&cli_msg, 0, sizeof(CLI_TO_SERV));
	memset(&client_addr, 0, sizeof(struct sockaddr));
	memset(&ser_msg, 0, sizeof(SERV_TO_CLI));
	memset(&client_dname, 0, sizeof(client_dname));
	client_len = sizeof(client_addr);

	while(1)
	{
	// 链接请求
	if((serto_client_fd = accept(fd->sock_fd, (struct sockaddr *)&client_addr, &client_len)) == -1)
		err_sys("accept error");
	printf("发现来自客户端的链接请求\n");
	// 分析客户端的请求问题

        if(setsockopt(fd->sock_fd, SOL_SOCKET, SO_RCVTIMEO, &recv_timeout, sizeof(recv_timeout)) == -1)
                err_sys("setsockopt error");

        if((recv_len = recv(serto_client_fd, &cli_msg, sizeof(CLI_TO_SERV), 0)) == -1)
	{
		log_msg(fd, NULL, "超时错误 : 链接请求失败");

		if(errno = ETIMEDOUT)
			puts("时间超时");
		else
			puts("其他错误原因");

		continue;
	}
	
	recv_timeout.tv_usec = 0;
	if(setsockopt(fd->sock_fd, SOL_SOCKET, SO_RCVTIMEO, &recv_timeout, sizeof(recv_timeout)) == -1)
                err_sys("setsockopt error");

	if(recv_len == 0)
	{
		close(serto_client_fd);
		continue;
	}

        switch(cli_msg.cts_events)								// 获取用户请求类型
        {
	// =======================  用户登录请求
        case CL_LOGIN:

                printf("用户登录\n");
		puts(cli_msg.cts_text);

                check_retu =admin_login(cli_msg.cts_text, &admin_msg);

                if(check_retu == -2)								// 用户名或密码失败
		{		
			ser_msg.stc_events = SE_REFUSE;		

			if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                  	{
                                close(serto_client_fd);
                                break;
			}
                        log_msg(fd, NULL, "用户名或密码错误");
			close(serto_client_fd);
		}

                else if(check_retu == -3)								// 表示用户已经在线		
		{
			ser_msg.stc_events = (SE_FAILE);
 
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
				close(serto_client_fd);
				break;
			}

                        log_msg(fd, NULL, "重复的用户登录");

			close(serto_client_fd);

		}
		else											// 用户登录成功
		{
			printf("用户登录成功进入设置\n");

			if(!client_to_dir(admin_msg.au_name, client_dname))
                                err_que("client_to_dir error");

			memset(&ser_msg, 0, sizeof(ser_msg));
			ser_msg.stc_events = (SE_SUCESS);
			strcpy(ser_msg.stc_mdir, client_dname);
			
			if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                break;
                        }

                        if(retu_direc(serto_client_fd, client_dname) == -1)
                        {
                                close(serto_client_fd);
                                break;
                        }
			
			memset(&ser_msg, 0, sizeof(ser_msg));
			ser_msg.stc_events = (SE_FINISH);
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                break;
                        }	
			
			event_add(fd, serto_client_fd, admin_msg.au_name, client_dname, check_retu);
			show_listen_events();
			printf("Login sucess\n");
		}

                break;

        case CL_ENROLL:	// ================ 用户注册请求

                printf("用户注册\n");

                admin_retu = admin_register(cli_msg.cts_text, &admin_msg);

		if(admin_retu == 0)						//请求拒绝
		{
			ser_msg.stc_events = (SE_REFUSE);

                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                break;
                        }

                        log_msg(fd, NULL, "用户注册失败");
			close(serto_client_fd);
		}
                else									// 请求通过
		{
			ser_msg.stc_events = (SE_SUCESS);
			
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                break;
                        }

			add_admin_user(admin_msg.au_name);				//为用户添加新的目录

                        log_msg(fd, NULL, "用户注册成功");

			close(serto_client_fd);
		}

                break;

      default:  //=================================== 意外请求
		ser_msg.stc_events = (SE_FAILE);

                send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0);
		log_msg(fd, NULL, "意外的用户请求");
                close(serto_client_fd);
        }
	}

		return NULL;
}

void recv_client_event(const PSERVICE_FD pser_fd, PLISTEN_EVENT listen_event)
{
	CLI_TO_SERV	client_event;
	SERV_TO_CLI	service_event;
	char		client_dir[DNAM_LEN+1];
	int 		recv_len;

	memset(&service_event, 0, sizeof(SERV_TO_CLI));
	memset(&client_event, 0, sizeof(CLI_TO_SERV));

	
	recv_len = recv(listen_event->st_fd, &client_event, sizeof(CLI_TO_SERV), 0);
	
	if(recv_len == 0 || recv_len == -1)	// 表示用户退出事件
	{
		puts("用户退出事件");
		if(recv_len == -1)
			printf("recv_error : %s\n", strerror(errno));
		event_del(pser_fd, listen_event);
		return;
	}

	printf("进入事件\n");

	switch(client_event.cts_events)
	{
	case CL_EXIT:					// 用户退出事件
		puts("用户退出require");
		event_del(pser_fd, listen_event);
		break;
	case CL_CDDIR :					// 用户进入目录
		puts("用户进入目录");	

		puts(client_event.cts_main);
		puts(listen_event->st_name);

		if(admin_checkdir(client_event.cts_main, listen_event->st_name) == -1)
		{
			printf("check error\n");
			service_event.stc_events = (SE_REFUSE);
                	send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0);
                	return ;
		}

		service_event.stc_events = SE_OK;
		strncpy(service_event.stc_mdir, client_event.cts_main, strlen(client_event.cts_main));
		strncpy(listen_event->st_dnam, client_event.cts_main, strlen(client_event.cts_main));

		if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
		{
			event_del(pser_fd, listen_event);
			return ;
		}

		retu_direc(listen_event->st_fd, listen_event->st_dnam);

		puts("Sucess to Enter DIR");

		service_event.stc_events = SE_FINISH;
		if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
		{
			event_del(pser_fd, listen_event);
		}
		show_listen_events();
		break;

	case CL_EXDIR :					// 用户退出目录
		puts("用户退出目录");

		puts(client_event.cts_main);
                puts(listen_event->st_name);

		if(back_dir(client_event.cts_main, listen_event->st_name) == -1)
		{
			service_event.stc_events = (SE_REFUSE);
                       	if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
				event_del(pser_fd, listen_event);
			return ;
		}
		memset(listen_event->st_dnam, 0, sizeof(listen_event->st_dnam));
		strncpy(listen_event->st_dnam, client_event.cts_main, strlen(client_event.cts_main));
		service_event.stc_events = SE_OK;
		strncpy(service_event.stc_mdir, client_event.cts_main, strlen(client_event.cts_main));
			
		if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
                {
                        event_del(pser_fd, listen_event);
                        return ;
                }
			
		retu_direc(listen_event->st_fd, listen_event->st_dnam);

		puts("sucess to ExDir");

                service_event.stc_events = SE_FINISH;
                if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
                       	event_del(pser_fd, listen_event);
		break;
	case CL_CRDIR :					// 用户创建目录
		puts("Makir ---");
		puts(client_event.cts_fname);
		puts(client_event.cts_main);

		if(admin_mkdir(client_event.cts_main, listen_event->st_name, client_event.cts_fname) == -1)
		{
			puts("Make error");
			service_event.stc_events = (SE_REFUSE);
                        send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0);
                        return ;
		}	
                service_event.stc_events = SE_OK;
                if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
                           event_del(pser_fd, listen_event);
		break;
	case CL_RMFIL : 				// 用户删除文件
		
	case CL_CPFIL :					// 用户复制文件
	case CL_MVFIL :					// 用户移动文件
	case CL_SNDFL :					// 用户上传文件
	case CL_RCVFL :					// 用户下载文件
	default:
		printf("其他事件到达\n");		
	}

}

