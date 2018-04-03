#include <stdio.h>
#include "olgraph.h"

int main ()
{
	OLGraph one; 

	CreateDG (&one);

	PrintDG (&one);
	free (one.xlist);

	return 0;
}