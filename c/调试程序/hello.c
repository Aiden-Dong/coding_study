#include<conio.h> 
#include<stdio.h> 
#include <stdlib.h>

int main() 
{ 
	char a ,c , b ;
	int num1 , num2 ; 
	a = getch ();
	c = getch ();
	b = getch ();

	num1 = atoi(&a);
	num2 = atoi(&b);
	printf ("%d %d %d",num1 , num2 , num1+num2);
	printf ("\n");

	a = getch ();
	c = getch ();
	b = getch ();

	num1 = atoi(&a);
	num2 = atoi(&b);
	printf ("%d %d %d",num1 , num2 , num1+num2);
	printf ("\n");
	return 0;
}
