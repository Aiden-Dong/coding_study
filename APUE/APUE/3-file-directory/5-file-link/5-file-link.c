#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

// link 创建的是Hard link
// symlink 创建的是symbolic link

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
	int a;
	int nlen;
	struct stat file_msg;
	char buf[30];
/*
	if(argc != 3)
		err_que("please input parameter : one two");

	if(puts("can you link or symlink : 1/2 ") && (fgetc(stdin) == '1'))
	{
		if(link(argv[1], argv[2]) == -1)
			err_sys("link error");
		else 
			puts("link success");

		a = 1;
	}
	else
	{
		if(symlink(argv[1], argv[2]) == -1)
			err_sys("symlink error");
		else
			puts("symlink success");

		readlink(argv[2], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, strlen(buf));

		a = 2;
	}

	fstatat(AT_FDCWD, argv[2], &file_msg, AT_SYMLINK_NOFOLLOW);

	printf("%s : %d\n", argv[1], file_msg.st_nlink);
	
	getchar();
	
	if(puts("can you unlink : y") && (fgetc(stdin) == 'y')) 
		unlink(argv[2]);	

	fstatat(AT_FDCWD, argv[2], &file_msg, AT_SYMLINK_NOFOLLOW);
	printf("%s : %d\n", argv[1], file_msg.st_nlink);
*/
	nlen = readlink(argv[1], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, nlen);

	return 0;
}
