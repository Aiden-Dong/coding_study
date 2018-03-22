#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// 内联函数
inline void syserr(char *err)
{
	printf("%s : %s\n", err, strerror(errno));
	exit (0);	
} 

int main(int argc, char *argv[])
{
	int fd;
	int fd1;

	if((fd = open(argv[1], O_RDONLY)) == -1)
		syserr("open error ");

	printf("fd : %d\n",fd);
	
	fd1 = dup(fd); 
	// 复制文件描述符
	// 共享一个文件表: 文件状态，当前文件偏移量，i结点指针
	
	printf("fd : %d\n", fd1);
	
	return 0;
}
