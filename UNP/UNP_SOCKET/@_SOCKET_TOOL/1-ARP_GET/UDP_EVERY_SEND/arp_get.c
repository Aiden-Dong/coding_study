#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
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
	printf("%s : %s\n", msg, strerror(errno));
	exit(errno);
}

int main(int argc, char *argv[])
{
	int 			i;
	uint8_t			*paddr;
	int 			sockfd;
	struct sockaddr_in	servaddr;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		err_sys("socket error");

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family 	= AF_INET;
	servaddr.sin_port	= htons(8068);
	if(inet_pton(AF_INET, "192.168.1.0", &servaddr.sin_addr.s_addr) == -1)
		err_sys("arpa_inet error");
	
	paddr = (uint8_t *)&servaddr.sin_addr.s_addr;
	
	for(i = 1; i < 255; i++)
	{
		paddr[3] = i;
		if(sendto(sockfd, "hello world\n", strlen("hello world\n"), 0, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
			err_sys("sendto error");
	}
	
	return 0;
}
