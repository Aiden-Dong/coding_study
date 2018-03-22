# include <stdio.h>

int main (void)
{
	char a[2][6];
	char b[6];
	int  r;
	//char a[6];

	for ( r = 0 ; r <= 1 ; r++)
		gets (a[r]);
	puts ( a[0] );

	for ( r = 0 ; r <= 4 ; r++)
		scanf ("%c",&b[r]);
	puts (b);
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
123456
asd
123456asd

asdfwed
asdfw烫?23456asd
Press any key to continue
==============================
*/