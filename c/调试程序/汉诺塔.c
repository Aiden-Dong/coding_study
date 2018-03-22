#include <stdio.h>
 

void hanoi(n,A,B,C);

int main()
{
	int n;
	char c1='a'	,c2='b',c3='c';
	printf("input a number=");
	scanf("%d",&n);
	hanoi(n,c1,c2,c3);
	
	
	return 0;
}

void hanoi(n,A,B,C)
{
	
	if(n==1)
		printf("%c to %c\n",A,B);
	else
	{
		
		
		hanoi(n-1,A,C,B);
		printf("%c to %c\n",A,B);
		hanoi(n-1,C,B,A);
	}
	
}