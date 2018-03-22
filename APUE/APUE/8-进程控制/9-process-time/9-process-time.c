#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

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

static void pr_times(clock_t, struct tms *, struct tms * );
static void do_cmd(char *);

int main(int argc, char *argv[])
{
	int i ;	
	struct timespec tim;

	setbuf(stdout,NULL); // 设置标准输出流 无缓冲

	for(i = 1; i < argc; i++)
		do_cmd(argv[i]);
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tim);	
	printf("进程时间 : %d-%d\n", tim.tv_sec,tim.tv_nsec);

	return 0;
}

static void do_cmd(char *cmd)
{
	struct tms tmsstart, tmsend;
	clock_t start, end;
	int status;

	printf("/ncommand: %s\n",cmd);

	/*
 	***********************************************************************
	*	clock_t times(struct tms *buf);
	*	---------------------------------------------------------------
	*	用法：
	*		应调用times 保存其返回值 ， 在以后的某个时间
	*		内再次times  差值为 墙上时间
	*	返回值:
	*		流逝的墙上滴答时间 可以使用 _SC_CLK_TCK 转换成秒
	*	struct tms
	*	{
	*		clock_t tms_utime;
	*		clock_t tms_stime;
	*		clock_t tms_cutime;
	*		clock_t tms_cstime;
	*	}
 	*
 	***********************************************************************
 	*/

	if((start= times(&tmsstart)) == -1) // 获取执行之前的开始时间
		err_sys("times error");
	
	if((status = system(cmd)) == -1)
		err_sys("system error");

	if((end = times(&tmsend)) == -1) // 获取执行之后的终止时间
		err_sys("times error");
	
	pr_times(end-start, &tmsstart, &tmsend);

	printf("system 终止状态 : %d\n", WEXITSTATUS(status));
}

static void pr_times(clock_t real, struct tms* tmsstart, struct tms * tmsend)
{
	static long clktck = 0;

	if(clktck == 0)
		if((clktck = sysconf(_SC_CLK_TCK)) == -1)
			err_sys("sysconf error");

	printf(" real : %7.2f\n",  real/(double)clktck);
	printf(" user : %7.2f\n", 
		(tmsend->tms_utime - tmsstart->tms_utime) / (double)clktck);
	printf(" sys  : %7.2f\n", 
		(tmsend->tms_stime - tmsstart->tms_stime) / (double)clktck);
	printf(" child user: %7.2f\n",
		(tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck);
	printf(" child sys: %7.2f\n",
		(tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck);
}
