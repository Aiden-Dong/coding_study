#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

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
	int											sockfd;
	int											errinfo;
	int											recv_len;
	int											read_len;
	pthread_t 							ptid;
	char										strbuff[1024];
	struct sockaddr_in			serviceaddr;
	struct addrinfo					init_addrinfo, *res_addrinfo, *now_addrinfo;
	pthread_attr_t					pthattr;


	if(argc != 4)
		err_que("nc Ipaddress protoc comm");


	init_addrinfo.ai_flags = AI_CANONNAME;
	init_addrinfo.ai_family = AF_INET;
	init_addrinfo.ai_socktype = SOCK_STREAM;
	init_addrinfo.ai_protocol = IPPROTO_TCP;

	if(errinfo = getaddrinfo(argv[1], argv[2], &init_addrinfo, &res_addrinfo))
	{
		printf("getaddrinfo error : %s\n", gai_strerror(errinfo));
    exit(0);
	}

	for(now_addrinfo = res_addrinfo; now_addrinfo != NULL; now_addrinfo = now_addrinfo->ai_next)
	{
		if((sockfd = socket(now_addrinfo->ai_family, now_addrinfo->ai_socktype, now_addrinfo->ai_protocol)) == -1)
			continue;

		if(connect(sockfd, now_addrinfo->ai_addr, now_addrinfo->ai_addrlen) == -1)
			continue;

		break;
	}

	if(now_addrinfo == NULL)
		err_sys("connect error");

	if(res_addrinfo != NULL)
		freeaddrinfo(res_addrinfo);

	if(send(sockfd, argv[3], strlen(argv[3]), 0) == -1)
		err_sys("send error");

	if((read_len = recv(sockfd, strbuff, 1024, 0)) == -1)
		err_sys("recv error");

	write(STDOUT_FILENO, strbuff, read_len);
	write(STDOUT_FILENO, "\n", strlen("\n"));

	return 0;
}
