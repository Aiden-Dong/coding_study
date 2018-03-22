#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

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
	char buf[10];
	int n;

	int fd = open("one", O_RDONLY);

	while(1)
	{
		memset(buf, 0, sizeof(buf));
		if((n = read(fd, buf, sizeof(buf))) < 0)
			err_sys("read error");
		if(n == 0)
			break;
		
		// read 无缓冲区 在读到 终止符 换行符 读满缓冲区 后就返回 

		if(write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
		printf("-------- %d\n",n);				
	}

	// fread 属于全缓冲, 在读取满缓冲区前不返回
/*
	while(fread(buf, sizeof(buf), 1, stdin))
	{
		printf("%s\n", buf);
	}
*/;

	return 0;
}
