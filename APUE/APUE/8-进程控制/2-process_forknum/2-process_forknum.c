#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int i ;

	for(i = 0 ; i < 4 ; i++)
	{
		pid = fork();
		if(pid == 0)
			printf("%d , pid = %d, ppid = %d\n",i, getpid(), getppid());
	}
	while(1);

	return 0;
}
