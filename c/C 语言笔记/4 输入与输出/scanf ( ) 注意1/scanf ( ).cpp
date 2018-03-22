# include <stdio.h>

int main (void)
{
	char str[10];
	char str1[10];
	char str2[10];
	char c;

	scanf ( "%s" , str);
	puts (str);

	gets (str1);
    puts (str1);


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
hellow world
hellow
 world
Press any key to continue
=============================
*/
