#include "sstable.h"
#include <stdio.h>
#include <string.h>

void Create (pssTable table , int n)
{
	int i = 0 ;

	for (i = 0 ; i < n ; i++)
	{
		table[i].Market = i;
		puts ("请输入记录名 :");
		gets(table[i].name);
	}

}

int Traverse (pssTable table , int n ,const char *str )
{
	int i = 0;
	if (!strcmp (str , table[0].name))
		return 0;
	memset (table[0].name , 0 , sizeof(table[0].name));
	strcpy (table[0].name , str);
	
	for (i = n-1 ; strcmp(str,table[i].name) ; i--);

	if (i == 0)
		return -1;
	else
		return i;
	
}