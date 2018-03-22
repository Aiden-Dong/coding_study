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
	

	setsid();
	
	// 设置信号屏蔽
	sigemptyset(&proc_sigset);
	sigaddset(&proc_sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &proc_sigset, &proc_osigset);

	if(stat(FIFO_FILE, &file_msg) == -1)
		err_sys("stat error");
	else if((file_msg.st_mode & S_IFMT) != S_IFIFO)
		err_que("file is not fifo");

	if((fifo_fd = open(FIFO_FILE, O_WRONLY))== -1)
		err_sys("open error");

	if(getrlimit(RLIMIT_NOFILE, &fd_rlimit) == -1)
		err_sys("getrlimit error");

	umask(0);
	
	for(i = 0; i < fd_rlimit.rlim_max; i++)
	{
		if(i != fifo_fd)
			close(i);
	}

	if(dup2(fifo_fd, 0) == -1)
		err_sys("dup2 error 0");
	if(dup2(fifo_fd, 1) == -1)
		err_sys("dup2 error 1");
	if(dup2(fifo_fd, 2) == -1)
        	err_sys("dup2 error 2");


	if((msg_fd = msgget(MSG_KEY, 0600)) == -1)
		err_sys("msgget error");

	if((log_fd = open(DAEMON_FILE, O_WRONLY|O_APPEND)) == -1)
		err_sys("open error");

	// 守护进程配置完成
	puts("sucess");
	fflush(stdout);	

	sigprocmask(SIG_SETMASK, &proc_osigset, NULL);

	while(1)
	{
		
		if(msgctl(msg_fd, IPC_STAT, &msg_mess) == -1)	// 检测当前信号值
			err_sys("msgctl eror");
		
		memset(&log_msg, 0, sizeof(MSG));

		errno = 0;

		if(msgrcv(msg_fd, &log_msg,sizeof(MSG), 0, 0) == -1)
			err_sys("msgrcv error");

		write(log_fd, log_msg.msg_text, strlen(log_msg.msg_text));

		fsync(log_fd); // 等待数据写回
	
	}

	return 0;
}      

