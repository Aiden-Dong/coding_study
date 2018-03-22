# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int reverse_str (char *inbuf , char *outbuf) ;

int main ()
{
	char str1[20] = "hellow world!!" ;
	char str2[20] ;

	reverse_str (str1 , str2) ;

	printf ("%s\n" ,str2) ;
	return 0 ;
}

int reverse_str (char *inbuf , char *outbuf)
{
	char * iterator = inbuf ;

	if (inbuf == NULL || outbuf == NULL)
	{
		printf ("error to copy this : reverse_str  (inbuf == NULL||outbuf == NULL)\n") ;
		exit (-1) ;
	}
	
	while (*iterator != '\0')
		iterator ++ ;

	do {
		iterator -- ;
		*outbuf++ = * iterator ;
	}while (iterator != inbuf) ;

	*outbuf = '\0' ;

	return 0;

}