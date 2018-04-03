# include <stdio.h>

int f_lie ( int n );

int main (void)
{
	int n , r;

Start:
	
	printf ("请输入要显示的总项数 :\n");
	scanf ("%d",&n);
	
	if ( n <= 0 )
		goto Start;
	
	else
	{
		
		for ( r = 1 ; r <= n ; r++ )
		{
			printf ("%d  ",f_lie(r) );
		}
	}
	
	return 0;
}
int f_lie ( int n )
{
	int Sum = 0;
	
	if ( n == 1 )
		Sum =1;
	else if ( n == 2 )
		Sum = 1;
	else
		Sum = f_lie( n-1 ) + f_lie ( n-2 );

	return Sum;
}