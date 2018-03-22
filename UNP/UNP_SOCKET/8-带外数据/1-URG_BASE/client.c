// 带外数据的基本知识
// 2016年8月29日 星期一 at saligia

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

int main(int argc, char *argv[])
{
	int 										i;
	int											sockfd;
	int											recv_len;
	int											read_len;
	char										strbuff[2048];
	struct sockaddr_in			serviceaddr;


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

	if(send(sockfd, "Hello world", strlen("Hello world"), 0) == -1)
		err_sys("send error");

	if(send(sockfd, "a", 1, MSG_OOB) == -1)
		err_sys("send error");

	if(send(sockfd, "Hello world", strlen("Hello world"), 0) == -1)
		err_sys("send error");


	close(sockfd);

	return 0;
}
