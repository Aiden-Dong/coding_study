#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
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

int main()
{
	char *tmpname;
	char bufname[L_tmpnam];
	char bufin[20];
	char bufout[20];
	int fd1, fd2;
	int len;
	

	tmpname = tmpnam(bufname);
	printf("temporary file : %s\n", tmpname);

	if(creat(tmpname, S_IRWXU | S_IRWXG) == -1)
		err_sys("creat error");

	if((fd1 = open(tmpname, O_WRONLY)) == -1)
		err_sys("open error");
	if ((fd2 = open(tmpname, O_RDONLY)) == -1)
		err_sys("open error");

	remove(tmpname);

	while(len = read(STDIN_FILENO, bufin, 20))
	{
		if(len == -1)
			err_sys("read error");

		if(write(fd1, bufin, len) == -1)
			err_sys("write error");

		if ((len = read(fd2, bufout, 20)) == -1)
			err_sys("read error");

		if (write(STDOUT_FILENO, bufout, len) == -1)
			err_sys("write error");
	}

	return 0;
}
