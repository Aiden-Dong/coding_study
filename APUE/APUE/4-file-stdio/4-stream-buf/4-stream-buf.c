#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	char bufin[20];
	char bufout[20];
	char buf[20];

	if(argc != 2)
		err_que("please input a lparam for choice....");
	switch(atoi(argv[1]))
	{
	case 1:
		puts("you choice Line buf");
		setvbuf(stdin, bufin, _IOLBF, 20);
		setvbuf(stdout, bufout, _IOLBF, 20);
		break;
	case 2:
		puts("you choice no buf");
		setvbuf(stdin, NULL, _IONBF, 0);
		setvbuf(stdout, NULL, _IONBF, 0);
		break;
	default:
		puts("Not choice buffer type");
	}	
	
	memset(buf, 0, sizeof(buf));

	while(fread(buf, 20, 1, stdin))
	{
		fwrite(buf, sizeof(buf), 1, stdout);
		memset(buf, 0, sizeof(buf));
	}
	
	
	return 0;
}
