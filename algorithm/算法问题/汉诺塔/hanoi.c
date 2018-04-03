#include <stdio.h>

void hanoi (int n , char A , char B , char C);

int main ()
{
	int n ;
	printf ("请输入 A 柱的盘子数 : \n");
	scanf ("%d",&n);
	hanoi (n , 'A' , 'B' , 'C');

	return 0 ;
}
void hanoi (int n , char A , char B , char C)
{
	if (n == 1)
		printf ("%c -> %c \n" , A , C);
	else
	{
		hanoi (n-1 , A , C , B);
		printf ("%c -> %c \n" , A , C);
		hanoi (n-1 , B , A , C);
	}
}