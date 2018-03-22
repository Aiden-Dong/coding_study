#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char *env;
	int i =0;

	if(argc != 2)
		puts("please input a environment variable ...");
	else
	{
		if(env = getenv(argv[1]))
			puts(env);
		else
			puts("not variable");
	}
/*
	// 获取指定的环境变量	
	printf("PATH = %s\n", getenv("PATH"));
	
	//设置环境变量 ： 
	//环境变量的设置只影响到当前的进程及其子进程， 但是并不影响父进程
	
	// 设置形式1：
	// 如果出现一定以的变量， 则先删除原先的变量
	putenv("env1=hello world");
	printf("env1= %s\n", getenv("env1"));
	
	// 设置形式2：
	// 如果 rewrite 值为 0， 则不删除原定义
	// 否则，出现已定义的变量， 先删除
	setenv("env2", "saligia", 0);	
	printf("env2=%s\n", getenv("env2"));

	for(i = 0 ; environ[i] != NULL ; i++)
		puts(environ[i]);
	
*/
	return 0;
}
