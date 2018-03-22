#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

int main(int argc, char *argv[])
{
	int val = 0;
	int n = 1;
	FILE *fp;

	if (argc != 2)
		err_que("please input a lparam");

	printf("val -- %d\n", atoi(argv[1]));

	switch(atoi(argv[1]))
	{
	case 1:
		val = fwide(stdout, 0);
		break;
	case 2:
		val = fwide(stdin, 0);
		break;
	default:
		printf("sorry ...");		
		n = 0;
	}		

	if (n)
		printf("流模式 : %d", val);
	else
	{
		fp = fopen(argv[1], "r");
		val = fwide(fp, 0);
		printf("流模式 :%d\n", val);
	}

	return 0;
}
