# include <stdio.h>

int prime_number ( int n );

int main (void)
{
	int n , r , Sum = 0;
	int a , b;
	
	puts ("请输入要查询的数字");
	
	scanf ("%d",&n);

	printf ("\n==================================================================\n\n");
	
	for ( r = 2 ; r <= (n/2) ; r++ )
	{
		a = r;
		b = n - r;

		if ( prime_number(a) && prime_number(b))
		{
			printf ("%5d + %5d = %5d\n", a , b , n );
			Sum++;
		}
	}
	
	printf ("\n==================================================================\n");
	printf ("总共有 %d 组这样的组合\n" , Sum);
	
	return 0;
}
int prime_number ( int n )
{
	int r ;
	bool judge ;
	
	if ( n == 2 )
		judge = 1;
	
	else
	{
		for ( r = 2 ; r < n ; r++ )
		{
			if ( n % r == 0 )
			{
				judge = 0;
				break;
			}
			else
			{
				judge = 1;
			}
		}
	}
	
	return judge;
}
