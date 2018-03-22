# include <stdio.h>

int main (void)
{
	char str[10][10];

	printf ("str = %#X\n" , str);
	printf ("str1 = %#X\n" , str[1]);
	printf ("str[2][9] = %#X\n" , &str[2][9]);
	printf ("str3 = %#X\n" , str[3]);
	printf ("str4 = %#X\n" , str[4]);
	printf ("str5 = %#X\n" , str[6]);
	printf ("str0 = %#X\n" , str[0]);

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
str = 0X12FEE4
str1 = 0X12FEEE
str[2][9] = 0X12FF01
str3 = 0X12FF02
str4 = 0X12FF0C
str5 = 0X12FF20
str0 = 0X12FEE4
Press any key to continue
============================
*/