#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
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

	memset(buf, 1, 10);
	printf("%d--%d--%d--%d--%d--%d\n", 
		sizeof(int), sizeof(float), sizeof(double), sizeof(long), sizeof(char), sizeof(long long));
	scanf("%5s", buf);// 将只读取5个字符到缓冲区中
	write(STDOUT_FILENO, buf, 10);
	printf("\n");
	printf("%s\n", buf);
	printf("--%07.3d--\n",12);

	return 0;
}
