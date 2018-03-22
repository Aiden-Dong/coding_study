#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <pthread.h>

void err_sys(const char *msg)
{
	printf("%s:%s\n", msg, strerror(errno));
	exit(errno);
}

void * sendtoclient(void * args);

int main(int argc, char *argv[])
{
	int 				i;
	pthread_t			ppid;
	pthread_attr_t		pthattr;
	int 				sockfd;
	int 				clientfd;
	int					addr_len;
	int 				read_len;
	char				ip_addr[INET_ADDRSTRLEN];
	struct sockaddr_in	service_addr;
	struct sockaddr_in	client_addr;
	char				readbuff[1024];

	// 建立套接字
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		err_sys("socket error");


	// 设置绑定地址
	memset(&service_addr, 0, sizeof(service_addr));
	service_addr.sin_family 	= AF_INET;
	service_addr.sin_port		= htons(8068);
	service_addr.sin_addr.s_addr= 0;

	// 绑定地址
	if(bind(sockfd, (struct sockaddr *)&service_addr, sizeof(service_addr)) == -1)
		err_sys("bind error");
	// 进入Listen 状态
	if(listen(sockfd, 5) == -1)
		err_sys("listen error");

	while(1)
	{
		// 等待客户端的连接
		if((clientfd=accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) == -1)
				err_sys("client error");

		printf("Accept form : %s\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip_addr, INET_ADDRSTRLEN));

		// 创建线程
		if(pthread_attr_init(&pthattr) == -1)
			err_sys("pthread_attr_init error");
		pthread_attr_setdetachstate(&pthattr, PTHREAD_CREATE_DETACHED);
		if(pthread_create(&ppid, &pthattr, sendtoclient, &clientfd) != 0)
			err_sys("pthread_creat error");

		// 接受客户端数据
		while(read_len = recv(clientfd, readbuff, sizeof(readbuff), 0))
		{
			if(read_len == -1)
				err_sys("read error");

			if(write(STDOUT_FILENO, readbuff, read_len)== -1)
				err_sys("write error");
		}
		
		// 取消线程
		close(clientfd);
		exit(0);
	}


	return 0;
}
void * sendtoclient(void * args)
{
	char strbuf[1024];
	int	 strlen;
	int clientfd = *(int *)args;

	while(strlen = read(STDIN_FILENO, strbuf, sizeof(strbuf)))
	{
		if(send(clientfd, strbuf, strlen, 0) == -1)	
			err_sys("send error");
	}
}

