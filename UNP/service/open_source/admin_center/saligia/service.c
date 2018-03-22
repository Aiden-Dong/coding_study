#include "myservice.h"
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <errno.h>

extern PLISTEN_EVENT listen_event_head;
extern PLISTEN_EVENT listen_event_end;

int main()
{
	SERVICE_FD 		ser_fd;				// 文件描述符
	PLISTEN_EVENT		listen_the_event;		// 处理收集到的事件
	struct epoll_event 	listen_epoll_events[100];	// 收集监听到的事件
	int 			listen_epoll_num, i;		// 监听的事件的数目
	// 服务程序准备工作
	
	puts("service is opening :");
	puts("service is arranged to daemon ......");

	if(service_arranged(&ser_fd) == -1)
		err_que("service_arranged fause");

	else
		puts("service_arranged success");


	while(1)
	{
		
		listen_epoll_num = epoll_wait(ser_fd.epoll_fd, listen_epoll_events,100, 10000);
		// 等待事件的到来并监听事件

		for(i = 0; i < listen_epoll_num; i++)
		{
			listen_the_event = (PLISTEN_EVENT)listen_epoll_events[i].data.ptr;


			if(listen_the_event->st_fd == ser_fd.sock_fd)				// 表示是来自服务器的事件
			{
				if(listen_epoll_events[i].events & EPOLLHUP)
				{
					log_msg(&ser_fd, "service",listen_the_event->st_fd, "服务器端已经挂断");
					exit(0);
				}
				else if(listen_epoll_events[i].events & EPOLLERR)
				{
					log_msg(&ser_fd, "service",listen_the_event->st_fd, "服务器端发生意外错误");
					exit(0);
				}
				else if(listen_epoll_events[i].events & EPOLLIN)		
					accept_listen_event(&ser_fd);
			}
			else if(listen_epoll_events[i].events & EPOLLHUP)			// 客户端已经挂断
			{
				puts("客户端挂断");
				event_del(&ser_fd, listen_the_event);				
			}
			else if(listen_epoll_events[i].events & EPOLLERR)                       // 客户端已经挂断
                        {
                                puts("客户端发生错误");
                                event_del(&ser_fd, listen_the_event);                           
                        }
			else if(listen_epoll_events[i].events & EPOLLIN)			// 客户端的请求事件
			{
				puts("来自客户端的请求事件");
				recv_client_event(&ser_fd, listen_the_event);                    
			}
			else
				log_msg(&ser_fd, listen_the_event->st_name, listen_the_event->st_fd, "意外的消息类型");

		}
	}
	
	return 0;
}
