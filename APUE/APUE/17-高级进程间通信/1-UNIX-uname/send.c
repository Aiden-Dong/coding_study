#include <sys/socket.h>
#include <pthread.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#define KEY_FD (key_t)20132018

typedef struct{
	long msg_level;
	char msg_text[512];
}Mymess;

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}
inline void err_sys(const char *msg, int err)
{
	printf("%s : %s\n", msg, strerror(err));
	exit(0);
}



int main(int argc, char *argv[])
{
	int msg_fd;
	int num;
	struct msqid_ds ipc_mess;
	Mymess msg_one;	
	struct tm *ctime;

	if(argc != 3)
		err_que("please chose 0, 1, 2  or input your works for send");

	num = atoi(argv[1]);

	if(num != 1 && num !=2 && num!= 0)
		err_que("please chose 0, 1, 2");
	
	if((msg_fd = msgget(KEY_FD + num, 0660)) == -1)
		err_sys("msgget error", errno);
	
	if(msgctl(msg_fd, IPC_STAT, &ipc_mess) == -1)
		err_sys("msgget error", errno);

	ctime = localtime(&ipc_mess.msg_ctime);
	printf("消息的创建时间 : %d--%d--%d\n", ctime->tm_hour, ctime->tm_min, ctime->tm_sec);
	
	msg_one.msg_level = 1;
	strcpy(msg_one.msg_text, argv[2]);

	msgsnd(msg_fd, &msg_one, sizeof(msg_one), 0);

	return 0;
}

