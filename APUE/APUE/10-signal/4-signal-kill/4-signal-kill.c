#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/***************全局变量区*****************/

pid_t pid;
int status;
/*************内连函数区**************/

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

/******************* 调用函数区 ********/
void show_status(int status);

void sig_alrm1(int signo);
void sig_alrm2(int signo);
void sig_child(int signo);

int main()
{

	if((pid = fork()) < 0)
		err_sys("fork error");

	if(pid == 0)	// 子进程
	{
		while(1)
		{
			puts("子进程");
			sleep(1);
			puts("continue..");
			sleep(1);
		}
	}

	if(signal(SIGCHLD, sig_child) == SIG_ERR) // 设置子进程信号的捕捉动作
		err_sys("signal error");
	// 可以捕获任何子进程状态发生变化的信号		
	if(signal(SIGALRM, sig_alrm1) == SIG_ERR) // 设置时钟信号的捕捉动作
		err_sys("signal error");
	alarm(3);	// 设置时钟信号
	while(1)
		pause();

/*
	while(waitpid(pid, &status, WUNTRACED|WCONTINUED) != -1)
		show_status(status);
	// WUTRACED   : 获得子进程的暂停信号 ------------------- WIFSTOPPED(status)
	// WCONTINUED : 获得子进程的暂停后继续运行的信号-------- WIFCONTINUED(status)

*/	
	return 0;
}

void sig_alrm1(int signo)
{
	puts("父进程向子进程发送停止信号 :");
	kill(0, SIGKILL);

	if(signal(SIGALRM, sig_alrm2) == SIG_ERR) // 重设 SIGALRM 的信号处理动作
		err_sys("signal error");
	alarm(3);		    // 重置 计时器 
}

void sig_alrm2(int signo)
{
	puts("父进程向子进程发送继续信号 :");
	kill(pid, SIGCONT);

	if(signal(SIGALRM, SIG_DFL) == SIG_ERR) // 恢复信号的默认设置
		err_sys("signal error");

	alarm(0);	          // 撤销闹钟 
}

void sig_child(int signo)
{
	if(waitpid(pid, &status, WCONTINUED | WUNTRACED) == -1)
		err_sys("waitpid error");

	// 显示子进程的状态详情
	
	show_status(status);
}
void show_status(int status)
{
	if(WIFEXITED(status))
	{
		printf("子进程正常终止 : %d\n", WEXITSTATUS(status));
		exit(0);
	}
	else if(WIFSIGNALED(status))
	{
		printf("子进程异常终止 : %d\n", WTERMSIG(status));
		exit(0);
	}
	else if(WIFSTOPPED(status)) 
		printf("子进程暂停 : %d\n", WSTOPSIG(status));
	// 当子进程接受到 SIGSTOP 信号 WIFSTOPP(status) 为真

	else if(WIFCONTINUED(status))
		printf("暂停的子进程已经继续运行\n");
	// 当暂停的子进程接受到 SIGCONT 信号时， WIFCONTINUED(status) 为真
}
