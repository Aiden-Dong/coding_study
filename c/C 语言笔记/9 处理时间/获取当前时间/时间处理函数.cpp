# include <stdio.h>
# include <time.h>

int main (void)
{
	time_t now;
	long n= 0;

	//time (&now);     // time_t time ( time_t *timeptr );

	now = time (0);    // 返回距离 1970 年1 月一日 到现在位置所经过的秒数

	while ( time(0) - now <= 1)

		n++;      //计算每秒的运算次数

	printf ("\a\a");
	printf ("n = %d\n",n);

	return 0;
}