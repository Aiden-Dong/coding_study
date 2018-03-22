#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

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

void show_sigset(const char *msg, sigset_t *signo);

int main()
{
	sigset_t sigmask, sigoldmask, sigset;
	
	if(sigemptyset(&sigmask) == -1) // 初始化信号集
		err_sys("sigemptyset error");
	
	if(sigaddset(&sigmask, SIGUSR1) == -1) // 增加 SIGUSR1 信号到信号集
		err_sys("sigaddset error");	
	if(sigaddset(&sigmask, SIGUSR2) == -1)
		err_sys("sigaddset error");
	if(sigprocmask(SIG_BLOCK, &sigmask, &sigoldmask) == -1) // 设置信号的阻塞
		err_sys("sigprocmask error");

	sleep(15); // 设置等待

	if(sigpending(&sigset) == -1)
		err_sys("sigpending error");

	show_sigset("当前的阻塞信号", &sigset);

	return 0;
}


void show_sigset(const char *msg, sigset_t *signo)
{

	printf("%s", msg);

	if(sigismember(signo, SIGQUIT))
		printf("SIGQUIT ");
	if(sigismember(signo, SIGABRT))
		printf("SIGABRT ");
	if(sigismember(signo, SIGKILL))
		printf("SIGKILL ");
	if(sigismember(signo, SIGCONT))
		printf("SIGCONT ");
	if(sigismember(signo, SIGSTOP))
		printf("SIGSTOP ");
	if(sigismember(signo, SIGCHLD))
		printf("SIGCHLD ");
	if(sigismember(signo, SIGALRM))
		printf("SIGALRM ");
	if(sigismember(signo, SIGUSR1))
		printf("SIGUSR1 ");
	if(sigismember(signo, SIGUSR2))
		printf("SIGUSR2 ");

	printf("\n");
}
