#include <semaphore.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SHM_KEY "./6-process_semaphore.c"
#define SHM_SIZE 60
#define SEM_NAME "/home"

int shm_id   = 0;
sem_t *p_sem = NULL;

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

void exit_fcntl(void);
void show_shm(const struct shmid_ds *shm_msg);

int main()
{
	pid_t pid;
	key_t key;
	int   sem_val;
	struct shmid_ds shm_msg;

	atexit(exit_fcntl);

	if((key = ftok(SHM_KEY, 1)) == -1)
		err_sys("ftok error");

	if((shm_id = shmget(key, SHM_SIZE, IPC_CREAT|0660)) == -1)
		err_sys("shmget error");

	if((p_sem = sem_open(SEM_NAME, O_CREAT, 0660, 1)) == SEM_FAILED)
		err_sys("sem_open error");

	if((pid = fork()) == -1)
		err_sys("fork error");

	else if(pid == 0)	// ============================= 子进程
	{
		char *buf1;

		if(sem_wait(p_sem) == -1)			// 获取共享内存的操作权
			err_sys("sem_wait error");

		printf("子进程获取资源\n");

		if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
			err_sys("semctl error");

		if((buf1 = (char *)shmat(shm_id, NULL, 0)) == NULL)
                                err_sys("shmat error");

		if(shm_msg.shm_nattch == 0)
		{
			printf("子进程写入数据\n");
			memset(buf1, 0, SHM_SIZE);
			strcpy(buf1, "hello world\n");	
		}
		else
			printf("子进程获取数据 : %s", buf1);

		if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
				err_sys("shmctl error");

		show_shm(&shm_msg);
		printf("子进程释放资源\n");

		sem_post(p_sem);				// 释放锁资源 
		exit(0);
	}
	else	//=============================父进程 
	{
		char *buf2;
		
		if(sem_wait(p_sem) == -1)		     // 获取锁资源
			err_sys("sem_wait error");
		printf("父进程获取资源 :\n");
		
		if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
			err_sys("shm_id error");

		if((buf2 = shmat(shm_id, NULL, 0)) == NULL)  // 关联内存
			err_sys("shmat error");

		if(shm_msg.shm_nattch == 0)		     // 表示没有进程于此关联
		{
			printf("父进程写入数据\n");
			memset(buf2, 0, SHM_SIZE);
			strcpy(buf2, "hello world\n");
		}		
		else 
			printf("父进程读取数据 : %s", buf2);

		sem_getvalue(p_sem, &sem_val);
		printf("sem_val ----  %d\n", sem_val);

		if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
			err_sys("shmctl error");

		show_shm(&shm_msg);

		printf("父进程释放资源 .\n");
		sem_post(p_sem);		// 释放锁资源
		wait();				// 等待子进程结束
		exit(0);
	}

}

void exit_fcntl()		// 退出清理函数
{

	printf("清理函数启动 : \n");

	if(shm_id != 0)
		shmctl(shm_id, IPC_STAT, NULL);
	if(p_sem != NULL)
		sem_unlink(SEM_NAME);
		
}

void show_shm(const struct shmid_ds *shm_msg)
{
	printf("==============\n");
	printf("shm_segsz : %d\n", shm_msg->shm_segsz);
	printf("shm_lpid  : %d\n", shm_msg->shm_lpid);
	printf("shm_cpid  : %d\n", shm_msg->shm_cpid);
	printf("shm_nattch: %d\n", shm_msg->shm_nattch);
	printf("==============\n");
}
