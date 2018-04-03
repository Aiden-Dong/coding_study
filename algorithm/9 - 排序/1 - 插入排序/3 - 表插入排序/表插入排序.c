#include <stdio.h>
#include "arrage.h"

int main ()
{
	SLinkType one ;
	int i ;
	int num[8] = {49 , 38 , 65 , 97 ,76,13 , 27,52};

	TableInsert (&one , num , 8);

	Arrange  (&one);
	for (i = 1 ; i <=8 ;i++)
		printf ("%d ",one.r[i].rc);
	printf ("\n");
	return 0;
}