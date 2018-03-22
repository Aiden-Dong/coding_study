#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

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
pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s pid : %lu  tid : %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void * thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *) 0);
}

int main()
{
	int err;

	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if(err != 0)
		err_sys("pthread_create error");

	printids("main thread :");

	sleep(1);

	return 0;
}
