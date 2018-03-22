# include <stdio.h>
# include <string.h>

int str_find (char *s1 , char *s2) ;

int main ()
{
	char *p = "hellabcdjundabcdjheibaldbhabcdabcdjigabc" ;
	char *s = "abcd" ;

	printf ("字符串总共出现过 %d 次\n" ,str_find(p ,s) );

	return 0 ;
}
int str_find (char *s1 , char *s2)
{
	int * p = s1 ;
	int num = 0 ;

	while (p!=NULL)
	{
		
		if ((p = strstr(p , s2)) != NULL)
		{
			printf ("%s\n" , p) ;
			num++ ;
			p++;
			printf ("%s\n" , p);
		}
	}

	return num ;
}
/*
在 VC++6.0 的运行环境中:
========================
abcdjundabcdjheibaldbhabcdabcdjigabc
jundabcdjheibaldbhabcdabcdjigabc
abcdjheibaldbhabcdabcdjigabc
jheibaldbhabcdabcdjigabc
abcdabcdjigabc
abcdjigabc
abcdjigabc
jigabc
字符串总共出现过 4 次
Press any key to continue
========================
*/