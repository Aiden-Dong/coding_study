#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/*
 * 队列消息：
 * 	消息的存放 是按照队列模型进程的， 可以先进先出， 也可以指定消息的类型存取消息
 *
 * 	消息的初始化， ipc_perm 结构按照实际的用户信息来初始化， msg_qbytes 取决于实现
 * 			msg_qnum | msg_lsqid | msg_lrqid | msg_stime | msg_rtime == 0
 * 			msg_ctime 为创建的时间
 * */
#define KEY_BUF "./3-process_msg.c"
#define MESG_NOR (long)1
#define MESG_NOT (long)2

typedef struct mymesg{
	long mtype;
	char mtext[512];
}Mymesg, *pMymesg;

void show_msg(const struct msqid_ds *msg_mess);
void show_message(const pMymesg mesg_rcv);
void show_time(const char *msg, time_t timenow);

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

void signo(int sig);

int main()
{
	key_t msg_key;
	struct msqid_ds msg_mess; 
	Mymesg mesg_send;
	int msg_id;
	int pid;
	

	msg_key = ftok(KEY_BUF, 1);	// 创建一个新的键值

	if((msg_id = msgget(msg_key, IPC_CREAT| IPC_EXCL | 0660)) == -1)
		err_sys("msgget error");

	if(msgctl(msg_id, IPC_STAT, &msg_mess) == -1)
		err_sys("msgctl error");

	show_msg(&msg_mess);

	if((pid = fork()) == -1)
		err_sys("fork error");
	else if(pid == 0)
	{
		sigset_t sig_mask, sig_omask;
		sigset_t sig_sus;
		Mymesg mesg_rcv;
		struct sigaction act;

		act.sa_handler = signo;
		act.sa_flags = SA_RESTART;
		sigemptyset(&act.sa_mask);

		if(sigaction(SIGUSR1, &act, NULL) == -1)
			err_sys("sigaction error");
		
		sigemptyset(&sig_mask);
		sigaddset(&sig_mask, SIGUSR1);
		sigfillset(&sig_sus);
		sigdelset(&sig_sus, SIGUSR1);

		if(sigprocmask(SIG_BLOCK, &sig_mask, &sig_omask) == -1)
			err_sys("sigprocmask error");
		
		sigsuspend(&sig_sus);

		if(msgrcv(msg_id, &mesg_rcv, sizeof(Mymesg), 0, IPC_NOWAIT) == -1)
			err_sys("msgrcv error");

		show_message(&mesg_rcv);

		if(msgctl(msg_id, IPC_STAT, &msg_mess) == -1)
			err_sys("msgctl error");
		show_msg(&msg_mess);
			
		if(msgctl(msg_id, IPC_RMID, NULL) == -1)
			err_sys("msgctl error");


		exit(0);
	}

	mesg_send.mtype = MESG_NOR;
	strcpy(mesg_send.mtext, "this is the first message ------- MESG_NOR");
	msgsnd(msg_id, &mesg_send, sizeof(Mymesg), IPC_NOWAIT);
	mesg_send.mtype = MESG_NOT;
	strcpy(mesg_send.mtext,"this is the second message -------- MESG_NOT");
	msgsnd(msg_id, &mesg_send, sizeof(Mymesg), IPC_NOWAIT);

	if(msgctl(msg_id, IPC_STAT, &msg_mess) == -1)
		err_sys("msgctl error");

	show_msg(&msg_mess);

	kill(pid, SIGUSR1);

	return 0;
}

void signo(int sig)
{
	printf("子进程开始运行 :\n");
}

void show_message(const pMymesg mesg_rcv)
{
	switch(mesg_rcv->mtype)
	{
	case MESG_NOR:
		printf("普通消息 :\n");
		printf("%s\n", mesg_rcv->mtext);
		break;
	case MESG_NOT:
		printf("通知消息 :\n");
		printf("%s\n", mesg_rcv->mtext);
		break;
	}
}
void show_msg(const struct msqid_ds *msg_mess)
{
	puts("msg_mess.msg_perm :");
	printf("uid : %d\ngid : %d\ncuid : %d\ncgid : %d\n",
		msg_mess->msg_perm.uid, msg_mess->msg_perm.gid,
		msg_mess->msg_perm.cuid, msg_mess->msg_perm.cgid);
	printf("mode  : %d\n", msg_mess->msg_perm.mode);	// 队列的权限信息
	printf("qnum  : %d\n", msg_mess->msg_qnum);	// 队列的信息数量
	printf("qbyte : %d\n", msg_mess->msg_qbytes);	// 队列的最大字节数量
	printf("lspid : %d\n", msg_mess->msg_lspid);	// 最后放入消息的进程
	printf("lrpid : %d\n", msg_mess->msg_lrpid);	// 最后取走消息的进程
	show_time("stime", msg_mess->msg_stime);
	show_time("rtime", msg_mess->msg_rtime);
	show_time("ctime", msg_mess->msg_ctime);
}

void show_time(const char *msg, time_t time)
{
	struct tm * locltm;

	locltm = localtime(&time);
	
	printf("%s : %d-%d-%d\n", msg, locltm->tm_hour, locltm->tm_min, locltm->tm_sec);
}
