# include <stdio.h>
# include <time.h>

int main (void)
{
	time_t start , finish , now, noe;
	struct tm *ptr ;
	char *c , buf1 [80];
	double duration;

	start = time(0);
	time (&now);

	ptr = localtime (&now);
	noe = mktime (ptr);

	c = asctime (ptr);
	puts (c);
	getc (stdin);

	strftime (buf1 , 80 , "This is week %U of the year %Y",ptr);
	puts (buf1);
	getc (stdin);

	finish =  time (0);

	duration = difftime ( finish , start );

	return 0;
}