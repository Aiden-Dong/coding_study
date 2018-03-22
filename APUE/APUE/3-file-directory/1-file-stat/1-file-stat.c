#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

typedef struct stat stats, *pstat;

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

void show_msg(char * , pstat);

int main(int argc, char *argv[])
{
	struct stat file_msg;
	stats fd_msg;

	if(argc != 2)
		err_que("please input parameter ......");

	if(stat(argv[1], &file_msg) == -1)
		err_sys("stat error");

	if(fstatat(AT_FDCWD, argv[1], &fd_msg, AT_SYMLINK_NOFOLLOW) == -1)
		err_sys("fstatat error");

	show_msg(argv[1], &file_msg);
	puts("--------------------");
	show_msg(argv[1], &fd_msg);

	
	return 0;
}
void show_msg(char * file_name, pstat file_msg)
{
	switch(file_msg->st_mode & S_IFMT)
	{
	case S_IFREG:
		printf("%s is REG\n", file_name);
		break;
	case S_IFDIR:
		printf("%s is DIR\n", file_name);
		break;
	case S_IFLNK:
		printf("%s is LNK\n", file_name);
		break;
	}
	printf("%s -- UID : %d , GID : %d\n", file_name, file_msg->st_uid, file_msg->st_gid);	//查看用户 ID 和用户组ID 
	printf("%s's size --- size : %d , blocksize : %d , blocknum : %d\n", 
		file_name, file_msg->st_size, file_msg->st_blksize, file_msg->st_blocks);	
		// 查看文件的大小， 分配的块数量，文件系统的块大小
	printf("%s inode number : %d\n", file_name, file_msg->st_ino);			// 文件的inode 节点号
	printf("%s link num is : %d\n", file_name, file_msg->st_nlink);			// 文件的链接数
	printf("%s device num is :%d\n", file_name, file_msg->st_dev);			// 文件的设备号
}

