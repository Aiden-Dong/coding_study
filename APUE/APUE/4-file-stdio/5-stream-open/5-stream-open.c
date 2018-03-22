#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
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

void show_fp(FILE *fp);
void show_fd(int fd);

int main(int argc, char *argv[])
{
	FILE *fp;
	int fd;

	if(argc == 3)
		puts("please input a open file and a type for open");
	fp = fopen(argv[1], argv[2]);

	show_fp(fp);

	fd = fileno(fp);

	show_fd(fd);

	return 0;
}
void show_fp(FILE *fp)
{
	printf("I/O stream :\n");
	puts("================");
	printf("file size : %d\n", fp->_bufsiz);
	printf("template file: %s\n", fp->_tmpfname);
	printf("file : %s\n", fp->_ptr);
}
void show_fp(int fd)
{
	struct stat attr;

	printf("file flags:\n");
	puts("===============");
	fstat(fd, &attr);
	printf("file size : %d\n",attr.st_size);
}
