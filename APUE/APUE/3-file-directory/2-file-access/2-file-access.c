#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

inline void err_que(char *msg)
{
	puts(msg);
	exit(0);
}
inline void err_sys(char *msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}
int main(int argc, char *argv[])
{
	if(argc != 2)
		err_que("please input parameter");

//========= 通过有效用户测试打开权限=================
	if(open(argv[1], O_RDONLY) == -1)
		err_sys("open error");
	else
		puts("open success");

//========= 测试实际用户的打开权限===============
	if(access(argv[1], R_OK) == -1)
		err_sys("access error");
	else
		puts("access success");
	return 0;
}
