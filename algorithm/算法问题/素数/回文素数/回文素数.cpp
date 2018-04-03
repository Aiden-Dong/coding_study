# include <stdio.h>

int h_wen ( int n );
int prime_number ( int n );

int main (void)
{
	int n , i ;
	puts ("请选择要查找的上限 :");

	scanf ("%d",&n);

	puts ("================================================================================");

	for ( i = 2 ; i <= n ; i ++)
	{
		if (prime_number (i) )
		{
			if ( h_wen (i) )
			{
				printf ("%4d " , i);
			}
		}
	}

	printf ("\n");
	puts ("================================================================================");
	printf ("\n\n");

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
int prime_number ( int n )
{
	int r , judge ;
	
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
