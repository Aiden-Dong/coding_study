# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main ( void )
{
	int x , y;
	int str1 [2][3] = {
		{ 1 , 2 , 3 },
		{ 4 , 5 , 6 }
	};
	int str2 [2][3];

	memcpy ( str2 , str1 , sizeof (str1));
	for ( y = 0 ; y <= 1 ; y++)
	{
	
		for ( x = 0 ; x <= 2 ; x++)
		{
			printf ("%d ",str2[y][x]);
		}
		printf ("\n");
	}
	return 0;
}