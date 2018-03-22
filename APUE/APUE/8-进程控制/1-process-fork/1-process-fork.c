#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}
inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}
int main()
{
	pid_t pid;
	int status;
	char buf[20];
/*
	if((pid = fork()) == -1)
		err_sys("fork error");

	if(pid == 0)
	{
		while(1)
		{
			puts("child process to get data:");
			fgets(buf, 20, stdin);
			printf("子进程已经接受到数据 :%s\n", buf);	
		}
	}
	else
	{
		while(1)
		{
			puts("parent process to get data:");
			fgets(buf, 20, stdin);
			printf("父进程已经接受到数据: %s\n", buf);
		}
	}
*/

	if((pid = fork()) == -1) 
		err_sys("fork error");

/*
 * ****************************************************
 * 	pid_t fork();
 * 	
 * 	返回：
 * 		父进程返回 子进程的 pid
 * 		子进程返回----------- 0
 * 		出错返回 ----------- -1
 *
 * 	说明: 
 * 		父进程和子进程并不共享存储空间部分， 父进程和子进程共享正文段
 *
 * ****************************************************
*/	printf("进程ID   	: %d\n", getpid());
	printf("父进程ID 	: %d\n", getppid());
	printf("进程的组ID	: %d\n", getgid());
	printf("进程的有效组ID	: %d\n", getegid());
	printf("进程实际用户ID	: %d\n", getuid());
	if(pid == 0) // 子进程
	{
		printf("my pid = %d\n", getpid()); 	   //获得自己的pid
		printf("my parent pid = %d\n", getppid()); // 获得父进程的pid
			
		if ((status = system("ps -u saligia -o pid,ppid,sid,comm | grep 1-")) == -1)
			err_sys("system error");
		else if (WEXITSTATUS(status) == 127)	// 判断是不是exec 失败
			err_que("system error exec");
		/*
 		****************************************************************************
		*	int system(const char *cmdstring);
		* -------------------------------------------------------------------------
		*  返回：
		*  	1） 如果是 fork 失败， 则返回 -1；
		*  	2)  如果是wait 失败， 则返回 -1；
		*  	3） 如果是exit失败，  则返回值如同执行 exit(127)
		*
		****************************************************************************
  		*/

		sleep(20);	

		// 如果子进程成为孤儿进程会被init 进程收养 : ppid == 1
		// 如果子进程成为僵死进程,资源需要等到父进程运行结束后才被收回

		exit(0);
	}

	// 父进程段
	
	waitpid(pid, NULL, 0);

	printf("my pid = %d\n",  getpid());
	printf("my parent pid = %d\n", getppid());

	// 一般来说父进程的父进程是 bash 进程
	// 父进程与子进程所在的 会话ID 为 bash ID

	
	return 0;
}
