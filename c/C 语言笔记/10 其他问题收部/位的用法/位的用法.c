# include <stdio.h>

int main ()
{
	int i = 12, y = 0 ;
	printf ("%d\n" , 3<<1) ;
	printf ("%d\n" , 3>>1) ;

	y = 1 << i ;
	printf("y = %d\n", y);
	printf("y = %#x\n",y);

	return 0 ;
}