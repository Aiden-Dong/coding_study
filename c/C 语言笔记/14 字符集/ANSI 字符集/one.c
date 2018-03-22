#include <stdio.h>
#include <string.h>
#include <windows.h>

int main ()
{
	FILE *fp ;
	char ch[51] ;
	char buf[4];
	int i = 0;

	fp = fopen("one.txt","r");

	memset (ch , 0 , sizeof(ch));
	memset(buf , 0 , sizeof(buf));
	
	while(fread(buf, 1 , 1 , fp) && !feof(fp))
	{		
		if((0x80 & buf[0]) == 0x80)
		{
			fread (&buf[1] , 1 , 1 , fp);
			strncpy (&ch[i] , buf , 2);
			i = i+2 ;

			if(i == 50 || i == 49)
			{
				printf ("%s\n",ch);
				memset(ch , 0 , sizeof(ch));
				i = 0 ;
			}
		}
		else
		{
			strncpy(&ch[i] , buf , 1);
			i++ ;
			if(i == 50 || i == 49)
			{
				printf ("%s",ch);
				memset(ch , 0 , sizeof(ch));
				i = 0 ;
			}
		}	
		
	}
	printf ("%s",ch);

	fclose(fp);

	return 0;
}