# include <stdio.h>

int main ()
{
	FILE *fp ;
	int a ;
	char c ;
	int i = 0;

	fp = fopen ("C:\\Users\\think\\Documents\\KOEI\\Shin Sangokumusou 5\\Savedata\\save.dat" , "r") ;


	if (fp == NULL)
		puts ("error") ;

	while (i++ < 100)
	{
	fread (&a , sizeof(int) , 1 , fp) ;
	
	printf ("%d  ",a) ;
	//printf ("\n");
	}

	return 0 ;
}