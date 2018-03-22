#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct NodeStudent
{
	char *name;
	int age;
	int grade;	
}Node, *pNode;

inline void err_sys(const char *msg, int err)
{
	printf("%s : %s\n", msg, strerror(err));
	exit(0);
}

void * thread_th1(void *param);

int main()
{
	int err;
	pthread_t tid;
	void *a;

	Node one;
	one.name = "saligia";
	one.age = 20;
	one.grade = 98;
	printf("创建线程\n");	
	if(err = pthread_create(&tid, NULL, thread_th1, (void *)(&one)))
		err_sys("create error", err);
	pthread_detach(tid);
	sleep(5);	
	//if(err = pthread_join(tid,  &a))
	//	err_sys("join error", err);

	return 0;
}

void * thread_th1(void *param)
{
	int i ;
	int err;
	pNode pOne = (pNode)param;
	// 置线程为分离状态
	//	err_sys("pthread_detach error", err);
	
	puts(pOne->name);
	printf("%d\n", pOne->age);
	printf("%d\n", pOne->grade);
	

	pthread_exit((void *)param);
}
