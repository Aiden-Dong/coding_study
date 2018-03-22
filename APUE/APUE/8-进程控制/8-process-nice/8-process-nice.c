#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

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

void show_status(int);

int main()
{
	const int NZERO = sysconf(_SC_NZERO); 
	int my_nice;
	pid_t pid ;
	int status;

	printf("进程的最低优先级为 : %d\n", 2*NZERO-1);

	

	if ((pid = fork()) < 0)
		err_que("fork error");
	else if(pid == 0)	// 子进程
	{
		setpriority(PRIO_USER, 0, 0); // 设置用户的优先级
		/*
 		******************************************************************
 		*	设置进程优先级：
 		*		nice 的值越小, 进程的优先级越高
 		*		MAX(nice) = NZERO;
 		*******************************************************************
 		*/
		printf("child process nice = %d\n", getpriority(PRIO_PROCESS, 0));
		exit(0);
	}

	/*
 	******************************************************************************
	*
	*	int getpriority(int whitch, id_t who);
	*	----------------------------------------------------------------------
	*	which:
	*		PRIO_PROCESS : 进程 | PRIO_PGRP : 进程组 | PRIO_USER : 用户ID
	*	who :
	*		who 参数选择感兴趣的一个或多个进程， 如果who 参数是0表示调用进
	*		程, 进程组,或用户组
	*
 	******************************************************************************
 	*/

	waitpid(pid,&status, 0);
	show_status(status);

	printf("this process's nice = %d\n",getpriority(PRIO_USER, 0)); // 获得用户的优先级
	
	return 0;
}

void show_status(int status)
{
	if(WIFEXITED(status))
		printf("子进程已经正常终止 : %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("子进程异常终止 : %d\n", WTERMSIG(status));
	else if(WIFCONTINUED(status))
		printf("子进程暂停后已经继续运行\n");
	else if(WIFSTOPPED(status))
		printf("子进程已经暂停\n", WSTOPSIG(status));

}
