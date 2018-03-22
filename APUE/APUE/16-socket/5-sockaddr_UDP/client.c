#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main()
{
	int sockfd;
	int addr_ip;
	char buf[1024];
	int addr_len, len;
	struct sockaddr_in server_addr;

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	inet_pton(AF_INET, "192.168.2.100", (void *)&addr_ip);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	server_addr.sin_addr.s_addr = addr_ip;
	memset(server_addr.sin_zero, 0, 8);

	while(1)
	{
		memset(buf, 0, 1024);

		len = read(STDIN_FILENO, buf, sizeof(buf));

		sendto(sockfd, buf, len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
	
	}

	return 0;
}
