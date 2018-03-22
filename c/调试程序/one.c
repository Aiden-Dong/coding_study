#include <stdio.h>
#include <string.h>

int main ()
{
	char one1[20] = "hello ";
	char * one2 = "world";
	strcat (one1 , one2);
	return 0;
}