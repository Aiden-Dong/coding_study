#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
 /*
 * 在调用 readv 跟 writev 时， 要注意 使所调用的缓冲区全部读完（或写完）
 * */
typedef struct Card{
	char name[20];
	char ip[20];
	char id[20];
}Node, *pNode;
inline void err_que(const char * msg)
{
	puts(msg);
	exit(0);
}

inline void err_sys(const char * msg)
{
	printf("%s : %s\n", msg, strerror(errno));
	exit(0);
}

int main(int argc, char *argv[])
{
	int fd;
	int i;
	Node card[2]; 
	struct iovec iobuf[2];
	
	if(argc != 2)
		err_que("please input a file for open");

	if((fd = open(argv[1], O_WRONLY)) == -1)
		err_que("open error");
	
	memset(card, 0, sizeof(Node)*2);
	for(i = 0; i < 2; i++)
	{
		fgets(card[i].name, 20, stdin);
		fgets(card[i].ip, 20, stdin);
		fgets(card[i].id, 20, stdin);
	}

	iobuf[0].iov_base = &card[0];
	iobuf[0].iov_len = sizeof(Node);
	iobuf[1].iov_base = &card[1];
	iobuf[1].iov_len = sizeof(Node);
 
	writev(fd, iobuf, 2);

	return 0;
}
