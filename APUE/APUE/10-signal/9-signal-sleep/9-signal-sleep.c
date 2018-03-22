#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef void (*Resign)(int);

extern const char *const sys_siglist[_NSIG];

inline void err_que(const char *msg)
{	
	puts(msg);

	exit(0);
}
inline void err_sys(const char *msg)
{
	printf("%s : %s", msg, strerror);

	exit(0);
}

void show_sig(sigset_t sig);

int main()
{
	sigset_t sig;
	show_sig(sig);	
	return 0;
}

void show_sig(sigset_t sig)
{
	int i;

	for(i = 1; i < 30; i++)
		puts(sys_siglist[i]);

}
