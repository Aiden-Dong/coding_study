# include <stdio.h>
# include <stdlib.h>

int main ()
{
	int a ;
	int b ; 
	int * p1 = (int *)malloc (4) ;
	int * p2 = (int *)malloc (4) ;

	printf ("p1 = %d \nb = %d\n" , &a , &b) ;  // 栈的开口向下  a 的地址比 b 的地址大 ;
	printf ("p2 = %d \nb = %d\n" , p1 , p2) ;	// 堆的生长方向是向上的 ;

	return 0 ;
}
/*
在 VC++6.0 的运行环境中
========================
a = 1244996
b = 1244992
p1 = 5844624
p2 = 5844680
========================
*/