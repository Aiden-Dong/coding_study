#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

void signo(int pid);
void show_sig(int sig)
{
	printf("子进程接受到信号 SIGTERM \n");
}

int main()
{
	int pid;
	
	signal(SIGCHLD, signo);			// 获取子进程发送来的信号

	if((pid = fork()) == -1)		// 创建一个新的进程
		err_sys("fork error");

	else if(pid == 0)			// 子进程
	{
		signal(SIGTERM, show_sig);
		while(1)
		{
			printf("++++++++++\n");
			sleep(1);
			printf("===========\n");
			sleep(1);
		}
	}

	while(1)
	{
			pause();			// 等待接受来自子进程的信号
	}
	// 父进程	
	return 0;
}
void signo(int sig)
{
	int status;
	int pid;

	pid = waitpid(-1, &status, WCONTINUED | WNOHANG|WUNTRACED);
	// 获取子进程的终止， 暂停， 继续状态（在无阻塞的环境下） 
	// 信号捕获
	printf("接受到来自子进程的消息通知： %d\n", pid);
	
	if(WIFEXITED(status))
	{
		printf("子进程已经正常终止 : %d\n", WEXITSTATUS(status));
		exit(0);
	}
	else if(WIFSIGNALED(status))
	{
		printf("子进程受到一个信号 : %d\n", WTERMSIG(status));
		exit(0);
	}
	else if(WIFSTOPPED(status))
		printf("子进程已经暂停 : %d\n", WSTOPSIG(status));
	else if(WIFCONTINUED(status))
		printf("子进程停止后已经继续运行");
	else
		printf("接受到意外的子进程信号");
	
}
