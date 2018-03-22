# include <stdio.h>

void copy_first (char *s1 , char *s2) ;
void copy_second (char *s1 , char *s2) ;
void copy_third (char *s1 , char *s2) ;

int main ()
{
	char one[20] = {"hellow world!!"} ;
	char two [20] ;
	char three[20] ;
	char four[20] ; 

	copy_first (one , two) ;
	printf ("%s\n" , two) ;
	copy_second (one , three) ;
	printf ("%s\n" , three) ;
	copy_third (one , four) ;
	printf ("%s\n" ,four) ;

	return 0 ;
}

void copy_first (char *s1 , char *s2)
{
	for ( ; *s1 != '\0' ; s1++ , s2++)
		*s2 = *s1 ;
	*s2 = '\0' ;
}
void copy_second (char *s1 , char *s2) 
{
	while (*s1 != '\0')
	{
		*s2++ = *s1++ ;
	}
	*s2 = '\0' ;
}
void copy_third (char *s1 , char *s2) 
{
	while ((*s2++ = *s1++) != '\0') ;
}
/*
在 VC++6.0 的运行环境中 :
==========================
hellow world!!
hellow world!!
hellow world!!
Press any key to continue
==========================
*/