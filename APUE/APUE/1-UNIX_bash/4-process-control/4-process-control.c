#include <stdio.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main ()
{
	char buf[2048];
	int status;
	pid_t pid;

	printf("%% ");
	memset(buf, 0, sizeof(buf));

	while(fgets(buf,2048,stdin) != NULL)
	{
		if (buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = 0;
		if((pid = fork()) < 0)
		{
			puts("fork error");
			exit(0);
		}
		else if(pid == 0) // 子进程
		{
			execlp(buf, buf, (char *)0);
			printf("couldn't execute: %s", buf);
			exit(127);
		}
		memset(buf, 0 , sizeof(buf));
	}
	if ((pid = waitpid(pid, &status, 0)) < 0)
	{
		puts("waitpid error");
		exit(0);
	}

	printf("%% ");

	return 0;	
}
