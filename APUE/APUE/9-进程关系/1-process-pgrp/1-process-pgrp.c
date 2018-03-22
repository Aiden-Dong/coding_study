#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

void show_msg();

int main()
{
	show_msg();
	sleep(10);

	return 0;
}

void show_msg()
{
	puts("user message :");
	printf("my uid : %d\n", getuid());
	printf("my effiective uid : %d\n", geteuid());
	printf("my gid : %d\n", getgid());
	puts("process message:");
	printf("my pid : %d\n", getpid());
	printf("my parent pid : %d\n", getppid());
	printf("my process group ID : %d\n", getpgrp());
	printf("this terminal session ID : %d\n", getsid(0));
	
}
