#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

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

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX sysconf(_POSIX_HOST_NAME_MAX)
#endif

int main(int argc, char *argv[])
{
	struct utsname utsnam_msg;
	char hostname_msg[HOST_NAME_MAX];

	if(uname(&utsnam_msg) == -1)
		err_sys("uname error");

	puts(utsnam_msg.sysname);	// 系统名
	puts(utsnam_msg.nodename);	// 主机名
	puts(utsnam_msg.release);
	puts(utsnam_msg.version);
	puts(utsnam_msg.machine);

	if(gethostname(hostname_msg, HOST_NAME_MAX) == -1)
		err_sys("gethostname error");
	printf("host name : %s\n", hostname_msg);
	return 0;
}
