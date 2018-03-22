#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "mysig.h"

void show_sigset(const char *msg, sigset_t signo)
{

	puts(msg);

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
}
