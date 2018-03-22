#include <sys/mman.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

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

int main(int argc, char *argv[])
{	

	int	shm_id;
	sem_t	*sem_id;
	int	value;
	if(argc != 2)
		err_que("Command ShmName");

	if(fork() == 0)				// 子进程
	{
		sleep(1);
		if((shm_id = shm_open(argv[1], O_RDWR, 0)) ==-1)
                	err_sys("shm_open error");
        	if((sem_id = mmap(NULL, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED, shm_id, 0)) == NULL)
                	err_sys("mmap error");

		sem_getvalue(sem_id, &value);

		printf("子进程--当前信号量数目 : %d\n", value);
		sem_wait(sem_id);
		sleep(2);
		exit(0);
	}

						// 父进程
	if((shm_id = shm_open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
		err_sys("shm_open error");
	
	ftruncate(shm_id, sizeof(sem_t));

	if((sem_id = mmap(NULL, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED, shm_id, 0)) == NULL)
		err_sys("mmap error");

	// 创建无名信号量
	sem_init(sem_id, 1, 0);
	sem_post(sem_id);
	sleep(2);
	sem_getvalue(sem_id, &value);
	printf("父进程--当前信号量 : %d\n", value);
	waitpid(0, NULL, 0);
	return 0;
}
