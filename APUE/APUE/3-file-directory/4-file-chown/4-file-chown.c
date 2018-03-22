#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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
	if(argc != 4)
		err_que("please input parameter : one two three");
	
	if(chown(argv[1], atoi(argv[2]), atoi(argv[3])) == -1)
		err_sys("chown error");
	else 
		puts("success to chown");
	return 0;
}
