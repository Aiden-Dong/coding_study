#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void (*Sigturn)(int);

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

void abort_sig(int signo);
void alrm_sig(int signo);
Sigturn sig_func(int signo, Sigturn func);

int main()
{


	sig_func(SIGABRT, abort_sig);	// 设置abort 的信号动作
	sig_func(SIGALRM, alrm_sig);	// 设置alrm 的信号动作

	alarm(3);
	
	while(1)
	{
		printf("hello world\n");
		sleep(1);
		printf("hold on\n");
		sleep(1);
	
	}	

	return 0;
}

void abort_sig(int signo)
{
	puts("SIGABRT is opening....");

}
void alrm_sig(int signo)
{
	puts("alarm opening and open abort");
	abort();
	puts("end opening abort");
}
Sigturn sig_func(int signo, Sigturn func)
{	
	static struct sigaction act, oact;

	act.sa_handler = func;
	
	sigemptyset(&act.sa_mask);	// 清空信号屏蔽集
	act.sa_flags = SA_RESTART;	// 设置中断的系统调用为自动重启

	sigaction(signo, &act, &oact);

	
	return oact.sa_handler;
}
