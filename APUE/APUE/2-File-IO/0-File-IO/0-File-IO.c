#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

inline void err_que(const char * msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char * msg)
{
	printf("%s : %s\n",msg,strerror(errno));
	exit(0);
}

int main(int argc, char *argv[])
{
	int fd;		// 文件描述符 
	FILE *fp;	// 文件流
	char buf[20];	// 缓冲区
	int nline;	// 记录读取的字节的长度
	off_t offset;	// 标记文件读取位置
	int status;
	
	if(argc != 2)
		err_que("please input lparameter ...");

	if((fd = open(argv[1], O_RDONLY)) == -1)
		err_sys("open error");
	
	fp = fdopen(fd, "r");
	// 将文件描述符用文件流表示
	
	memset(buf, 0, sizeof(buf));

	errno = 0;

// ============================显示文件的内容========================

	while((nline = read(fd, buf, sizeof(buf))) != 0 && errno == 0 )
	{
		if(write(STDOUT_FILENO, buf, nline) == -1)
			break;
		memset(buf, 0, sizeof(buf));
	}

// ===================	获取文件的描述标志=========================
	
	status = fcntl(fd, F_GETFL);

	switch(O_ACCMODE & status)
	{
	case O_RDONLY:
		printf("%s is read_only\n",argv[1]);
		break;
	case O_WRONLY:
		printf("%s is write_only\n",argv[1]);
		break;
	case O_RDWR:
		printf("%s is read_write\n",argv[1]);
		break;
	default:
		printf("sorry....\n");
	}

// =======================  指定显示文件的内容======================

	while(printf("please input stdress :\n") && scanf("%d",&offset))
	{
		memset(buf, 0, sizeof(buf));

		if(offset == 0)
			break;
		printf("num = %d : \n", offset);

		lseek(fd, offset, SEEK_SET);

		if(fgets(buf, sizeof(buf), fp) == NULL)
			err_sys("read error");
		fputs(buf,stdout);
	}

	if(errno != 0)
		err_sys("error");
	
	return 0;
}
