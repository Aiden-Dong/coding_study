#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
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

int main(int argc, char *argv)
{
	struct stat attr;
	DIR *dp;
	struct dirent drent;

	if(argc != 2)
		err_que("argc error");

	if(stat(argv[1], &attr) == -1)
		err_sys("stat error");
	
	if(attr.st_mode & S_IFMT != S_IFDIR)
		err_que("please input dictory");
	
	return 0;
}
