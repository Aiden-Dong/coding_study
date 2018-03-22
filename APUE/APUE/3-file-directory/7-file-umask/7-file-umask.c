#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
	mode_t oldm;
	oldm = umask(S_IRWXO);	// 设置文件权限屏蔽字
	if(creat("one", S_IRWXU|S_IRWXG|S_IRWXO) == -1)
	{
		printf("creat error\n");
		exit(0);
	}
	
	return 0;
}
