#include <pwd.h>
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

void show_pwd(const struct passwd *);

int main(int argc, char *argv[])
{
	struct passwd *pwd_msg;

	if(argc != 2)
		err_que("please input parameter ...");

	if((pwd_msg = getpwnam(argv[1])) == NULL)
		err_sys("getpwnam error");
	// 获取指定用户名的详情信息
	
	show_pwd(pwd_msg);
	
	setpwent();
	while((pwd_msg = getpwent()) != NULL)
	{
		getchar();
		show_pwd(pwd_msg);
	}
	endpwent();
	return 0;
}
void show_pwd(const struct passwd* msg)
{
	puts("用户信息 : ");
	puts(msg->pw_name);
	puts(msg->pw_passwd);
	printf("UID : %d\n", msg->pw_uid);
	printf("GID : %d\n", msg->pw_gid);
}
