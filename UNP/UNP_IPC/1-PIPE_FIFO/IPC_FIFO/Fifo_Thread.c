#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <sys/param.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define		CMD "/tmp"

void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}
void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

// 将文件名转换成fifo文件名
int path_make(const char *cmd, char *path);

// 执行读取管道中的数据并输出
void * put_fifo(void * path);

int main(int argc, char *argv[])
{
	char		fifo_path[PATH_MAX];
	pthread_t	tid1, tid2;
	int 		fifo_fd;
	int		i;

	path_make(CMD, fifo_path);

	if(mkfifo(fifo_path, 0666) == -1)
		err_sys("mkfifo error");

	printf("原子写入的大小 : %d\n" ,pathconf(fifo_path, _PC_PIPE_BUF));

	pthread_create(&tid1, NULL, put_fifo, (void *)fifo_path);
	pthread_create(&tid2, NULL, put_fifo, (void *)fifo_path);

	sleep(1);
	
	if((fifo_fd = open(fifo_path, O_WRONLY)) == -1)
		err_sys("open error");


	unlink(fifo_path);

	for(i = 0; i < 5; i++)
	{
		sleep(1);
		write(fifo_fd, "hello world", sizeof("hello world"));
	}

	close(fifo_fd);

	sleep(3);

	return 0;
}

int path_make(const char *cmd, char *path)
{
	time_t		time_now;
	struct tm	time_to_type;

	if(path == NULL)
		return 0;

	time_now = time(NULL);

	if(localtime_r(&time_now, &time_to_type) == NULL)
		err_sys("localtime error");	

	if(snprintf(path, PATH_MAX, "%s/%d-saligia.fifo", cmd, time_to_type.tm_yday) == -1)
		err_sys("snprintf error");

	return strlen(path);
}

void * put_fifo(void * path)
{
	pthread_t	tid;
	char		buf[100];
	int rd_fifo = open((char *)path, O_RDONLY);

	if(rd_fifo == -1)
		err_sys("open error");

	tid = pthread_self();
	pthread_detach(tid);
	printf("线程 : %u 启动\n", tid);

	memset(buf, 0, sizeof(buf));
	while(1)
	{
		int recv = read(rd_fifo, buf, sizeof(buf));
		if(recv == -1)
			err_sys("read error");
		else if(recv == 0)
		{
			printf("%d 线程接收到了关闭请求\n", tid);
			break;
		}
		printf("%u : %s\n", tid, buf);
		memset(buf, 0, sizeof(buf));	
		sleep(2);
	}	

	return NULL;
}
