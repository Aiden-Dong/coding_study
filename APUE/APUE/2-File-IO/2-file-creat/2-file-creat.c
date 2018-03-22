#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd ; // 文件描述符
	char buf[50];
	int nline;
	
	if(argc == 1)
	{
		puts("please input parameter");
		return 0;
	}

	if((fd = creat(argv[1], 0640)) < 0)
	{
		fprintf(stderr, "creat error : %s\n", strerror(errno));
		return 0 ;
	}	
/*
 * ***********************************************************************************
 * #include <fcntl.h>
 *
 * int creat(const char * path, mode_t mode);
 *
 * 等效 ： open(path, O_WRONLY|O_CREAT|O_TRUNC, mode);
 *
 * 成功--返回为只写方式打开的文件描述符
 * 失败--返回-1
 * **********************************************************************************
*/
	do
	{
		memset(buf, 0, sizeof(buf));
		if((nline = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
		{
			fprintf(stderr, "read error : %s\n", strerror(errno));
			return 0;
		}	

		if(write(fd, buf, nline) != nline)
		{
			fprintf(stderr, "write error : %s\n", strerror(errno));
			return 0;
		}

		if(buf[nline - 1] == '\n')
			buf[nline - 1] = 0;

	}while(strcmp(buf, "end"));
	
	close(fd);

	return 0;
}
