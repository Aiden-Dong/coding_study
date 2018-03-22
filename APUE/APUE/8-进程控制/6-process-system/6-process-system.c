#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
int system(const char *cmdstring);

int main()
{
	int status;

	if((status = system("date")) < 0)
		err_sys("date error");
	if((status = system("who; exit 44")) < 0)
		err_sys("who error");

	return 0;
}

int system(const char *cmdstring)
{
	pid_t pid;
	int status;
	
	if(cmdstring == NULL)
		return 1;
	if((pid = fork()) == -1)
		status = -1;
	else if(pid == 0)
	{
		execl("/bin/sh", "sh", "-c", cmdstring, NULL);
		_exit(127);
	}
	else 
	{
		while(waitpid(pid, &status, 0) == -1)
		{
			if(errno != EINTR)
			{
				status = -1;
				break;
			}
		}
			
	}

	return status;
}
