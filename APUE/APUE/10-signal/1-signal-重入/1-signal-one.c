#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

static void my_alarm(int signo)
{
	struct passwd *rootptr;


	signal(SIGALRM, my_alarm);	
	printf("in signal handler\n");

	
	// 程序在此产生了不可重入问题
	if((rootptr = getpwnam("saligia")) == NULL)
		err_sys("getpwnam error");

	printf("one\n");

	alarm (1);
}

int main()
{	
	struct passwd *ptr;
	int i= 0;

	signal(SIGALRM, my_alarm); // 信号设置

	alarm (1);

	for(;;)
	{
		
		printf("%d\n",i++);

		if(errno != 0)
			err_sys("error");

		if((ptr = getpwnam("saligia")) == NULL)
			err_sys("getpwnam error");

		if(strcmp(ptr->pw_name, "saligia") != 0)
			printf("return value corrupted !, pw_name = %s\n", ptr->pw_name);
	}

	return 0;
}
