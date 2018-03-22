#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

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

void show_time(const struct tm *);

int main(int argc, char *argv[])
{
	time_t time_now;
	struct tm * tm_now;

	time_now = time(NULL); // 获取当前的时间（日历时间）
	
	puts("localtime :");
	tm_now=localtime(&time_now); // 进行时间转换(转换成协调同一时间)	
	show_time(tm_now);
	puts("gmtime :");
	tm_now=gmtime(&time_now);    // 转换成本地世界
	show_time(tm_now);
	return 0;
}

void show_time(const struct tm * tm_now)
{
	printf("日期 : %d - %d - %d\n", tm_now->tm_year + 1900, tm_now->tm_mon, 
					tm_now->tm_mday);
	printf("时间 : %d:%d:%d\n", tm_now->tm_hour, tm_now->tm_min,
				    tm_now->tm_sec);
}
