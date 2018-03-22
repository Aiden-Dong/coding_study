#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

void signo(int sig);

int main()
{
	int pid;
	int len;
	char buf[20];

	signal(SIGCHLD, signo);

	if((pid = fork()) == -1)
		err_sys("fork error");
	
	else if(pid == 0) 
	// 子进程 ----------------当前的后台进程组
	{
	
		setpgid(getpid(), getpid());	
		// 将子进程加入到一个新的进程组使其自身为组长进程
		printf("子进程开始\n");
		// 与前台通话
		
		while(len = read(STDIN_FILENO, buf, sizeof(buf)))
		{	
			if(len == -1)
				err_sys("read error");
			if(write(STDOUT_FILENO, buf, len) == -1)
				err_sys("write error");
		}/*
		while(1)
		{
			sleep(1);
			write(STDOUT_FILENO, "hello world\n", sizeof("hello world"));
		}*/

		exit(0);
	}

	sleep(2);	// 首先让子进程拥有独立的进程组
	printf("my pid : %d\n", getpid());
	// 父进程 ------------ 当前的前台进程组
	printf("the sid : %d\n", tcgetpgrp(STDOUT_FILENO));	
	// 获取当前前台进程组
	//tcsetpgrp(STDOUT_FILENO, pid);
	// 设置子进程的进程组为前台进程组
	printf("the sid : %d\n", tcgetpgrp(STDOUT_FILENO));
	printf("the sid of process group pid : %d\n", tcgetsid(STDOUT_FILENO));
	
	while(1)
		pause();
	// 父进程在子进程之前结束
	// 子进程成为孤儿进程						
	

	return 0;
}

void signo(int sig)
{
	int status;

	waitpid(-1, &status, WCONTINUED | WNOHANG | WUNTRACED);
	
	if(WIFEXITED(status))
	{
		printf("子进程已经正常终止 : %d\n", WEXITSTATUS(status));
		exit(0);
	}
	else if(WIFSIGNALED(status))
	{
		printf("子进程接受到信号终止 : %d\n", WTERMSIG(status));
		exit(0);
	}
	else if(WIFSTOPPED(status))
		printf("子进程已经暂停 : %d\n", WSTOPSIG(status));
	else if(WIFCONTINUED(status))
		printf("子进程已经继续运行 : %d\n");
	else 
		printf("不能确定的 子进程返回状态\n");
}
