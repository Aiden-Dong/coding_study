# include <stdio.h>

# define JIN(n) x##n 
# define FINE(n) printf ("x"#n"= %d \n" , x##n)
int main ()
{
	int JIN(1) = 20 ;
	FINE (1) ;
	return 0 ;
}
/*
在 VC++6.0 的运行环境中
=========================
x1= 20
Press any key to continue
=========================
*/