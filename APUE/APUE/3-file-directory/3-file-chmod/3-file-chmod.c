#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

inline void err_que(char *msg)
{
	puts(msg);
	exit(0);
}
inline void err_sys(char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main(int argc, char *argv[])
{
	int fd;

	if(argc != 2)
		err_que("please input a parameter");

	if((fd = open(argv[1], O_RDONLY)) == -1)
		err_sys("open error");

	// 设置文件创建屏蔽字

	if(chmod(argv[1], S_IRUSR | S_IWUSR | S_IRGRP|S_IWGRP) == -1)
		err_sys("chmod error");
	
	return 0;
}
