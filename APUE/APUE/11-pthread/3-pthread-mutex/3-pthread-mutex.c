#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/************* 宏定义 **********************/
#define NHASH 29
#define HASH(id) (((unsigned long)id)%NHASH)

typedef struct student
{
	char name[20];
	char card[20];
	int age;
	char grade;
}St, *pSt;

typedef struct foo
{
	int f_count;
	St f_one;	
	pthread_mutex_t f_lock;
	int f_id;
	struct foo *f_next;
}Foo, *pFoo;

pFoo fh[NHASH];

pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

/****************** 内联 错误处理 ************/
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
/****************  处理工具 *********************/
pFoo foo_alloc(int id)
{
	pFoo fp;
	int idx;

	if((fp = (pFoo)malloc(sizeof(Foo))) == NULL)
		return NULL;
	fp->f_count = 1;
	if(pthread_mutex_init(&fp->f_lock, NULL) != 0)
	{
		free(fp);
		return NULL;
	}
	fp->f_id = id;

	idx = HASH(id);

	pthread_mutex_lock(&hashlock); // 对表进行加锁
	
	fp->f_next = fh[idx];
	fh[idx] = fp;
	
	pthread_mutex_unlock(&hashlock); // 对表进行解锁

	pthread_mutex_lock(&fp->f_lock); // 对单位项目进行加锁
	// 对项目进行处理
	pthread_mutex_unlock(&fp->f_lock); // 对单位项目进行解锁

	return fp;
}

pFoo foo_find(int id)
{
	pFoo fp;

	pthread_mutex_lock(&hashlock); // 对表加锁 -- 防止查找时发生链表变化
	for(fp = fh[HASH(id)] ; fp != NULL ; fp = fp->f_next)
	{
		if( fp->f_id == id)
		{
			pthread_mutex_lock(&fp->f_lock); // 对表项执行加锁
			fp->f_count++;
			pthread_mutex_unlock(&fp->f_lock);//释放表项锁
			break;
		}
	}
	pthread_mutex_unlock(&hashlock); // 完成操作， 释放锁

	return fp;
}

void foo_rele(pFoo fp)
{
	pFoo tfp;
	int idx;

	pthread_mutex_lock(&fp->f_lock);
	if(fp->f_count == 1)
	{
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_lock(&hashlock);
		pthread_mutex_lock(&fp->f_lock); // 顺序加锁 防止死锁
		if(fp->f_count != 1) // 窗口过程中被改动
		{
			fp->f_count--;
			pthread_mutex_unlock(&hashlock);
			pthread_mutex_unlock(&fp->f_lock);
		}

		idx = HASH(fp->f_id);
		tfp = fh[idx];
		if(tfp == fp)
			fh[idx] = fp->f_next;
		else
		{
			while(tfp->f_next != fp)
				tfp = tfp->f_next;
			tfp->f_next = fp->f_next;
		}

		// 留意解锁顺序
		pthread_mutex_unlock(&hashlock);
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	}

	else
	{
		fp->f_count --;
		pthread_mutex_unlock(&fp->f_lock);
	}
}
int main()
{
	
	return 0;
}
