# include <stdio.h>
#include <conio.h>

int main (void)
{
	char a;

    puts ("请输入 :");
	a  = getch ();

	printf ("c =  %d\n",a);

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入 :
c =  f
Press any key to continue
=============================
*/