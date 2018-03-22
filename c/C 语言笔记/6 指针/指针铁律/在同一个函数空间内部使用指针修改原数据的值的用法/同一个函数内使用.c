# include <stdio.h>

int main ()
{
	char str1[20] = {0} ;
	char str2[20] = {0} ;
	char *p1 = NULL ;
	char *p2 = NULL ;

	strcpy (str1 , "hellow world!!") ;

	p1 = str1 ;
	p2 = str2 ;

	while (*p1 != '\0')	// 此处为在同一个函数内调用 指针改变原值的用法 ；
	{
		*p2 = *p1 ;
		p1++ ;
		p2++ ;
	}
	return 0 ;
}