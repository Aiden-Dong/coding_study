#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// 服务端用 epoll 实现

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
	int sock_fd, client_fd;
	int epoll_fd;
	int client_size;     				// 获取客户地址缓冲区的大小
	int listen_num;
	char buf[1024];
	int buf_size;
	char addr_buf[INET_ADDRSTRLEN];
	struct sockaddr_in sock_addr, client_addr;
	struct epoll_event event_ctl, event_listen[30];	// 事件结构
	
	
	// 创建 epoll 池 来监听事件
	epoll_fd = epoll_create(30);
	// 创建 socket;
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	// 将 socket 绑定到特定的 IP 地址
	sock_addr.sin_family = 	AF_INET;
	sock_addr.sin_port = 8080;
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	memset(sock_addr.sin_zero, 0, 8);	// 清空填充字符
	
	if(bind(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
		err_sys("bind error");

	// 监听来自客户端的连接事件
	event_ctl.events = EPOLLIN | EPOLLET;	// 使用边缘触发模式
	event_ctl.data.fd = sock_fd;
	if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &event_ctl) == -1)
		err_sys("epoll_sys error");
	// 进入监听模式
	if(listen(sock_fd, 5) == -1)
		err_sys("listen error");

	while(1)
	{
		int i;
		if((listen_num = epoll_wait(epoll_fd, event_listen, 30, 0)) == -1)
			err_sys("epoll_wait error");

		for(i = 0; i < listen_num; i++) 						// 检测事件
		{
			if(event_listen[i].data.fd == sock_fd)					// 表示有新的连接到达
			{
				if((client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_size)) == -1)
					err_sys("accept error");
			
				printf("有客户端的连接到达 : %s\n",
					inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr,addr_buf, INET_ADDRSTRLEN));

				event_ctl.data.fd = client_fd;
				event_ctl.events = EPOLLIN | EPOLLET | EPOLLHUP | EPOLLERR;
		
				epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event_ctl);
			}
			
			else if(event_listen[i].events & EPOLLIN)
			{	
				client_fd = event_listen[i].data.fd;
				// 获取对方的 IP 地址
				if(getpeername(client_fd ,(void *)&client_addr, &client_size) == -1)
					err_sys("getpeername error");
				
				printf("来自客户端的数据 : %s\n", 
					inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, addr_buf, INET_ADDRSTRLEN));

				// 接受客户端的数据并输出
				buf_size = recv(client_fd, buf, sizeof(buf), 0);
				
				if(buf_size == 0)
				{
					printf("%s 客户端已经关闭 \n", addr_buf);
					close(client_fd);
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &event_listen[i]);
				}
				else
					write(STDOUT_FILENO, buf, buf_size);
			}

			else if(event_listen[i].events & EPOLLHUP)
			{
				client_fd = event_listen[i].data.fd;
                                
                                if(getpeername(client_fd , (void *)&client_addr, &client_size) == -1)
                                 	err_sys("getpeername error");
                                
                                printf("客户端己经挂断 : %s\n",
					inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, addr_buf, INET_ADDRSTRLEN));

				// 关闭与客户端通信的套接字并删除此监听事件
				close(client_fd);	
				epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &event_listen[i]);  
                                
			}

			else if(event_listen[i].events & EPOLLERR)
                        {
                                client_fd = event_listen[i].data.fd;
                                
                                if(getpeername(client_fd , (void *)&client_addr, &client_size) == -1)
                                        err_sys("getpeername error");
                                
                                printf("客户端发生错误 : %s\n",
                                        inet_ntop(AF_INET, (void *)&client_addr.sin_addr.s_addr, addr_buf, INET_ADDRSTRLEN));
                                
                                // 关闭与客户端通信的套接字并删除此监听事件
                                close(client_fd);
                                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &event_listen[i]);  
                        }
			
		
		}
	}	
	
	return 0;
}
