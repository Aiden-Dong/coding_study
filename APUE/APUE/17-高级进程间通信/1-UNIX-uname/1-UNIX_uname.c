#include <sys/socket.h>
#include <pthread.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>

#define KEY_FD (key_t)20132018

typedef struct{
	int 	msg_fd;
	int 	sock_fd;
}Msg, *pMsg;

typedef struct{
	long mtype;
	char mtext[512];
}mymesg;

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


void *pthread_send(void *msg);

int main()
{
	int 		i;
	pthread_t 	tid[3];			// 线程标志
	int 		msg_fd[3];		// 队列消息标志
	int 		socket_fd[2];		// UNIX 域套接字
	Msg		thread_msg[3];		// 传送给线程的消息参数
	char 		buf[512];		// 消息体

	if(socketpair(AF_UNIX, SOCK_DGRAM, 0, socket_fd) == -1)
		err_sys("socketpair error");

	for(i = 0 ; i < 3; i++)
	{
		if((msg_fd[i] = msgget(KEY_FD+i, IPC_CREAT | 0660)) == -1)
			err_sys("msgget error");

		thread_msg[i].sock_fd = socket_fd[1];
		thread_msg[i].msg_fd  = msg_fd[i];

		if(pthread_create(&tid[i], NULL, pthread_send, (void *)&thread_msg[i]) != 0)
			err_sys("pthread_create error");
	}

	while(1)
	{
		int len;
		if((len = read(socket_fd[0], buf, sizeof(buf))) == -1)
			err_sys("read error");

		write(STDOUT_FILENO, buf, len);
	}
	
	return 0;
}

void *pthread_send(void *msg)
{
	
	pMsg my_mess = (pMsg)msg;
	mymesg msg_buf;
	char buf[512];

	printf("线程开始运行\n");

	while(1)
	{
		int len;

		memset(buf, 0, sizeof(buf));
		if((len = msgrcv(my_mess->msg_fd, &msg_buf, sizeof(msg_buf), 0, 0)) == -1)
			err_sys("msgrcv error");
		printf("已经接受到数据 :%s\n", msg_buf.mtext);
		strcpy(buf, msg_buf.mtext);
		write(my_mess->sock_fd, buf, sizeof(buf));
	}

	pthread_exit(NULL);
}

