#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd;
	int len;
	struct stat my_stat;
	char buf[10];
/*
	fd = open("one", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG);	// 以读写， 创建， 跟截断模式打开文件
	
	while(len = read(STDIN_FILENO, buf, sizeof(buf)))
	{
		write(fd, buf, len);
		lseek(fd, 10, SEEK_END);
	}

	fsync(fd);	// 同步写回磁盘

	close(fd);
*/
	fd = open("one", O_RDONLY| O_DSYNC);
	fstat(fd, &my_stat);
	printf("文件大小 : %d\n", my_stat.st_size);
	while(len = read(fd, buf, sizeof(buf)))
	{
		write(STDOUT_FILENO, buf, len);
		fflush(stdout);
		printf("已经读取 %d 字节", len);
		fflush(stdout);
	}

	close(fd);

	truncate("one", 100);

	return 0;
}
