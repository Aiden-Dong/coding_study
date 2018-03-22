#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void sig_int(int);

int main()
{
	char buf[1024];
	pid_t pid;
	int status;

	if(signal(SIGINT, sig_int) == SIG_ERR)
	{
		puts("signal error");
		exit(0);
	}

	printf("%% ");
	memset(buf, 0, sizeof(buf));
	while(fgets(buf, 1024, stdin) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
	
		if((pid = fork()) < 0 )
		{
			puts("fork error");
			exit(0);
		}
		else if (pid == 0)
		{
			execlp(buf, buf, (char *)0);
			printf("couldn't execute : %s", buf);
			exit(0);
		}
		memset(buf, 0, sizeof(buf));
	}
	
	if((pid = waitpid(pid, &status, 0)) < 0)
	{
		puts("waitpid error !!");
		exit (0);
	}

	return 0;
}

void sig_int(int signal)
{
	printf("interrupt\n%% ");
}
