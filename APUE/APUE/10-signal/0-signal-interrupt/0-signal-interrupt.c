#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

void sigalrm(int signo);

int main()
{
	char buf[20];
	int len;
	signal(SIGALRM, sigalrm);

	alarm(2);

	memset(buf, 0, sizeof(buf));

	while((len = fread(buf, sizeof(buf), 1, stdin)))
	{
		if(len != 1)
			err_sys("read error");

		if(fwrite(buf, strlen(buf), 1, stdout) != 1)
			err_sys("write error");

		memset(buf, 0, sizeof(buf));
	}	

	return 0;
}

void sigalrm(int signo)
{	
	printf("alrm opening .....\n");
}
