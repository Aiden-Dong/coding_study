#include <grp.h>
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

void show_pwd(const struct group *);

int main(int argc, char *argv[])
{
	struct group *pwd_msg;

	if(argc != 2)
		err_que("please input parameter ...");

	if((pwd_msg = getgrnam(argv[1])) == NULL)
		err_sys("getpwnam error");
	// 获取指定用户名的详情信息
	
	show_pwd(pwd_msg);
	
	setpwent();
	while((pwd_msg = getgrent()) != NULL)
	{
		getchar();
		show_pwd(pwd_msg);
	}
	endpwent();
	return 0;
}
void show_pwd(const struct group* msg)
{
	int i = 0 ;

	puts("用户信息 : ");
	puts(msg->gr_name);
	puts(msg->gr_passwd);
	printf("GID : %d\n", msg->gr_gid);

	while(msg->gr_mem[i] != NULL)
		printf("name : %s\n",msg->gr_mem[i++]);
}
