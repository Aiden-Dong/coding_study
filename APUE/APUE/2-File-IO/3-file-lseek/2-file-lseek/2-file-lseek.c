#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd;
	const char *buf1 = "abcdefghij";
	const char *buf2 = "ABCDEFGHIJ";

	if((fd = creat("file.hole", 0640)) < 0)
	{
		printf("creat error : %s\n", strerror(errno));
		return 0;
	}	

	if(write(fd, buf1, strlen(buf1)) != strlen(buf1))
	{
		printf("write error : %s\n", strerror(errno));
		return 0;
	}

	if(lseek(fd, 100, SEEK_CUR) == -1)
	{
		printf("lseek error : %s\n", strerror(errno));
		return 0;
	}
/*
 *********************************************************************
 * #include <unistd.h>
 * off_t lseek(int fd, off_t offset, int whence);
 * whence:
 * 	SEEK_SET: 文件开始
 * 	SEEK_CUR: 当前位置
 * 	SEEK_END: 文件结尾：
 *********************************************************************
*/

	if(write(fd, buf2, strlen(buf2)) != strlen(buf2))
	{
		printf("write error : %s\n", strerror(errno));
		return 0;
	}

	return 0;
}
