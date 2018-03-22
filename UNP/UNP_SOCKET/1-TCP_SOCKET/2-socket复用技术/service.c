#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <sys/resource.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

#define LOGEFILE "./.saligia_ftp_log"		// 日志文件
#define LOCKFILE "./.saligia_ftp_lock"	// 文件互斥锁

// 测试是否有相同的进程开启
void test_service(void);
// 开启守护进程
void daemon_set(int stdfd);
// 向客户端发送数据请求
void *serv_to_client(void *msg);
// 获取当地时间
void get_time(char *msg);
// 中止信号处理
void sigint_chose(int signo);

void err_sys(const char *msg)
{
	char err_msg[128];
	memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s:%s\t", msg, strerror(errno));
	get_time(err_msg);
	write(STDOUT_FILENO, err_msg, strlen(err_msg));

	exit(errno);
}
void err_que(const char *msg)
{
	char err_msg[128];

	memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s\t", err_msg);
	get_time(err_msg);
	write(STDOUT_FILENO, err_msg, strlen(err_msg));
	exit(0);
}

typedef struct{
	char file_name[128];
	int  client_sock;
}CLIMSG, *PCLIMSG;

int main(int argc, char *argv)
{
	int 									logfd;
	int										service_fd;
	int										epoll_fd;
	int 									epoll_len;
	int 									index;
	int										sockopton;
	pthread_t							pthclient;
	int										clientaddrlen;
	int										clientsockfd;
	char									err_msg[128];
	char									log_msg[128];
	char									file_name[128];
	char									ip_addr[INET_ADDRSTRLEN];
	struct sockaddr_in		service_addr;
	struct sockaddr_in		client_addr;
	struct epoll_event  	set_event;
	struct epoll_event  	listen_events[10];
	struct timespec				nowtime;
	struct tm							*showtime;
	struct stat						filemsg;
	pthread_attr_t				pthread_msg;

	//创建日至记录文件
	if((logfd = open(LOGEFILE, O_RDWR|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
		err_sys("open error");

	daemon_set(logfd);

	// 创建服务器socket
	if((service_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		err_sys("socket error");
	// 创建监听池来接受数据
	if((epoll_fd = epoll_create(10)) == -1)
		err_sys("epoll error");

	// 绑定套接字
	memset(&service_addr, 0, sizeof(service_addr));
	service_addr.sin_family			= AF_INET;
	service_addr.sin_port			= htons(8068);
	service_addr.sin_addr.s_addr	= INADDR_ANY;

	sockopton = 1;
	if(setsockopt(service_fd, SOL_SOCKET, SO_REUSEADDR, &sockopton, sizeof(sockopton)) == -1)
		err_sys("setsockopt error");

	if(bind(service_fd, (struct sockaddr*)&service_addr, sizeof(service_addr)) == -1)
		err_sys("bind error");

	if(listen(service_fd, 10) == -1)
		err_sys("listen error");

	// 将 service 套接字加入监听池
	memset(&set_event, 0, sizeof(set_event));
	set_event.events	= EPOLLIN|EPOLLOUT;
	set_event.data.fd	= service_fd;

	if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, service_fd, &set_event) == -1)
		err_sys("epoll_ctl error");

	while(1)
	{
		// 监听套接字事件
		if((epoll_len = epoll_wait(epoll_fd, listen_events, 10, 10000000)) == -1)
			err_sys("epoll_wait error");

		for(index=0; index<epoll_len; index++)
		{
			//来自 LISTEN 套接字的事件
			if(listen_events[index].data.fd == service_fd)
			{
				if(listen_events[index].events & EPOLLERR)
				{
					memset(err_msg, 0, sizeof(err_msg));
					sprintf(err_msg,"listen_events error : %s\n", strerror(errno));
					if(write(STDOUT_FILENO, err_msg, strlen(err_msg)) == -1)
						err_sys("write error");
				}
				else if(listen_events[index].events & EPOLLIN)
				{
					clientaddrlen=sizeof(client_addr);

					if((clientsockfd = accept(service_fd, (struct sockaddr *)&client_addr, &clientaddrlen)) == -1)
							err_sys("accept error");

					memset(log_msg, 0, sizeof(log_msg));
					sprintf(log_msg, "%-15s:%05d\t\t%-30s\t",
						inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, ip_addr, INET_ADDRSTRLEN),
						ntohs(client_addr.sin_port), "client connect");
					get_time(log_msg);

					if(write(STDOUT_FILENO, log_msg, strlen(log_msg)) == -1)
						err_sys("write error");

					set_event.events = EPOLLIN | EPOLLERR;
					set_event.data.fd = clientsockfd;

					if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, clientsockfd, &set_event) == -1)
						err_sys("epoll_ctl error");
				}
			}
			else // 普通用户的连接请求
			{
				int clientfd = listen_events[index].data.fd;
				if(listen_events[index].events & EPOLLERR)
				{
					memset(log_msg, 0, sizeof(log_msg));
					sprintf(log_msg, "client link error\t");
					get_time(log_msg);
					if(write(STDOUT_FILENO, log_msg, strlen(log_msg)) == -1)
						err_sys("write error");

					if(epoll_ctl(epoll_fd, EPOLL_CTL_DEL,clientfd , &listen_events[index]) == -1)
							err_sys("epoll_ctl error");

					close(clientfd);
				}
				else if(listen_events[index].events & EPOLLIN)
				{
					memset(file_name, 0, sizeof(file_name));
					if(recv(clientfd, file_name, sizeof(file_name), 0) == -1)
							err_sys("recv error");

					// 记录用户请求文件信息
					clientaddrlen = sizeof(client_addr);
					if(getpeername(clientfd, (struct sockaddr *)&client_addr, &clientaddrlen) == -1)
						err_sys("getpeername error");

					if(inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip_addr, INET_ADDRSTRLEN) == NULL)
						err_sys("inet_ntop error");

					memset(log_msg, 0, sizeof(log_msg));
					sprintf(log_msg, "%-15s:%05d\t\t%-30s\t",ip_addr, ntohs(client_addr.sin_port),file_name);
					get_time(log_msg);

					if(write(STDOUT_FILENO, log_msg, strlen(log_msg)) == -1)
							err_sys("write error");

					if(stat(file_name, &filemsg) == -1)
					{
						if(errno = ENOENT)
						{
							send(clientfd, "file is not exist", strlen("file is not exist"), 0);
							if(epoll_ctl(epoll_fd, EPOLL_CTL_DEL,clientfd , &listen_events[index]) == -1)
								err_sys("epoll_ctl error");
							close(clientfd);
						}
						else
							err_sys("stat error");
					}
					else if(access(file_name, R_OK) == -1)
					{
						if(errno == EACCES)
						{
							send(clientfd, "file read false", strlen("file read false"), 0);
							if(epoll_ctl(epoll_fd, EPOLL_CTL_DEL,clientfd , &listen_events[index]) == -1)
								err_sys("epoll_ctl error");
							close(clientfd);
						}
						else
						err_sys("access error");
					}

					else
					{
						char SND_MSG[128];
						memset(SND_MSG, 0, sizeof(SND_MSG));
						sprintf(SND_MSG, "file size : %d", filemsg.st_size);
						if(send(clientfd, SND_MSG, strlen(SND_MSG), 0) == -1)
							err_sys("send error");

						PCLIMSG climsg = (PCLIMSG)malloc(sizeof(CLIMSG));

						memset(climsg, 0, sizeof(CLIMSG));
						strcpy(climsg->file_name, file_name);
						climsg->client_sock=clientfd;

						if(pthread_attr_init(&pthread_msg) == -1)
							err_sys("pthread_attr_init error");
						if(pthread_attr_setdetachstate(&pthread_msg, PTHREAD_CREATE_DETACHED) == -1)
							err_sys("pthread_attr_setdetached error");
						if(pthread_create(&pthclient, &pthread_msg, serv_to_client, climsg) != 0)
							err_sys("pthread_create error");

						if(epoll_ctl(epoll_fd, EPOLL_CTL_DEL,clientfd , &listen_events[index]) == -1)
								err_sys("epoll_ctl error");
					}
				}
			}
		}
	}

	return 0;
}
void test_service(void)
{
	int 					lockfd;
	struct flock 	lockmsg;

	if((lockfd = open(LOCKFILE, O_RDWR)) == -1)
		err_sys("file open error");

	memset(&lockmsg, 0, sizeof(lockmsg));
	lockmsg.l_type 		= F_WRLCK;
	lockmsg.l_whence 	= SEEK_SET;
	lockmsg.l_start 	= 0;
	lockmsg.l_len 		= 0;

	if(fcntl(lockfd, F_SETLK, &lockmsg) == -1)
	{
		if(errno == EAGAIN)
			exit(0);
		else
			err_sys("fcntl F_SETLK error");
	}

}
void daemon_set(int stdfd)
{
	int 						pid;
	int 						index;
	char						log_msg[128];
	struct rlimit 	filerlimit;
	sigset_t				sigblock;

	// 屏蔽终端字
	sigemptyset(&sigblock);
	sigaddset(&sigblock, SIGHUP);
	if(sigprocmask(SIG_BLOCK, &sigblock, NULL) == -1)
		err_sys("sigprocmask error");

	// 关闭所有的以打开的文件描述符
	if(getrlimit(RLIMIT_NOFILE, &filerlimit) == -1)
		err_sys("getrlimit error");
	for(index = 0; index < filerlimit.rlim_cur; index++)
		if(index != stdfd)
			close(index);

	// 重定义标准输入输出流
	if(fcntl(stdfd, F_DUPFD, 0) == -1)
		err_sys("fcntl error");
	if(fcntl(stdfd, F_DUPFD, 1) == -1)
		err_sys("fcntl error");
	if(fcntl(stdfd, F_DUPFD, 2) == -1)
		err_sys("fcntl error");

	if((pid = fork()) == -1)
		err_sys("fork error");

	if(pid != 0)
		exit(0);

	setsid();

	if((pid = fork()) == -1)
		err_sys("fork error");
	if(pid != 0)
		exit(0);

	test_service();

	memset(log_msg, 0, sizeof(log_msg));
	sprintf(log_msg, "service is opening\t");
	get_time(log_msg);

	if(write(STDOUT_FILENO, log_msg, strlen(log_msg)) == -1)
		err_sys("write error");
}
void *serv_to_client(void *msg)
{
	char									msg_buf[128];
	char									sysmsg[128];
	int										req_fd;
	int										read_len;
	int										clientaddrlen;
	sigset_t  						sigmask;
	struct timespec				starttime, endtime;

	PCLIMSG climsg = (PCLIMSG) msg;

	sigemptyset(&sigmask);
	sigaddset(&sigmask, SIGPIPE);


	if(pthread_sigmask(SIG_BLOCK, &sigmask, NULL) != 0)
		err_sys("pthread_sigprocmask error");

	if((req_fd = open(climsg->file_name, O_RDONLY)) == -1)
		err_sys("open error");

	if(clock_gettime(CLOCK_REALTIME, &starttime) == -1)
		err_sys("clock_gettime error");

	while(read_len = read(req_fd, msg_buf, sizeof(msg_buf)))
	{
		if(read_len == -1)
			err_sys("read error");
		if(send(climsg->client_sock, msg_buf, read_len, 0) == -1)
			break;
	}

	if(clock_gettime(CLOCK_REALTIME, &endtime) == -1)
		err_sys("clock_gettime error");

	memset(sysmsg, 0, sizeof(sysmsg));
	if(read_len == 0)
		sprintf(sysmsg, "%-40s\t file transport success :\t\t %d:%d\n",
						climsg->file_name, endtime.tv_sec-starttime.tv_sec, endtime.tv_nsec-starttime.tv_nsec);
	else
		sprintf(sysmsg, "%-40s\t file transport false :\t\t %d:%d\n",
					climsg->file_name, endtime.tv_sec-starttime.tv_sec, endtime.tv_nsec-starttime.tv_nsec);

	write(STDOUT_FILENO, sysmsg, strlen(sysmsg));

	close(req_fd);
	close(climsg->client_sock);
	free(climsg);

	return NULL;
}

void get_time(char *msg)
{
	struct timespec timenow;
	struct tm 			*showtime;
	char						*p;

	if(msg == NULL)
		err_que("time buff is null");

	p = msg + strlen(msg);

	if(clock_gettime(CLOCK_REALTIME, &timenow) == -1)
		err_sys("clock_gettime error");

	if((showtime = localtime(&timenow.tv_sec)) == NULL)
		err_que("localtime error");

	sprintf(p, "%02d-%02d  %02d:%02d:%02d\n", showtime->tm_mon+1, showtime->tm_mday,
								showtime->tm_hour, showtime->tm_min, showtime->tm_sec);
}
