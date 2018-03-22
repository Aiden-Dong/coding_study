#include <syslog.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>		//sigaction(); 
#include <unistd.h>   		// fork();
#include <sys/stat.h> 		// umask(0);
#include <sys/resource.h>	// getrlimit()

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

void daemonize(const char *cmd);

int main()
{
	daemonize("daemon");
	while(1);
	return 0;
}

void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;

	// 清空文件屏蔽
	umask(0);
	
	// 获得能打开的最大文件描述符
	if(getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_sys("can not get file limit");

	// 调用fork 父进程exit
	if((pid = fork()) == -1)
		err_sys("fork error");

	else if(pid != 0) // 父进程
		exit(0);	

	// 创建会话组 
	// 成为新会话的会话首进程
	// 成为会话组的组长
	setsid(); 

	sa.sa_handler = SIG_IGN; 
	sigemptyset(&sa.sa_mask); // 清空屏蔽字
	sa.sa_flags = 0;	  
	
	if(sigaction(SIGHUP, &sa, NULL) < 0) // 设置忽略 SIGHUP 信号
		err_sys("sigaction error"); 

	// 使得守护进程不会成为会话首进程
	if((pid = fork()) == -1)
		err_sys("fork error");
	else if(pid != 0)
		exit(0);

	// 改变当前工作目录
	if (chdir("/") < 0)
		err_sys("chdir error");
	for(i = 0; i < rl.rlim_max; i++)
		close(i);
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	// 初始化日志文件
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if(fd0 != 0 || fd1 != 1 || fd2 != 2) // 说明有标准输入输出没有被关闭
	{
		syslog(LOG_ERR, "unexpected, file descritors %d %d %d", fd0, fd1, fd2);
		exit(1);
	}
}
