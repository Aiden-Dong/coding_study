#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
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

void sig_alrm(int signo);

int main()
{
	FILE *fp;
	char buf[5];
	int len;

	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal error");
	// 设置 SIGALRM 的信号动作
	
	printf("signal size : %d\n", sizeof(SIGALRM));
	alarm(3);
	printf("hello");
	while(fread(buf, sizeof(buf), 1, stdin) > 0)
		fwrite(buf, strlen(buf), 1, stdout);
	// 行缓冲器
/*
	while((len = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
	{
		if(write(STDOUT_FILENO, buf, len) != len)
			err_sys("write error");
	}
*/

	if(errno != 0)
		err_sys("read error");
		
	
	return 0;
}

void sig_alrm(int signo)
{
	printf("time over...\n");
	
	alarm(1);
	// 防止出现对每次信号进行处理时， 信号动作的重置默认值的现象
}
