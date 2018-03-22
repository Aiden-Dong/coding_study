#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/*
*文件记录锁：
*	1： 锁与进程跟文件都有关联， 进程关闭时对此文件的所有文件锁都被释放，
*	    			     文件描述符关闭时此进程在此文件的文件锁都被释放
*	2： 由fork 产成的子进程不仅继承父进程的文件锁（深刻体会第一条）
*	3： 执行exec 函数后新进程可以继承原执行程序的锁机制
*
 */
inline void err_que(const char *msg)
{
	printf("%s\n",msg);
	exit(0);
}

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main(int argc, char *argv[])
{
	char buf[20];
	int fd;
	int pid;
	struct flock f_lock;
	int len;

	if(argc != 2)
		err_que("please input open file");
	
	f_lock.l_type = F_WRLCK;
	f_lock.l_whence = SEEK_SET;
	f_lock.l_start = 0;
	f_lock.l_len = 1;
	f_lock.l_pid = getpid();

	fd = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0770);
	if(fd == -1)
		err_sys("open error");
	
	if(fcntl(fd, F_GETLK, &f_lock) == -1)
		err_sys("fcntl -- F_GETLK error");
	if(f_lock.l_type != F_UNLCK)
		err_que("sorry ... you can't create this file lock");
	else
		f_lock.l_type = F_WRLCK;

	if(fcntl(fd, F_SETLK, &f_lock) == -1) // 设置记录锁
		err_sys("fcntl error");

	if((pid = fork()) == -1)
		err_sys("fock error");
	else if(pid == 0)		// 子进程
	{
		puts("子进程正在运行。。。。");
		if(fcntl(fd, F_SETLKW, &f_lock) == -1)
			err_sys("child fcntl error");

		printf("子进程写操作\n");

		if(write(fd, "hello world", sizeof("hello world")) == -1)
			err_sys("write error");
		f_lock.l_type = F_UNLCK;
		if(fcntl(fd, F_SETLK, &f_lock) == -1)
			err_sys("子进程解锁错误");
		printf("子进程操作完成\n");
		exit(0);
		
	}

	// 父进程
	
	puts("请输入数据");
	while(len = read(STDIN_FILENO, buf, sizeof(buf)))
	{
		if(len == -1)
			err_sys("read error");
		if(write(fd, buf, len) == -1)
			err_sys("write error");
	}
	f_lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &f_lock);

	printf("父进程解锁成功\n");

	return 0;
}
