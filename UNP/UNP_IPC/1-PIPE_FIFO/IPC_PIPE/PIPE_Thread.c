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

// PIPE 为半双工管道
// 执行读取管道中的数据并输出

void * put_fifo(void * path);

int main(int argc, char *argv[])
{
	char		fifo_path[PATH_MAX];
	pthread_t	tid1, tid2;
	int 		fifo_fd[2];
	int		i;
	int		recv_len;


	if(pipe(fifo_fd) == -1)
		err_sys("pipe error");

	pthread_create(&tid1, NULL, put_fifo, (void *)fifo_fd[0]);

	sleep(1);	
	
	for(i = 0; i < 5; i++)
	{
		sleep(1);
		write(fifo_fd[1], "hello world", sizeof("hello world"));
		recv_len = read(fifo_fd[1], fifo_path, sizeof(fifo_path));
		if(recv_len == -1)
			err_sys("recv error");
		else if(recv_len == 0)
			break;
		puts(fifo_path);
		memset(fifo_path, 0, sizeof(fifo_path));
	}

	close(fifo_fd);

	sleep(3);

	return 0;
}


void * put_fifo(void * path)
{
	pthread_t	tid;
	char		buf[100];
	int		rd_fifo;

	rd_fifo = (int) path;
	
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

		write(rd_fifo, "hello world", sizeof("hello world"));
		
		printf("%u : %s\n", tid, buf);
		memset(buf, 0, sizeof(buf));	
		sleep(2);
	}	

	return NULL;
}
