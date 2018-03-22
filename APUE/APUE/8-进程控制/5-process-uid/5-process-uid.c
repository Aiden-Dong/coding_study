#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

inline void err_sys(const char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

void show_uid();

int main(int argc, char *argv[])
{

	show_uid();		// 查看当前的实际用户 ID 和有效用户ID （是否有设置用户ID 存在）
	if(setuid(1000) == -1)
		err_sys("setuid error");
	show_uid();
	if(setuid(0) == -1)
		err_sys("setuid error");
	show_uid();

	return 0;
}
void show_uid()
{

	printf("my uid is : %d\n", getuid());			// 获取该进程的用户     ID
	printf("my effective uid is : %d\n", geteuid());	// 获取该用户的有效用户 ID
}
