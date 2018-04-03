#include <stdio.h>

int main ()
{
	int i , a[10] = {5 , 2 , 6 , 0 , 3 , 9 , 1 , 7 , 4 , 8};

	QuickSort (a , 10);
	puts ("排序后的结果为 :");
	for (i = 0 ; i < 10 ; i++ )
		printf ("%d ",a[i]);
	printf ("\n");

	return 0;
}

