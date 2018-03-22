#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void err_que(const char *msg)
{
	puts(msg);
	exit(0);
}

void err_sys(const char *msg)
{
	printf("%s:%s\n", msg, strerror(errno));
	exit(errno);
}

int main(int argc, char *argv[])
{
	int											sockfd;
	int											recv_len;
	int											fsize;
	int											index;
	int											cursize;
	int											file_fd;
	int											read_len;
	char										*file_name;
	char										filemsg[128];
	char										strbuff[128];
	struct sockaddr_in			serviceaddr;
	struct stat							file_msg;
	struct timespec					timestart, timeend;

	if(argc != 3)
		err_que("client Ipaddress filename");

	file_name = argv[2] + strlen(argv[2]) -1;
	while(*(file_name-1) != '/')
		file_name--;

	if(stat(file_name, &file_msg) != -1)
	{
		if(!S_ISREG(file_msg.st_mode))
			err_que("file is exist in locale and it isn't a regeular file");

		while(1)
		{
				write(STDOUT_FILENO, "file is exist are you replace it ?? (y|n) :\n", strlen("file is exist are you replace it ?? (y|n) :\n"));
				switch (getchar()) {
					case 'y':
					case 'Y':
										break;
					case 'n':
					case 'N':
										exit(0);
										break;
					default:
									while(getchar()!='\n');
									continue;
				}
				break;
		}
	}
	else if(errno != ENOENT)
		err_sys("stat file error");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		err_sys("socket error");


	memset(&serviceaddr, 0, sizeof(serviceaddr));
	serviceaddr.sin_family = AF_INET;
	serviceaddr.sin_port	= htons(8068);
	if(inet_pton(AF_INET, argv[1], (void *)&serviceaddr.sin_addr.s_addr) == -1)
		err_sys("inet_pton error");

	// 链接服务器
	if(connect(sockfd, (struct sockaddr *)&serviceaddr, sizeof(serviceaddr)) == -1)
		err_sys("connect error");

	if(send(sockfd, argv[2], strlen(argv[2]), 0) == -1)
		err_sys("send error");

	memset(filemsg, 0, sizeof(filemsg));
	if(recv(sockfd, filemsg, sizeof(filemsg), 0) == -1)
		err_sys("recv error");

	if(!strncmp(filemsg, "file is not exist", strlen("file is not exist")))
			err_que("file is not exist in service");
	if(!strncmp(filemsg, "file read false", strlen("file read false")))
				err_que("file read false");

	sscanf(filemsg, "file size : %d", &fsize);

	if((file_fd = open(file_name, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)) == -1)
		err_sys("file open error");

	write(STDOUT_FILENO,"File is transport now :\n", strlen("File is transport now :\n"));
	write(STDOUT_FILENO,"==========================================================================================\n",
							 strlen("==========================================================================================\n"));
	if(clock_gettime(CLOCK_REALTIME, &timestart) == -1)
		err_sys("clock_gettime error");

	cursize = 0;	// 当前已经读取的大小
	index 	= 0;	// 当前的点数

	while(read_len=recv(sockfd, strbuff, sizeof(strbuff), 0))
	{
		int i;

		if(read_len == -1)
			err_sys("read_error");


		cursize += read_len;

		for(i =0; i < (int)((double)cursize/fsize * 90)-index; i++)
			write(STDOUT_FILENO, "#", 1);
		index = (int)((double)cursize/fsize * 90);

		if(write(file_fd, strbuff, read_len) == -1)
			err_sys("send error");
	}
	if(clock_gettime(CLOCK_REALTIME, &timeend) == -1)
		err_sys("clock_gettime error");

	printf("\nUsetime : %d:%d\n", timeend.tv_sec - timestart.tv_sec, timeend.tv_nsec-timestart.tv_nsec);
	close(sockfd);
	return 0;
}
