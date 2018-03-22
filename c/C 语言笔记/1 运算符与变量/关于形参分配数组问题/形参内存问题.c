# include <stdio.h>

void memory (int a[10]) ;

int main ()
{
	int a[10] ;
	int i ;

	for ( i = 0 ; i < 10 ; i ++)
		a[i] = i ;
	memory (a) ;

	return 0 ;
}
void memory (int a[10])
{

	printf ("a 的大小 : %d\n" , sizeof (a[10])); // 即使形参为 a[10]  编译器 也会自动的转化为 指针 
	printf("a[9] = %d\n" , a[9]) ;  // a[9] = 9
}