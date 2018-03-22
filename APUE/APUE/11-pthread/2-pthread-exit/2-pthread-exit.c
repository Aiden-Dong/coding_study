#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

inline void err_sys(const char *msg, int err)
{
	printf("%s : %s\n", msg, strerror(err));
	exit(0);
}

void *thr_fn1(void *arg)
{
	printf("thread 1 returning\n");
	sleep(3);
	printf("thread 1 stop\n");
	return ((void *)1);
}

void *thr_fn2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void *)2);
}

int main()
{
	pthread_t tid1, tid2;
	int err;
	void *tret; // 获取退出码

	// 创建线程
	
	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if(err != 0)
	{
		printf("pthread_create error\n");
		exit(0);
	}	
	err = pthread_create(&tid2, NULL, thr_fn2, NULL);
	if(err != 0)
	{
		printf("pthread_create error\n");
		exit(0);
	}
	puts("thread 1 send cancel");
	pthread_cancel(tid1);
	puts("thread 1 send OK");
	// 等待线程结束并获取结束值
	err = pthread_join(tid1, &tret);
	if(err != 0)
	{
		printf("pthread_join error\n");
		exit(0);
	}
	printf("thread 1 exit code %ld\n", (long)tret);

	err = pthread_join(tid2, &tret);
	if(err != 0)
	{
		printf("pthread_join error\n");
		exit(0);
	}
	printf("thread 2 exit code %ld\n",(long)tret);

	return 0;
}
