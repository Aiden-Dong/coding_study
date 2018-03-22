#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

void err_sys(const char *msg)
{
	printf("%s:%s\n", msg, strerror(errno));
	exit(errno);
}
void * recvfromservice(void *msg);

int main(int argc, char *argv[])
{
	int											sockfd;
	int											recv_len;
	int											read_len;
	pthread_t 							ptid;
	char										strbuff[1024];
	struct sockaddr_in			serviceaddr;
	pthread_attr_t					pthattr;


	if(argc != 2)
		err_que("client Ipaddress");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		err_sys("socket error");

	memset(&serviceaddr, 0, sizeof(serviceaddr));
	serviceaddr.sin_family = AF_INET;
	serviceaddr.sin_port	= htons(8068);
	if(inet_pton(AF_INET, argv[1], (void *)&serviceaddr.sin_addr.s_addr) == -1)
		err_sys("inet_pton error");

	// 链接服务器
	if(connect(sockfd, (struct sockaddr *)&serviceaddr, sizeof(serviceaddr)) == -1)
		err_sys("connect error");

	pthread_attr_init(&pthattr);
	pthread_attr_setdetachstate(&pthattr, PTHREAD_CREATE_DETACHED);
	pthread_create(&ptid, &pthattr, recvfromservice, &sockfd);

	while(read_len=read(STDIN_FILENO, strbuff, sizeof(strbuff)))
	{
		if(read_len == -1)
			err_sys("read_error");
		else if(read_len == 0)
		{
			close(sockfd);
			break;
		}
		else
			if(send(sockfd, strbuff, read_len, 0) == -1)
				err_sys("send error");
	}

	return 0;
}

void * recvfromservice(void *msg)
{
	int recv_len;
	char buff[1024];
	int servicefd = *(int *)msg;

	while(recv_len = recv(servicefd, buff, sizeof(buff), 0))
	{
		if(recv_len == -1)
			err_sys("recv error");

		if(write(STDOUT_FILENO, buff, recv_len) == -1)
			err_sys("send error");
	}
	exit(0);
}
