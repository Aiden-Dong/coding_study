# include <stdio.h>
# include <string.h>

int str_test (char *instr , char * outstr) ;

int main ()
{
	char str[30] = "       hellowworld!!    " ;
	char str2 [20] ;

	str_test (str , str2) ;

	printf ("%s\n" , str2) ;
	return 0 ;
}
int str_test (char *instr , char * outstr)
{

	while (*instr == ' ') 
	{
		instr ++ ;
	}

	while (*instr != ' ')
	{
		*outstr++ = *instr ;
		instr++ ;
	}

	*outstr = '\0' ;

	return 1 ;
}