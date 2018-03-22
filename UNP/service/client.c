#include <sys/stat.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define SE_SUCESS 0             // 操作成功
#define SE_OK     1             // 请求通过
#define SE_REFUSE 2             // 请求拒绝
#define SE_FAILE  3             // 操作失败
#define SE_ERROR  4             // 服务异常（服务端关闭）
#define SE_DONOW  5             // 正载执行服务操作
#define SE_FINISH 6             // 请求操作完成


#define CL_LOGIN  1             // 用户登录
#define CL_ENROLL 2             // 用户注册
#define CL_EXIT   3             // 用户退出
#define CL_CDDIR  4             // 进入目录
#define CL_EXDIR  5             // 退出目录
#define CL_CRDIR  6             // 创建目录
#define CL_RMFIL  7             // 删除文件
#define CL_CPFIL  8             // 复制文件
#define CL_MVFIL  9             // 移动文件
#define CL_SNDFL  10            // 上传文件
#define CL_RCVFL  11            // 下载文件
#define CL_ERROR  0             // 意外错误
typedef struct{
char     cts_events;             // 用户请求事件
char	cts_fname[21];		// 文件名
int	cts_ftype;		// 文件格式
int 	cts_fsize;		// 文件大小
char    cts_main[126];     	// 主目录
char    cts_minor[126];    	// 辅助目录
char    cts_text[47];           // 请求内容
}CLI_TO_SERV, *PCLI_TO_SERV;

typedef struct{
        char     stc_events;                     // 服务器回应事件
        char    stc_fname[21];		          // 文件名
        int     stc_ftype;                      // 文件格式
        int     stc_fsize;                      // 文件大小
        char    stc_mdir[126];           	// 操作目录
        char    stc_text[47];		         // 回馈内容
}SERV_TO_CLI, *PSERV_TO_CLI;

void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

CLI_TO_SERV     msg_sqe;
int             sock_fd;

void signo(int sig);

int main(int argc, char *argv[])
{
	int 		sock_addr_ip;
	int 		events;
	char		msg_buf[47];
	char 		my_dir[126];
	struct  	sockaddr_in service_addr;
	SERV_TO_CLI	msg_recv;

	printf("%d --- %d\n", sizeof(CLI_TO_SERV), sizeof(SERV_TO_CLI));
	if(argc != 4)
		err_sys("please input chose name passname");

	signal(SIGINT, signo);

	if ((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		err_sys("socket error");

	memset(&msg_buf, 0, sizeof(msg_buf));
	memset(&msg_sqe, 0, sizeof(CLI_TO_SERV));
	memset(&service_addr, 0, sizeof(service_addr));

	if(atoi(argv[1]) == 1)
		msg_sqe.cts_events	= CL_ENROLL;	// 注册事件 2
	else if(atoi(argv[1]) == 2)
                msg_sqe.cts_events      = CL_LOGIN;	// 登录事件 1

	strcat(msg_buf, argv[2]);
	strcat(msg_buf, ":");
	strcat(msg_buf, argv[3]);
	strcpy(msg_sqe.cts_text, msg_buf);

	service_addr.sin_family = AF_INET;
	service_addr.sin_port    = htons(8068);
	inet_pton(AF_INET, "192.168.1.100", (void *)&sock_addr_ip);
	service_addr.sin_addr.s_addr = sock_addr_ip;

	if(connect(sock_fd, (struct sockaddr *)&service_addr, sizeof(service_addr)) == -1)
		err_sys("connect error");

	send(sock_fd, &msg_sqe, sizeof(CLI_TO_SERV), 0);
	while(recv(sock_fd, &msg_recv, sizeof(SERV_TO_CLI), 0))
	{
		printf("==============================================\n");
		printf("events	: %d\n", msg_recv.stc_events);
		printf("name 	: %s\n", msg_recv.stc_fname);
		printf("type 	: %d\n", ntohl(msg_recv.stc_ftype));
		printf("size 	: %d\n", ntohl(msg_recv.stc_fsize));
		printf("mdir 	: %s\n", msg_recv.stc_mdir);
		printf("text 	: %s\n", msg_recv.stc_text);
/*
		if(ntohl(msg_recv.stc_events) != SE_DONOW &&  ntohl(msg_sqe.cts_events) != CL_ENROLL)
		{
			memset(my_dir , 0, 126);
			strcpy(my_dir, msg_recv.stc_mdir);
			
			puts("请输入事件:");
			scanf("%d", &events);
			msg_sqe.cts_events = htonl(events);

			getchar();
			puts("请输入文件名:");
			gets(msg_sqe.cts_fname);
			if(msg_sqe.cts_fname[strlen(msg_sqe.cts_fname) -1] == '\n')
				msg_sqe.cts_fname[strlen(msg_sqe.cts_fname) - 1] = 0;

			puts("文件格式 :");
			scanf("%d", &msg_sqe.cts_ftype);
			getchar();
			puts("目录 :");
			memset(msg_sqe.cts_main, 0, sizeof(msg_sqe.cts_main));
			strcpy(msg_sqe.cts_main, my_dir);
			
			send(sock_fd, &msg_sqe, sizeof(CLI_TO_SERV), 0);
		}*/
	}
		

	return 0;	
}

void signo(int sig)
{
	msg_sqe.cts_events      = htonl(CL_EXIT);
	send(sock_fd, &msg_sqe, sizeof(CLI_TO_SERV), 0);

	exit(0);
}
