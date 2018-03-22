#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void err_sys(const char *msg)
{	
	puts(msg);
	exit(0);
}

void err_que(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main(int argc, char *argv[])
{
	sem_t		*semid;
	int		pid;
	int		value;

	if(argc != 2)
		err_que("Command SemphoreName");

	if((pid = fork()) == 0)		// 子进程
	{
		sleep(1);
		printf("子进程开始运行\n");
		if((semid = sem_open(argv[1], 0)) == -1)
			err_sys("sem_open error");
		sem_wait(semid);
		puts("子进程获取到信号");
		sem_close(semid);
		exit(0);	
	}
					// 父进程
	if((semid = sem_open(argv[1], O_CREAT, S_IRWXU, 0)) == -1)
		err_sys("sem_open error");

	sleep(2);
	printf("父进程运行\n");
	sem_getvalue(semid, &value);
	printf("当前信号值 : %d\n", value);
	fflush(stdout);
	sem_post(semid);
	sem_post(semid);
	waitpid(0, NULL, 0);

	sem_getvalue(semid, &value);
        printf("当前信号值 : %d\n", value);
	sem_close(semid);
	sem_unlink(argv[1]);
	return 0;
}
