#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main()
{
	int sock_fd;
	struct sockaddr_in server_addr;
	int addr;
	char buf[1024];
	int buf_len;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = 8080;
	inet_pton(AF_INET, "192.168.2.100", (void *)&addr);
	server_addr.sin_addr.s_addr = addr;
	memset(server_addr.sin_zero, 0, 8);

	if(connect(sock_fd, (void *)&server_addr, sizeof(server_addr)) == -1)
		err_sys("connect error");

	memset(buf, 0, sizeof(buf));

	buf_len = read(STDIN_FILENO, buf, sizeof(buf));
	
		if(buf_len == -1)
			err_sys("read error");
		
		send(sock_fd, buf, buf_len, 0);
	
	
	close(sock_fd);

	return 0;
}
