#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define SHM_BUF "./5-process_shm.c"
#define SHM_SIZE (int)50

inline void err_sys(const char *msg, int shm_id)
{
	printf("%s : %s\n", msg, strerror(errno));
	shmctl(shm_id, IPC_RMID, NULL);
	exit(0);
}

inline void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

void show_shm(const struct shmid_ds *shm_msg);
void show_tim(const char *msg, time_t tim);
void signo(int sig);

int main()
{
	int shm_id;
	struct shmid_ds shm_msg;
	char *buf;
	key_t key;
	pid_t pid;

	if((key = ftok(SHM_BUF, 1)) == -1)
		err_que("ftok error");

	if((shm_id = shmget(key, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0660)) == -1)
		err_sys("shmget error", shm_id);

	if((pid = fork()) == -1)
		err_que("fork error");

	else if(pid == 0)
	{
		char *buf1;
		struct sigaction act;
		struct shmid_ds my_shm;

		act.sa_handler = &signo;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_RESTART;

		sigaction(SIGUSR1, &act, NULL);

		pause();

		if((buf1 = shmat(shm_id, NULL, 0)) == NULL)
			err_sys("shmat error", shm_id);

		if(shmctl(shm_id, IPC_STAT, &my_shm) == -1)
			err_sys("shmctl error", shm_id);

		show_shm(&my_shm);

		puts(buf1);

		exit(0);
	}


	if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
		err_sys("shmctl error", shm_id);

	show_shm(&shm_msg);

	if((buf = (char *)shmat(shm_id, NULL, 0)) == NULL)
		err_sys("shmctl error", shm_id);

	memset(buf, 0, 50);
	
	strcpy(buf, "hello world\n");
	
	if(shmctl(shm_id, IPC_STAT, &shm_msg) == -1)
		err_sys("shmctl error", shm_id);

	show_shm(&shm_msg);

	kill(pid, SIGUSR1);
	wait();	
	return 0;
}

void signo(int sig)
{
	printf("子进程开始运行\n");
}
void show_shm(const struct shmid_ds *shm_msg)
{
	printf("====================================\n");
	printf("shm_segsz : %d\n", shm_msg->shm_segsz);
	printf("shm_lpid  : %d\n", shm_msg->shm_lpid);
	printf("shm_cpid  : %d\n", shm_msg->shm_cpid);
	printf("shm_nattch: %d\n", shm_msg->shm_nattch);
	show_tim("shm_atime", shm_msg->shm_atime);
	show_tim("shm_dtime", shm_msg->shm_dtime);
	show_tim("shm_ctime", shm_msg->shm_ctime);

}
void show_tim(const char *msg, time_t tim)
{
	struct tm *local_tm;
	
	local_tm = localtime(&tim);

	printf("%s : %d-%d-%d\n", msg, local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
}
