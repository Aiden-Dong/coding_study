#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <time.h>

#define SEM_KEY "./4-process_sem.c"

typedef union Semun{
	int 		val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo	*__buf;
}semun;

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char *msg, int key)
{
	printf("%s : %s\n", msg, strerror(errno));
	semctl(key, 0, IPC_RMID);
	exit(0);
}

void show_sem(const struct semid_ds *sem_msg);

int main()
{
	key_t key;
	pid_t pid;
	semun arg;
	struct semid_ds sem_msg;
	struct sembuf sem_opt;
	int sem_id;

	if((key = ftok(SEM_KEY, 1)) == -1)
		err_que("ftok error");
	if((sem_id = semget(key, 1, IPC_CREAT|O_EXCL|0660)) == -1)
		err_sys("semget error", sem_id);

	if((pid = fork()) == -1)
		err_sys("fork error", sem_id);

	else if(pid == 0)
	{
		sem_opt.sem_num = 0;
		sem_opt.sem_op	= 0;
		sem_opt.sem_flg = 0;

		puts("子进程请求信号量");

		semop(key, &sem_opt, 1);
		exit(0);	
	}
	arg.buf = &sem_msg;

	if(semctl(sem_id, 0, IPC_STAT, arg) == -1)
		err_sys("semctl error", sem_id);

	show_sem(&sem_msg);

	arg.val = 5;

	if(semctl(sem_id, 0, SETVAL, arg) == -1)
		err_sys("semctl error", sem_id);

	printf("sigval : %d\n", semctl(sem_id, 0, GETVAL, arg));	// 获取信号量的值

	sem_opt.sem_num = 0;
	sem_opt.sem_op = -2;
	sem_opt.sem_flg = 0;

	if(semop(sem_id, &sem_opt, 1) == -1)
		err_sys("semop error", sem_id);
	printf("semncnt : %d\n", semctl(sem_id, 0, GETZCNT, arg));

	printf("sigval : %d\n", semctl(sem_id, 0, GETVAL, arg));        // 获取信号量的值

	if(semctl(sem_id, 0, IPC_RMID, arg) == -1)
		err_sys("semctl error", sem_id);

	return 0;
}
void show_sem(const struct semid_ds *sem_msg)
{
	struct tm *local_tm;

	printf("sem_nsems : %d\n", sem_msg->sem_nsems);
	local_tm = localtime(&sem_msg->sem_otime);
	printf("sem_otime : %d-%d-%d\n", local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
	local_tm = localtime(&sem_msg->sem_ctime);
	printf("sem_ctime : %d-%d-%d\n", local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
}
