# include <stdio.h>

void point_number (int(*a)[10]);
void poin_number2 (int (*b)[4]) ;	// 数组指针的本质是一个指针  数组决定着指针的步长
int main ()
{
	int a[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

	int b[3][4] = {
		{1 , 2 , 3 , 4 },
		{5 , 6 , 7 , 8 },
		{9 , 10 , 11 , 12}
	} ;

	poin_number2 (b) ;
	point_number (a) ;

	return 0 ;
}
void point_number (int(*a)[10])
{
	int i = 0 ;

	for ( ; i < 10 ; i++)
		printf ("%3d" , (*a)[i]) ;	//   1  2  3  4  5  6  7  8  9 10
	printf ("\n") ;
}
void poin_number2 (int (*b)[4]) 
{
	int i = 0 ;
	int j = 0 ;

	for (j=0 ; j < 3 ; j++)
	{
		for ( i = 0; i < 4 ; i++)
			printf ("%3d" , (*b)[i]) ;
		printf ("\n") ;
		b ++ ;
	}
	/*
		  1  2  3  4
		  5  6  7  8
		  9 10 11 12
	*/
}