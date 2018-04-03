# include <stdio.h>

int h_wen ( int n ); 

int main (void)
{
	int n , t;
	puts ("请输入要检验的数字 :");

	scanf ("%d" , &n );

	t = h_wen (n);

	if (t)
		puts ("这个数是回文数 !!!!");
	else
		puts ("这个数不是回文数!!!!!!");

	return 0;
}
int h_wen ( int n )
{
	bool t;
	int m = 0 , r;

	r = n;

	while ( n > 0)
	{
		m = 10*m + n%10;
		n = n/10;
	}

	//printf ("%d\n" , m);

	if ( m == r )
		t = 1;
	else
		t = 0;

	return t; 
}