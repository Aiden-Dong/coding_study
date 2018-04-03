#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "binarysort.h"

int main ()
{
	int i;
	int a;
	pBinaryTree one = NULL;

	srand ((unsigned int)time(NULL));

	for (i = 0 ; i < 5 ; i++)
	{
		a = rand()%50 ;
		printf ("a = %d\n",a);
		CreateBinarySortTree (&one , a);
	}

	TravelBinarySortTree (one);
	printf ("End\n");

	printf ("请输入要删除的结点 : \n");
	scanf ("%d",&a);
	EarseBinarySortTree (&one, a);
	TravelBinarySortTree (one);
	printf ("End\n");
	return 0;
}

