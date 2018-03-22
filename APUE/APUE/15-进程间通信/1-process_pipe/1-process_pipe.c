#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/*
 * 	协同进程模型：
 * 			父进程从标准输入中获取数据然后将处理的数据发往子进程
 * 			子进程作为 协同进程 从标准输入接受数据， 然后对数据处理后发送给
 * 				标准输出
 *
 * */

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

int main()
{
	char buf_prent[10];
	int len;
	int fdin[2], fdout[2];		// 用于管道
	int pid;		

	pipe(fdin);			
	pipe(fdout);				
	
	if((pid = fork()) == -1)
		err_sys("fork error");
	
	// 子进程关闭标准输入与标准输出， 然后将管道连接标准输入与标准输出
	// 成为协同进程
	if(pid == 0)		
	{
		char buf_child[10];
		
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(fdin[1]);
		close(fdout[0]);
	
		// 关联标准输入与标准输出
		if(dup2(fdin[0],0) == -1)
			err_sys("dup2 error");
		if(dup2(fdout[1], 1) == -1)
			err_sys("dup2 error");

		memset(buf_child, 0, sizeof(buf_child));
		fprintf(stderr, "正在获取数据\n");
		if(read(STDIN_FILENO, buf_child, sizeof(buf_child)) == -1)
			err_sys("read error");
		fprintf(stderr, "已经获取数据\n");

		if(strcmp(buf_child, "test") == 0)
			write(STDOUT_FILENO, "ok", sizeof("ok"));
		else
			write(STDOUT_FILENO, "error", sizeof("error"));

		return 0;
	}

	// 父进程从标准流中读写数据， 中间经过协同进程来处理
	
	close(fdin[0]);
	close(fdout[1]);

	sleep(1);
	write(fdin[1], "one", sizeof("test"));
	len = read(fdout[0], buf_prent, sizeof(buf_prent));
	
	write(STDOUT_FILENO, buf_prent, len);

	return 0;
}
