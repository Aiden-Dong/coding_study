#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <netinet/in.h>
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
 *	客户端 
 ************************************************
 */
#define PATH_ADDR	"/tmp/saligia.socket"
#define FILE_NAME 
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
	char			buf[30];
	int 			buf_len;
 	struct sockaddr_un 	sockaddr_msg, client_msg;
	struct msghdr 		socket_msg;
	struct cmsghdr		*fd_msg;
	int 			sockaddr_len, clientaddr_len;
	int 			file_fd;

	if((sock_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)	// 创建 UNIX 域套接字	
		err_sys("socket error");

	// 绑定到 UNIX 套接字文件
	memset(&sockaddr_msg, 0, sizeof(sockaddr_msg));
	sockaddr_msg.sun_family = AF_UNIX;
	strcpy(sockaddr_msg.sun_path, PATH_ADDR);
	sockaddr_len = offsetof(struct sockaddr_un, sun_path) + strlen(sockaddr_msg.sun_path);	// 确定结构的大小
	

	if(connect(sock_fd, (struct sockaddr *)&sockaddr_msg, sockaddr_len) == -1)
		err_sys("connect error");

	memset(&socket_msg, 0, sizeof(socket_msg));
	fd_msg = malloc(FD_SIZE);
	socket_msg.msg_control		= fd_msg;
	socket_msg.msg_controllen	= FD_SIZE;
 
	if(recvmsg(sock_fd, &socket_msg, 0) == -1)
		err_sys("recvmsg error");

	file_fd = *(int *)CMSG_DATA(fd_msg);

	while(buf_len = read(file_fd, buf, sizeof(buf)))
	{
		if(buf_len == -1)
			err_sys("read error");
		write(STDOUT_FILENO, buf, buf_len);
	}
	printf("接受完成\n");
	free(fd_msg);
	return 0;
}
