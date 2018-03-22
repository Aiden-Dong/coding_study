#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct stat Stat ;
typedef struct stat *pStat;

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

void show_DIR(DIR *);
const char* show_mode(pStat);
void ch_buf(char *);

int main(int argc, char *argv[])
{
	char buf[PATH_MAX];
	char d_name[20];
	struct stat msg;
	struct dirent *dir;
	DIR *dr;
	char ch;

        puts("=======================");
        puts("= please chose :      =");
        puts("= 1--显示当前的目录项 =");
        puts("= 2--进入指定目录     =");
        puts("= 0--退出             =");
        puts("=======================");
	
	memset(d_name, 0, sizeof(d_name));
	memset(buf, 0, sizeof(buf));

	puts("=====================================================");
	// 获取当前目录
	getcwd(buf, PATH_MAX);
	printf("当前目录 : %s\n", buf);
	// 打开当前目录
	if((dr = opendir(buf)) == NULL)
		err_sys("open dir error");
	
	
	while(1)
	{
		puts("请选择操作 :");

		switch(ch = getchar())
		{
		case '1':
			show_DIR(dr);
			break;
		case '2':
			getchar();
			printf("请输入目录名：");
			scanf("%s", &d_name);
		
			if(stat(d_name, &msg) == -1)
				err_sys("stat error");
			if((msg.st_mode & S_IFMT) == S_IFDIR)
			{
				strcat(buf, "/");
				strcat(buf, d_name);
				chdir(buf);
				closedir(dr);
				if((dr = opendir(buf)) == NULL)
					err_sys("opendir error");
				memset(buf, 0, sizeof(buf));
				getcwd(buf, sizeof(buf));
				printf("当前目录 : %s\n", buf);
			}
			else
				puts("==== please input DIR===");
			break;
		case '0':
			break;
		}

		while(getchar() != '\n');

		if (ch == '0')
			break;
	}
	
	return 0;
}

const char* show_mode(pStat st)
{
	switch(st->st_mode & S_IFMT)
	{
	case S_IFREG:
		return "REG";
	case S_IFDIR:
		return "DIR";
	case S_IFLNK:
		return "LNK";
	case S_IFIFO:
		return "FIFO";
	default:
		return "OTHER";
	}
}
void show_DIR(DIR *dr)
{
	Stat st;
	struct dirent *one_dir;
	
	// 遍历目录
	puts("========================================");
	while((one_dir = readdir(dr)) != NULL)
	{
		stat(one_dir->d_name, &st);
		printf("%s -- %s\n", one_dir->d_name, show_mode(&st));	
	}
	puts("========================================");
	printf("\n");
}

void ch_buf(char *buf)
{

}

