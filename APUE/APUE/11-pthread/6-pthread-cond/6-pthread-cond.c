#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

/*
 * ******************************************************************
 * 生产者-消费者问题：
 * ---------------------------------
 *  在总共10个可用单元中， 生产者线程负责制造数据单元， 而消费者线程负
 *  则从线程中提取数据
 *
 *  当没有空的数据单元时， 生产者线程阻塞等待消费者释放数据
 *  当没有满的数据单元时， 消费者线程阻塞等待生产者制造数据
 *  
 ********************************************************************
 */

typedef struct StudentCard{
	char name[10];
	int age;
	int grade;
	pthread_mutex_t mutex;	// 用于线程的同步
}Node, *pNode;

pthread_cond_t Producond = PTHREAD_COND_INITIALIZER;
pthread_cond_t Consucond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t fimutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t emmutex = PTHREAD_MUTEX_INITIALIZER;

int iin, iout;
int empty, fill;

Node element[10];

inline void err_sys(const char *msg, int err)
{
	char buf[20];
	strerror_r(err, buf, 20);
	printf("%s : %s\n", msg, buf);	
	// strerror 在线程中不能保证是异步信号安全的， 要使用 strerror_r 来代替
	exit(0);
}

void signo(int sig);

void *thread_Product(void *param);	// 用于生产一个数据单元
void *thread_Consume(void *param);	// 用于释放一个数据单元

int main()
{
	int i ;
	struct sigaction act;
	int err = 0;
	pthread_t tid1, tid2;

	iin = 0;
	iout = 0;
	empty = 10;
	fill = 0; 
	
	srand((unsigned int)time(NULL));
	
	act.sa_handler = signo;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	//  初始化变量
	for(i = 0; i < 10; i++)
		if(err = pthread_mutex_init(&element[i].mutex, NULL))
			err_sys("pthread_mutex_init error", err);
	// 初始化互斥量
	
	if(err = pthread_create(&tid1, NULL, thread_Product, NULL))
		err_sys("pthread_create error", err);
	if(err = pthread_create(&tid2, NULL, thread_Consume, NULL))
		err_sys("pthread_create error", err);

	

	while(getchar())
	{
		pthread_kill(tid1, SIGUSR1);
		pthread_kill(tid2, SIGUSR1);

		for(i = iout; i != iin; i = (i+1)%10)
		{
			printf("========================\n");
			printf("代读取的数据 : %d\n", i);
			printf("姓名 : %s\n", element[iout].name);
	                printf("年龄 : %d\n", element[iout].age);
	                printf("成绩 : %d\n", element[iout].grade);
			printf("========================\n");
		}
	}
	
	return 0;
}

// 生产者线程
void *thread_Product(void *param)
{
	int i;
	int err;


	while(1)
	{
		if(err = pthread_mutex_lock(&element[iin].mutex))
			err_sys("pthread_mutex_lock error", err);
		// 对需要制造的内存单元加锁
		
		if(empty == 0)	// 说明没有空的单元需要制造
			if(err = pthread_cond_wait(&Producond, &element[iin].mutex))
				err_sys("pthread_cond_wait error", err);
		
		puts("制造一个数据对象");

		// 制造一个内存数据
		for(i = 0 ; i < 5; i++)
			element[iin].name[i] = rand()%26 + 97;
		element[iin].name[i]= 0;
		element[iin].age = rand()%30;
		element[iin].grade = rand()%100;

		if(err = pthread_mutex_unlock(&element[iin].mutex))
			err_sys("pthread_mutex_unlock error", err);

		if(err = pthread_mutex_lock(&emmutex))
			err_sys("pthread_mutex_lock error", err);
		empty--;
		if(err = pthread_mutex_unlock(&emmutex))
			err_sys("pthread_mutex_unlock", err);

		iin = (iin+1)%10;

		if(fill == 0)
		{	
			err = pthread_cond_signal(&Consucond);
			if(err != 0)
				err_sys("pthread_cond_signal error", err);
		}

		if(err = pthread_mutex_lock(&fimutex))
			err_sys("pthread_mutex_lock error", err);
		fill++;
	
		if(err = pthread_mutex_unlock(&fimutex))
			err_sys("pthread_mutex_unlock error", err);

		sleep(2);
	}

	return NULL;
		
}

// 消费者线程
void *thread_Consume(void *param)
{
	int i ;
	int err;

	while(1)
	{
		if(err = pthread_mutex_lock(&element[iout].mutex))
			err_sys("pthread_mutex_lock error", err);

		if(fill == 0)
		{
			err = pthread_cond_wait(&Consucond, &element[iout].mutex);
			if(err != 0)
				err_sys("pthread_cond_wait error", err);
		}			

		// 取出一个数据单元
		printf("取出一个数据\n");
		printf("姓名 : %s\n", element[iout].name);
		printf("年龄 : %d\n", element[iout].age);
		printf("成绩 : %d\n", element[iout].grade);

		if(err = pthread_mutex_unlock(&element[iout].mutex))
			err_sys("pthread_mutex_unlock error", err);
		iout = (iout+1)%10;

		if(err = pthread_mutex_lock(&fimutex))
                        err_sys("pthread_mutex_lock error", err);
		fill --;

		if(err = pthread_mutex_unlock(&fimutex))
                        err_sys("pthread_mutex_unlock error", err);

		if(empty == 0)
			if(err = pthread_cond_signal(&Producond))
				err_sys("pthread_cond_signal error", err);

		if(err = pthread_mutex_lock(&emmutex))
                        err_sys("pthread_mutex_lock error", err);
		empty ++;

		if(err = pthread_mutex_unlock(&emmutex))
                        err_sys("pthread_mutex_unlock", err);

		sleep(rand()%6);
	}
	

	return NULL;
}

void signo(int sig)
{
	sleep(5);
}
