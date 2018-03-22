#include <sys/socket.h>
#include <stddef.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * *********************************************
 *	命名的 UNIX 域套接字 ----- 唯一连接
 *
 *		struct sockaddr_un{
 *			sa_family_t	sun_family;	
 *			char		sun_path[108];  // 创建 S_IFSOCK类型的文件 （通常放在 /tmp 文件目录下）
 *		}
 *
 *	服务器端  
 ************************************************
 */
#define PATH_ADDR	"/tmp/saligia.socket"
#define FILE_NAME 	"./one.txt"
#define FD_SIZE		CMSG_LEN(sizeof(int))
	
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
	int 			sock_fd, service_fd;
 	struct sockaddr_un 	sockaddr_msg, client_msg;
	struct msghdr 		socket_msg;
	struct cmsghdr		*fd_msg;
	int 			sockaddr_len, clientaddr_len;
	int 			file_fd;

	if((sock_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)	// 创建 UNIX 域套接字	
		err_sys("socket error");
	
	if((file_fd = open(FILE_NAME, O_RDONLY)) == -1)
		err_sys("open error");

	// 绑定到 UNIX 套接字文件
	memset(&sockaddr_msg, 0, sizeof(sockaddr_msg));
	sockaddr_msg.sun_family = AF_UNIX;
	strcpy(sockaddr_msg.sun_path, PATH_ADDR);
	sockaddr_len = offsetof(struct sockaddr_un, sun_path) + strlen(sockaddr_msg.sun_path);	// 确定结构的大小
	
	if(bind(sock_fd, (struct sockaddr *)&sockaddr_msg, sockaddr_len) == -1)
		err_sys("bind error");

	if(listen(sock_fd, 10) == -1)						// 监听来自 UNIX 域的客户端的请求
		err_sys("listen error");

	memset(&socket_msg, 0, sizeof(socket_msg));

	fd_msg = malloc(FD_SIZE);
	fd_msg->cmsg_len 		= FD_SIZE;
	fd_msg->cmsg_level 		= SOL_SOCKET;
	fd_msg->cmsg_type		= SCM_RIGHTS;
	*(int *)CMSG_DATA(fd_msg)	= file_fd;
	socket_msg.msg_control		= fd_msg;
	socket_msg.msg_controllen	= FD_SIZE;
 
	if((service_fd = accept(sock_fd, (struct sockaddr *)&client_msg, &clientaddr_len)) == -1)
		err_sys("accept error");
	
	if(sendmsg(service_fd, &socket_msg, 0) == -1)
		err_sys("sendmsg error");

	printf("发送完成\n");

	free(fd_msg);
	unlink(PATH_ADDR);

	return 0;
}
