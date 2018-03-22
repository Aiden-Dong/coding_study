#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>

void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int path_make(const char *cmd, char *path);

int main(int argc, char *argv[])
{
	mqd_t		mqfd;
	int		pid;
	struct mq_attr	mq_attr;
	int		state;

	if(argc != 2)
		err_que("Command QueueFile");

	if((pid = fork()) == 0)	// 子进程
	{
		int		mqfd;
		int		prio;
		char		*buf;
		int		recvlen;
		struct mq_attr	attr_msg;
		
		sleep(3);		// 让父进程做好准备

		if((mqfd = mq_open(argv[1], O_RDWR)) == -1)
			err_sys("mq_open error");

		if(mq_getattr(mqfd, &attr_msg) == -1)
			err_sys("mq_getattr error");

		buf = (char *)malloc(attr_msg.mq_msgsize);

		if((recvlen = mq_receive(mqfd, buf, attr_msg.mq_msgsize, &prio)) == -1)
			err_sys("mq_receive error");

		printf("接收到数据 : %d\n", prio);
		fflush(stdout);
		write(STDOUT_FILENO, buf, recvlen);
		exit(0);	
	}

	// 父进程
	// 打开消息
	if((mqfd = mq_open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR, NULL)) == -1)
		err_sys("mq_open error");

	if(mq_getattr(mqfd, &mq_attr) == -1)
		err_sys("mq_getattr error");	

	// 返回最大的 消息队列数， 每个消息的最大长度
	printf("maxmsg = %d\nmsgsize = %d\n", mq_attr.mq_maxmsg, mq_attr.mq_msgsize);

	// 描述符 数据 长度 优先级
	if(mq_send(mqfd, "hello world\n", sizeof("hello world\n"), 2) == -1)
		err_sys("mq_send error");

	close(mqfd);

	wait(&state);
	mq_unlink(argv[1]);

	if(WIFEXITED(state))	printf("子进程退出 %d\n", WEXITSTATUS(state));
}
