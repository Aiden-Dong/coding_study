#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

static void sig_cld(int);

int main()
{
	pid_t pid;

	if(signal(SIGCLD, sig_cld) == SIG_ERR)
		err_sys("signal error");

	if((pid = fork()) <0)
		err_sys("fork error");
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	
	pause();

	return 0;
}

static void sig_cld(int signo)
{
	pid_t pid;
	int status;

	printf("SIGCLD recevied\n");

	if(signal(SIGCLD, sig_cld) == SIG_ERR)
		err_sys("signal error");

	if((pid = wait(&status)) < 0)
		err_sys("wait error");

	printf("pid = %d\n", pid);

}
