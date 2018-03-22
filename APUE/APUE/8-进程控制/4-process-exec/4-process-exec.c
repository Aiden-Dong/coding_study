#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
	pid_t pid;
	int fd;
	int len;
	char val[5];
	char buf[20];

	memset(val, 0, sizeof(val));
	

	fd = open("one", O_RDONLY);

	sprintf(val,"%d", fd);

	if (fd == -1)
	{
		printf("open error : %s\n", strerror(errno));
		exit(0);
	}

	pid = fork();

	fcntl(fd, F_SETFD, FD_CLOEXEC); // 设置此标志后 在调用 exec 函数后 已经打开 的文件描述符会被关闭

	if(pid == 0)
	{
		if(execl("show.out", val, NULL) == -1)		 // val 参数将在 argv[0]位值
		{
			printf("execl error %s \n", strerror(errno));
			exit(0);
		}
	}

	wait(NULL);

	return 0;	
}
