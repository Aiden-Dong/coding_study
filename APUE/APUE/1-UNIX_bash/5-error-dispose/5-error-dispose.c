#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	fprintf(stderr,"EACCES: %s\n",strerror(EACCES)); // string.h
	// 将error的值映射为一条错误消息
	errno = ENOENT;
	perror(argv[0]);				// stdio.h
	// 基于erro 的当前值， 在标准错误上产生一条错误信息
	return 0;
}
