#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	char str[20];
	long name_max;
	
	if (argc == 1)
	{
		puts("please input a paramer");
		return 0;
	}
	fprintf(stdout, "errno = %d\n", errno);
	
	/*
 * 		注意 STDOUT_FILENO 与 stdout 的区别 :
 * 			STDOUT_FILENO : 用文件描述符表示 类型为： int
 * 			stdout : 用的是 FILE * 的指针类型
 	*/

	// 以只读方式打开文件 ， 出错是 error 会被重置
/*
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		printf("open error : %s\n", strerror(errno));
		return 0;
	}

	printf("%s : %d\n", argv[1], fd);

	printf("NAME_MAX = %d\n", fpathconf(fd, _PC_NAME_MAX));
	printf("_POSIX_NO_TRUNC = %d\n",fpathconf(fd, _POSIX_NO_TRUNC));
	printf("文件超出长度的错误表示: %s \n",strerror(ENAMETOOLONG));

	// _PC_NAME_MAX 用于限制文件的最大长度
	// _POSIX_NO_TRUNC 路径长于_PC_NAME_MAX 时候 截断/出错 (当返回值为 -1 则截断 ，否则设置 errno 错误: ENAMETOOLONG)
			
	close(STDOUT_FILENO);
	// 关闭标准输出流------STDOUT_FILENO = 1
	printf ("hello world\n");
	// 由于标准输出流被关闭， 所以 hello world 无法显示出来
	close(fd);
	fd=open(argv[1], O_WRONLY|O_APPEND);
	// 文件被重新打开 ， 新的文件描述符为 -- 1
	 
	memset(str, 0, sizeof(str));
	sprintf(str, "%s : %d\n", argv[1], fd);
	write(fd,str, strlen(str));
	memset(str, 0, sizeof(str));
	sprintf(str, "STDOUT_FILENO = %d\n",STDOUT_FILENO);
	write(fd, str, strlen(str));	

	close(fd);
*/	
	fd = open(argv[1], O_WRONLY|O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG);
	return 0;
}
