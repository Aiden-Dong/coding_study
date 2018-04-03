#include <stdio.h>

int main ()
{
	int i;
	int a[10] = {-1, 7 , 9 , 1 , 3 , 4 , 5 , 8, 6 , 0};
	HeapSort (a,9);

	for (i = 0 ; i < 10 ; i++)
		printf ("%d ",a[i]);
	printf("\n");
	return 0;
}

