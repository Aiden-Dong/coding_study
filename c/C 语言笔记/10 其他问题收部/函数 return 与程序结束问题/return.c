# include <stdio.h>

int r_test ();

int main ()
{
	r_test() ;
	return 0 ;
}
int r_test ()
{
	return 0 ;

	printf ("函数运行至此 : ===!!\n");	// 在函数调用中 遇到了 return 就要停止
}
