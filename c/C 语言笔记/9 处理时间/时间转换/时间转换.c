# include <stdio.h>
# include <time.h>

int main ()
{
	time_t now ;
	struct tm  *nowtime ;
	char *c ;

	time(&now); // time (&now) ;
	nowtime = localtime (&now);

	c = asctime(nowtime);  // 打印时间

	puts (c) ;
	c = ctime (&now) ;
	puts (c) ;

	return 0 ;
}