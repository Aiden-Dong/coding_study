#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void show_fcntl(int fd);

int set_fcntl(int fd);

int main()
{
	int fd1, fd2, fd3;
	int val;
	char buf[20];
	int n;

	// 使用两个open 打开两个文件描述符后，各自独享文件自己的文件偏移量
	fd1 = open("./one", O_RDONLY);
	fd2 = open("./one", O_RDONLY);
	
	puts("fd1 ...........");
	while(n = read(fd1, buf, sizeof(buf)))
		write(STDOUT_FILENO, buf, n);
	puts("fd2 ...........");
	while(n = read(fd2, buf, sizeof(buf)))
		write(STDOUT_FILENO, buf, n);
	
	fd3 = dup(fd2);

	// 使用dup 复制的文件描述符
	puts("fd3 ...........");
	while(n = read(fd3, buf, sizeof(buf)))
		write(STDOUT_FILENO, buf, n);

	show_fcntl(fd2);
	if (set_fcntl(fd3) == -1)
		printf("F_SETFL error\n");
	show_fcntl(fd3);

	return 0;
}

void show_fcntl(int fd)
{
	int val = fcntl(fd, F_GETFL);
	
	switch(val & O_ACCMODE)
	{
	case O_RDONLY:
		puts("this file is only read");
		break;
	case O_WRONLY:
		puts("this file is only write");
		break;
	case O_RDWR:
		puts("this file is read and write");
		break;
	default:
		puts("sorry .....");
	}

	if(val & O_APPEND)	//追加模式
		puts("this file can append");
	if(val & O_NONBLOCK)	// 无阻塞模式
		puts("this file is not nblock");
	if(val & O_SYNC)	
		puts("this file is can sync");
}

int set_fcntl(int fd)
{
	int val;

	if((val = fcntl(fd, F_GETFL)) == -1)
		err_sys("fcntl error");

	val |= O_APPEND;
	
	if(fcntl(fd, F_SETFL, val) == -1)
		return -1;
	return 0;
}
