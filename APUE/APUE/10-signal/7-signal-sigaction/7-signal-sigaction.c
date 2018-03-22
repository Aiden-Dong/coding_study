#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void Sigfunc (int);

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

struct sigaction* my_sigaction(int signo, Sigfunc);

void sig_print(int sig);

int main()
{
	int len;
	char buf[20];

	my_sigaction(SIGUSR1, sig_print);
	
	while(len = read(STDIN_FILENO, buf, sizeof(buf)))
	{
		if(len == -1)
			err_sys("read error");
		if(write(STDOUT_FILENO, buf, len) == -1)
			err_sys("write error");
	}

	return 0;
}

struct sigaction* my_sigaction(int signo, Sigfunc func)
{
	static struct sigaction act, oact;

	sigemptyset(&act.sa_mask);	// 清空屏蔽字
	act.sa_flags = SA_INTERRUPT;	// 设置系统调用的终端模式
	act.sa_handler = func;		// 设置信号的处理方式
	
	if (sigaction(signo, &act, &oact) == -1)
		return NULL;

	return &oact;
}

void sig_print(int sig)
{
	printf("SIGUSR1 doing .....\n");
}
