#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline void err_qut(char *buf)
{
	puts(buf);
	exit (0);
}
inline void err_sys(char *buf)
{
	printf("%s : %s\n", buf, strerror(errno));
	exit (0);
}

int main(int argc, char *argv[])
{
	int val;

	if(argc != 2)
		err_qut("please input a parameter....");

	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1)
		err_sys("fcntl error");

	switch(val & O_ACCMODE)
	{
	case O_RDONLY:
		printf("read only\n");
		break;
	case O_WRONLY:
		printf("write only\n");
		break;
	case O_RDWR:
		printf("read write\n");
		break;
	default:
		printf("unknow access mode\n");
	}
	
	if(val & O_APPEND)
		printf("append\n");
	if(val & O_NONBLOCK)
		printf("nonblocking\n");
	if(val & O_SYNC)
		printf("sysnc");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if(val & O_FSYNC)
		printf("synchronous writes\n");
#endif

	return 0;
}
