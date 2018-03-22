#include "myservice.h"
#include "public_source.h"
#include "admin_user.h"
#include "client_to_service.h"
#include "admin_user.h"
#include <sys/stat.h>
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

// 定义的全局常量区

// 服务程序准备工作
/*
*	 函数接口变量
*/
int pid;

static void exit_chose()
{
        kill(pid, SIGINT);
}

int service_arranged(PSERVICE_FD pser_fd)
{
        struct 		stat file_msg;
        struct 		sockaddr_in serv_addr;
	struct 		sigaction act, oact;
        int 		buf_len;
	int 		sock_opt = 1;
        char 		buf[50];
	
	if(stat("myself", &file_msg) == -1)
                mkdir("myself", S_IRUSR|S_IWUSR|S_IXUSR);

        else if((file_msg.st_mode & S_IFMT) != S_IFDIR)
        {
                unlink("myself");
                mkdir("myself", S_IRUSR|S_IWUSR|S_IXUSR);
        }

	if(stat(ADMIN_CENTER, &file_msg) == -1)
		mkdir(ADMIN_CENTER, S_IRUSR|S_IWUSR|S_IXUSR);
	else if((file_msg.st_mode & S_IFMT) != S_IFDIR)
	{
		unlink(ADMIN_CENTER);
		mkdir(ADMIN_CENTER, S_IRUSR|S_IWUSR|S_IXUSR);
	}

	// 重新创建与daemon 通话的 fifo
        if(stat(FIFO_FILE, &file_msg) != -1)
                unlink(FIFO_FILE);
        if(mkfifo(FIFO_FILE, S_IRUSR|S_IWUSR) == -1)
                err_sys("mkfifo error");

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
	
	// 创建队列消息来存放服务器所发生的一切事件
        if((pser_fd->msg_fd = msgget(MSG_KEY, IPC_CREAT|0600)) == -1)
                err_sys("msgget error");
	// 查看守护进程的 日志文件是否存在不存在便创建
        if(stat(DAEMON_FILE, &file_msg) == -1)
                if(creat(DAEMON_FILE, S_IRUSR|S_IWUSR) == -1)
                        err_sys("create error");

	event_add(pser_fd, pser_fd->sock_fd, "service", NULL, 0);

        if((pid = fork()) == -1)
                err_sys("fork error");

        else if(pid == 0)
        {
                struct rlimit rlimit_fd;
                int i;

                getrlimit(RLIMIT_NOFILE , &rlimit_fd);
                for(i = 4; i < rlimit_fd.rlim_max; i++)
                        close(i);
		// 打开守护进程 来 写日志
                if(execl("./daemon.out" , NULL) == -1)
                        err_sys("execl error");
        }


	// 打开管道来接收来自守护进程的消息， 并判断守护进程是否正常运行
	if((pser_fd->fifo_fd = open(FIFO_FILE, O_RDONLY)) == -1)
                err_sys("open error");
	// 注意 ： 有名管道要先写打开后读打开
	
	/*
	×	处理信号问题
	*/
	act.sa_handler	= sig_action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, &oact);
	sigaction(SIGCHLD, &act, &oact);

	memset(buf, 0, sizeof(buf));
		
        buf_len = read(pser_fd->fifo_fd, buf, sizeof(buf));

        if(strncmp(buf, "sucess", 6) == 0)
	{
		atexit(exit_chose);
                return 1;
	}
        else
        {
                if(buf_len != -1)
                        write(STDOUT_FILENO, buf, buf_len);
                return -1;
        }
}
void accept_listen_event(PSERVICE_FD fd)
{
	int 			serto_client_fd;		// 与客户端关联的文件套接字
	struct sockaddr_in 	client_addr;			// 用户地址信息
	int 			client_len;			// 用户地址长度
	char			client_dname[DNAM_LEN+1];	// 用户的目录地址
	CLI_TO_SERV 		cli_msg;			// 用户请求信息
	SERV_TO_CLI		ser_msg;			// 服务器返回信息
        int 			check_retu;			// 用户登录返回信息
	int 			admin_retu;			// 用户注册信息返回
	ADMIN_USR		admin_msg;			// 单用户信息
	int			recv_len;			// 接收字符长度


	memset(&cli_msg, 0, sizeof(CLI_TO_SERV));
	memset(&client_addr, 0, sizeof(struct sockaddr));
	memset(&ser_msg, 0, sizeof(SERV_TO_CLI));
	memset(&client_dname, 0, sizeof(client_dname));
	client_len = sizeof(client_addr);

	// 链接请求
	printf("发现客户端的链接请求\n");
	if((serto_client_fd = accept(fd->sock_fd, (struct sockaddr *)&client_addr, &client_len)) == -1)
		err_sys("accept error");

	// 分析客户端的请求问题
        if((recv_len = recv(serto_client_fd, &cli_msg, sizeof(CLI_TO_SERV), 0)) == -1)
                err_sys("recv error");

	if(recv_len == 0)
	{
		close(serto_client_fd);
		return;
	}

        switch(cli_msg.cts_events)								// 获取用户请求类型
        {
	// =======================  用户登录请求
        case CL_LOGIN:

                printf("用户登录\n");

                check_retu =admin_login(cli_msg.cts_text, &admin_msg);

                if(check_retu == -2)								// 用户名或密码失败
		{		
			ser_msg.stc_events = SE_REFUSE;		

			if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                  	{
                                close(serto_client_fd);
                                return;
			}
                        log_msg(fd, "NULL", serto_client_fd, "用户名或密码错误");
			close(serto_client_fd);
		}

                else if(check_retu == -3)								// 表示用户已经在线		
		{
			ser_msg.stc_events = (SE_FAILE);
 
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
				close(serto_client_fd);
				return;
			}

                        log_msg(fd, admin_msg.au_name, serto_client_fd, "重复的用户登录");

			close(serto_client_fd);

		}
		else											// 用户登录成功
		{
			if(!client_to_dir(admin_msg.au_name, client_dname))
                                err_que("client_to_dir error");

			memset(&ser_msg, 0, sizeof(ser_msg));
			ser_msg.stc_events = (SE_SUCESS);
			strcpy(ser_msg.stc_mdir, client_dname);
			
			if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                return;
                        }

                        if(retu_direc(serto_client_fd, client_dname) == -1)
                        {
                                close(serto_client_fd);
                                return ;
                        }
			
			memset(&ser_msg, 0, sizeof(ser_msg));
			ser_msg.stc_events = (SE_FINISH);
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                return;
                        }	
			
			event_add(fd, serto_client_fd, admin_msg.au_name, client_dname, check_retu);	
				
                        log_msg(fd, admin_msg.au_name, serto_client_fd, "用户登录成功");

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
                                return;
                        }

                        log_msg(fd, "NULL", serto_client_fd,"用户注册失败");
			close(serto_client_fd);
		}
                else									// 请求通过
		{
			ser_msg.stc_events = (SE_SUCESS);
			
                        if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)
                        {
                                close(serto_client_fd);
                                return;
                        }

			add_admin_user(admin_msg.au_name);				//为用户添加新的目录

                        log_msg(fd, admin_msg.au_name, serto_client_fd, "用户注册成功");

			close(serto_client_fd);
		}

                break;

      default:  //=================================== 意外请求
		ser_msg.stc_events = (SE_FAILE);

                if(send(serto_client_fd, &ser_msg, sizeof(SERV_TO_CLI), 0) == -1)      
		{
                                close(serto_client_fd);
                                return;
                }
		close(serto_client_fd);
        }
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

	switch(ntohl(client_event.cts_events))
	{
	case CL_EXIT:					// 用户退出事件
		puts("用户退出事件");
		event_del(pser_fd, listen_event);
		break;
	case CL_CDDIR :					// 用户进入目录
		puts("用户进入目录");	
		
		if(admin_checkdir(client_dir, listen_event->st_name) == -1)
		{
			service_event.stc_events = (SE_REFUSE);
                	send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0);
			event_del(pser_fd, listen_event);
                	return ;
		}

		service_event.stc_events = SE_OK;
		strncpy(service_event.stc_mdir, client_event.cts_main, strlen(client_event.cts_main));
		if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
		{
			event_del(pser_fd, listen_event);
			return ;
		}

		retu_direc(listen_event->st_fd, listen_event->st_dnam);

		service_event.stc_events = SE_FINISH;
		if(send(listen_event->st_fd, &service_event, sizeof(SERV_TO_CLI), 0) == -1)
		{
			event_del(pser_fd, listen_event);
		}
		show_listen_events();
		break;

	case CL_EXDIR :					// 用户退出目录
		puts("用户退出目录");
		
	case CL_CRDIR :					// 用户创建目录
	case CL_RMFIL : 				// 用户删除文件
	case CL_CPFIL :					// 用户复制文件
	case CL_MVFIL :					// 用户移动文件
	case CL_SNDFL :					// 用户上传文件
	case CL_RCVFL :					// 用户下载文件
	default:
		printf("其他事件到达\n");		
	}
}

