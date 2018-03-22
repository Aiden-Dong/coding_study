# include <stdio.h>
# include <math.h>

int primer_number (int a) ;

int main ()
{
	int n ;

	printf ("请输入 : ") ;

	scanf ("%d" , &n ) ;

	printf ("质数 : %d\n" , primer_number (n)) ;

	return 0 ;
}

int primer_number (int a)
{
	int t = 0 ;
	int r ;
	int i , j ;
	int x , y ;

	x = y = a ;
	i = j = 0 ;

	if (a < 2 )
		return 2;

	if (a == 2 || a == 3 )
		return a ;

	while (1)
	{
		

		if (x % 2 == 0 )
		{
			x++ ;	
			i++;
		}

		for ( r = 3 ; r < sqrt (a)+1 ; r = r+2)
		{
			if (x % r == 0)
			{
				x++ ;
				i++ ;
				break ;
			}
		}

		if (r >= sqrt (x)+1 )
			break ;
	}

	while (y>1)
	{
		

		if (y % 2 == 0  )
		{
			y-- ;
			j++ ;
		}	

		for ( r = 3 ; r < sqrt (a)+1 ; r = r+2)
		{
			if (y % r == 0 )
			{
				y-- ;
				j++ ;
				break ;
			}
		}

		if (r >= sqrt (y)+1 )
			break ;
	}
	return i <= j ? x : y ;
}