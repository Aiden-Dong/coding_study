#include <shadow.h>
#include <time.h>
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

void show_pwd(const struct spwd *);

int main(int argc, char *argv[])
{
	struct spwd *pwd_msg;

	if(argc != 2)
		err_que("please input parameter ...");

	if((pwd_msg = getspnam(argv[1])) == NULL)
		err_sys("getpwnam error");
	// 获取指定用户名的详情信息
	
	show_pwd(pwd_msg);
	
	setspent();
	while((pwd_msg = getspent()) != NULL)
	{
		getchar();
		show_pwd(pwd_msg);
	}
	endspent();
	return 0;
}
void show_pwd(const struct spwd* msg)
{
	struct tm *loctm;

	loctm = localtime(&msg->sp_lstchg);

	puts("用户信息 : ");
	puts(msg->sp_namp);
	puts(msg->sp_pwdp);
	printf("lstchg : %d-%d-%d\n", loctm->tm_year+1900, loctm->tm_mon, loctm->tm_mday);
	printf("Min  : %d\n", msg->sp_min);
	printf("Max  : %d\n", msg->sp_max);
	printf("warn : %d\n", msg->sp_warn);
	printf("inact: %d\n", msg->sp_inact);
}
