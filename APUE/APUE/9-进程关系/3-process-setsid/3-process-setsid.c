#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char *msg)
{
	printf("%s : %s \n", msg, strerror(errno));
	exit(0);
}

void signo(int sig);

int main()
{
	int pid;
	char buf[20];
	int len;

	signal(SIGCHLD, signo);
	signal(SIGTTOU, signo);
	signal(SIGTTIN, signo);

	if((pid = fork()) == -1)
		err_sys("fork error");

	else if(pid == 0)// 子进程
	{
	
		// 显示进程的一般信息

		printf("my pid : %d\n", getpid());
		printf("my ppid : %d\n", getppid());
		printf("my sid : %d\n", getsid(0));
		printf("the front is  : %d\n", tcgetpgrp(STDOUT_FILENO));
		printf("the front sid : %d\n", tcgetsid(STDOUT_FILENO));

		// 建立一个新的会话 
		// 必须不是一个进程的进程组的组长， 建立成功后不分配控制终端
		// 建立新会话后，该进程成为新进程组的组长进程，并且成为新会话的会话首进程
		setsid();
	//	open("dev/tty", O_RDWR);

		// 向前台终端发送消息
		fgets(buf, 20, stdin);
		fputs(buf, stdout);
	//	sleep(15);

		exit(0);
	}
	// 父进程 退出
	while(1)
		pause();
	
	return 0;
}

void signo(int sig)
{
	int status;

	if(sig == SIGCHLD)
	{
		waitpid(-1, &status, WCONTINUED | WUNTRACED | WNOHANG);
	
		if(WIFEXITED(status))
		{
			printf("子进程正常终止 : %d\n", WEXITSTATUS(status));
			exit(0);
		}
		else if(WIFSIGNALED(status))
		{
			printf("子进程接受到信号终止 : %d\n",WTERMSIG(status));
			exit(0);
		}
		else if(WIFSTOPPED(status))
			printf("子进程已经暂停 : \n", WSTOPSIG(status));
		else if(WIFCONTINUED(status))
			printf("子进程暂停后已经继续 ....\n");
	}
	else if(sig == SIGTTOU)	// 写控制终端
	{
		printf("%d 尝试写控制终端\n", getpid());
	}
	else if(sig == SIGTTIN)
	{
		printf("%d 尝试读控制终端\n", getpid());
	}
}
