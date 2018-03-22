# include <stdio.h>
# include <stdlib.h>

int main ()
{
	FILE *fp ;
	int a[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10} ;
	int i ;

	fp = open ("first.txt" ,"a") ;

	if (fp == NULL)
	{
		puts ("error to open first.txt") ;
		//exit (-1) ;
	}

	for (i = 0 ; i < 10 ; i++)
		fputc (a[i] , fp) ;
	close (fp) ;
	return 0 ;
}