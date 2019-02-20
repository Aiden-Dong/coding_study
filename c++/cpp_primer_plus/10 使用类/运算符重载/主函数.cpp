# include <iostream>
# include "name.h"

int main ()
{
	Victor r1 ( 2 , 4 , 2);
	Victor r2 ( 4 , 6 , 2);
	Victor r3;

	r1.c_a ();
	r1.c_b ();
	r1.c_c ();

	r2.c_a ();
	r2.c_b ();
	r2.c_c ();

	r3 = r1 + r2;

	r3.c_a ();
	r3.c_b ();
	r3.c_c ();

	r3 = r1.operator + (r2);
	r3.c_a ();
	r3.c_b ();
	r3.c_c ();


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
====================================
a = 2
b = 4
c = 2
a = 4
b = 6
c = 2
Bye!!!
Bye!!!
a = 6
b = 10
c = 4
Bye!!!
Bye!!!
a = 6
b = 10
c = 4
Bye!!!
Bye!!!
Bye!!!
Press any key to continue
====================================
*/