# include <stdio.h>
# include <stdlib.h>

int main ()
{
	int a = -100 , j , f ;
	double b =12.5 ; 
	char * c = "14.7" ;

	printf ("labs(-100) = %d\n" , labs (-100)) ;	// labs () 函数的用法
	printf ("atof (char *c) = %f\n" , atof (c)) ;	 // atof () 函数的用法
	printf ("atol (char *c) = %ld\n" , atol ("100")) ;	// atol () 函数用法
	printf ("atoi (char *c) = %d\n" , atoi ("100.12")) ;	// atoi () 函数用法
	printf ("ecvt () = %s\n" , ecvt (12.3 , 4 , &j , &f)) ;
	printf ("j = %d , f = %d\n", j , f) ;
	printf ("fcvt () = %s\n" , fcvt (-12.3 , 4 , &j , &f)) ;
	printf ("j = %d , f = %d\n", j , f) ;


	return 0 ;
} 