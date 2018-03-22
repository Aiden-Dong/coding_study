# include <stdio.h>

# define FINE(a , b) printf ("a * b = %d \n", a*b)

int main ()
{
	FINE ( 2 , 4) ;
	return 0 ; 
}
/*
在 VC++6.0 的运行环境中：
======================
a * b = 8
Press any key to continue
======================
*/