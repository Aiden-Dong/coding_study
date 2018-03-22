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
int 				        sockfd;

void urg_sig(int signo);

int main(int argc, char *argv[])
{
	int 				        i;
	struct sigaction		act;
	int 				        clientfd;
	int					        addr_len;
	int 				        read_len;
	char				        ip_addr[INET_ADDRSTRLEN];
	struct sockaddr_in	service_addr;
	struct sockaddr_in	client_addr;
	char				        readbuff[1024];

	// 建立套接字
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		err_sys("socket error");


	// 设置绑定地址
	memset(&service_addr, 0, sizeof(service_addr));
	service_addr.sin_family 	= AF_INET;
	service_addr.sin_port		= htons(8068);
	service_addr.sin_addr.s_addr= 0;

	act.sa_handler = urg_sig;
	act.sa_mask = SIGURG;
	act.sa_flags = SA_RESTART;

	if(sigaction(SIGURG, &act, NULL) == -1)
		err_sys("sigaction error");

	if(fcntl(sockfd, F_SETOWN, getpid()) == -1)
		err_sys("fcntl error");

		
	// 绑定地址
	if(bind(sockfd, (struct sockaddr *)&service_addr, sizeof(service_addr)) == -1)
		err_sys("bind error");
	// 进入Listen 状态
	if(listen(sockfd, 5) == -1)
		err_sys("listen error");

	addr_len = sizeof(client_addr);
	// 等待客户端的连接
	if((clientfd=accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) == -1)
			err_sys("client error");

	printf("Accept form : %s\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip_addr, INET_ADDRSTRLEN));

	// 接受客户端数据
	while(read_len = recv(clientfd, readbuff, sizeof(readbuff), 0))
	{
		sleep(1);
		printf("接受到数据\n");
	}

	// 取消线程
	close(clientfd);

	return 0;
}
void urg_sig(int signo)
{
	char	msgoob[10];
	int 	len;

	printf("接受到带外数据\n");

	if((len = recv(sockfd, msgoob, 10, MSG_OOB)) == -1)
		err_sys("recv error");

	write(STDOUT_FILENO, msgoob, len);
}
