#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd;
	char buf[20];
	int len ;

	fd = atoi(argv[0]);	// 获取文件描述符

	while((len = read(fd, buf, sizeof(buf))) != 0)
	{
		if(len == -1)
		{
			printf("%s : %s\n", "read error", strerror(errno));
			exit(0);
		}

		write(STDOUT_FILENO, buf, len);
	}

	return 0;
}
