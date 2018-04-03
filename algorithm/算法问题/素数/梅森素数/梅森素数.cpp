# include <stdio.h>

int prime_number ( int n );

int main (void)
{
	int n , r , i = 1 ,j ;
	_int64 Sum;

	puts ("请输入要查找的个数 :");

	scanf ("%d",&n);
	r = 2;
	while( i <= n )
	{
	
		if (prime_number(r))
		{
			Sum = 1;
			for ( j = 1 ; j <= r ; j++)
				Sum = 2 * Sum;
			Sum--;
			if (prime_number(Sum))
			{
				printf ("%4d -> %4d\n",r,Sum);
				i++;
			}
		}
		r++;
	}
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

