#include "public_source.h"
#include "myservice.h"
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/fcntl.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/*
 * 创建守护进程来处理日志文件的记录问题
*/

int 	fifo_fd;
int 	msg_fd;

static void exit_func(void)
{
	msgctl(msg_fd, IPC_RMID, NULL);	
}

int main(int argc, char *argv[])
{

	struct stat 	file_msg;
	struct rlimit 	fd_rlimit;
	struct msqid_ds msg_mess;
	sigset_t	proc_now;
	sigset_t	proc_sigset, proc_osigset;
	MSG  		log_msg;
	char 		msg[50];
	int 		msg_fd;
	int 		log_fd;
	int 		i;
	int 		pid, tid;
	


	if(fork() > 0)
		exit(0);
	setsid();
	
	if(fork()>0)
		exit(0);
	// 设置信号屏蔽
	sigemptyset(&proc_sigset);
	sigaddset(&proc_sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &proc_sigset, &proc_osigset);

	if(getrlimit(RLIMIT_NOFILE, &fd_rlimit) == -1)
		err_sys("getrlimit error");

	umask(0);
	
	for(i = 0; i < fd_rlimit.rlim_max; i++)
		close(i);

	// 查看守护进程的 日志文件是否存在不存在便创建
        if(stat(DAEMON_FILE, &file_msg) == -1)
                if(creat(DAEMON_FILE, S_IRUSR|S_IWUSR) == -1)
                        err_sys("create error");

	if((msg_fd = msgget(MSG_KEY, IPC_CREAT|0600)) == -1)
		err_sys("msgget error");

	if((log_fd = open(DAEMON_FILE, O_WRONLY|O_APPEND)) == -1)
		err_sys("open error");

	atexit(exit_func);

	while(1)
	{
		
		memset(&log_msg, 0, sizeof(MSG));

		errno = 0;

		if(msgrcv(msg_fd, &log_msg,sizeof(MSG), 0, 0) == -1)
			err_sys("msgrcv error");

		write(log_fd, log_msg.msg_text, strlen(log_msg.msg_text));

		fsync(log_fd); // 等待数据写回
	
	}

	return 0;
}      

