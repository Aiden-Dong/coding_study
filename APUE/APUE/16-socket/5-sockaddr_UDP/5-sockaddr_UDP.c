#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// UDP 协议 的服务器模型

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main()
{
	fd_set listen_fd;
	int maxfd;
	int sockfd ;
	char addr_buf[INET_ADDRSTRLEN];
	char buf[1024];
	char addr_ip[INET_ADDRSTRLEN];			// 存放 ip 地址
	struct sockaddr_in sock_service, sock_client;
	int addr_len, len;

	// 创建套接字
	if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		err_sys("socket error");

	// 设置要绑定的 地址 及 端口号
	sock_service.sin_family = AF_INET;
	sock_service.sin_port = htons(8080);		// sin_port 占两个字节
	sock_service.sin_addr.s_addr = INADDR_ANY;
	memset(sock_service.sin_zero, 0, 8);

	// 绑定地址
	if(bind(sockfd, (struct sockaddr *)&sock_service, sizeof(sock_service)) == -1)
		err_sys("bind error");

	// 设置初始监听集
	FD_ZERO(&listen_fd);
	FD_SET(sockfd, &listen_fd);
	maxfd = sockfd;

	if(getsockname(sockfd, (struct sockaddr *)&sock_client, &addr_len) == -1)
		err_sys("getsockname error");

	printf("服务器绑定地址 : %s\n", 
		inet_ntop(AF_INET, (void *)&sock_client.sin_addr.s_addr, addr_buf, INET_ADDRSTRLEN));


	//接受来自客户端的数据
	while(1)
	{
		int i;

		if(select(maxfd+1, &listen_fd, NULL, NULL, NULL) == -1)
			err_sys("select error");
		for(i = 0; i <= maxfd; i++)
			if(FD_ISSET(i, &listen_fd)) // 表示发生可读事件
			{
				memset(buf, 0, sizeof(buf));
				len = recvfrom(i, buf, sizeof(buf), 0, (struct sockaddr *)&sock_client, &addr_len);
				// 接受来自客户端的数据
				printf("客户端发送数据到达 : %s\n", 
				inet_ntop(AF_INET, (void *)&sock_client.sin_addr.s_addr, addr_ip, INET_ADDRSTRLEN));
				write(STDOUT_FILENO, buf, len);
		
			}
	}
	return 0;
}
