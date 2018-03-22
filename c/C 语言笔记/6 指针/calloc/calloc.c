# include <stdio.h>
# include <stdlib.h>

int main ()
{
	int ** p = (int **) calloc (8 , sizeof (int*)) ; // (总长度 ， 每个成员长度) 
	int i = 0 , x , y ;

	for (i = 0 ; i < 8 ; i++)
		p[i] = (int *) calloc (8 , sizeof (int));

	for (y = 0 ; y < 8 ; y++)
	{
		for (x = 0 ; x < 8 ; x++)
			printf ("%2d" , p[y][x]);
		printf ("\n") ;
	}

	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
============================
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0
Press any key to continue
============================
*/