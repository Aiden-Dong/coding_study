#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define FIFO_NAME "./fifo_one"

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

int main()
{
	int fd ;
	int pid;
	int len;
	char buf[20];

	mkfifo(FIFO_NAME, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
	
	if((pid = fork()) == -1)
		err_sys("fork error");
	else if(pid == 0)	// 子进程
	{
		fd = open(FIFO_NAME, O_RDONLY);
				
		len = read(fd, buf, sizeof(buf));

		write(STDOUT_FILENO,buf, len);
		
		return 0;
	}

	fd = open(FIFO_NAME, O_WRONLY);
	
	if(write(fd, "hello world\n", sizeof("hello world\n")) == -1)
		err_sys("write error");
		
	return 0;
}
