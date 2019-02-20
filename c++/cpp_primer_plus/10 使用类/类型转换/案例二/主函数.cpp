# include <iostream>
# include "name.h"

int main ()
{
	using std::cout ;
	using std::endl ;

	Stock temp;
	Stock temp1 (12 , 16 , 2.30);
	Stock temp3;

	temp3 = Stock(5.2);              // 使用了关键字 explicit 后只能使用 显式转换

	temp.show ();
	cout << endl;
	temp1.show ();
	cout << endl;
	temp3.show ();
	cout << endl;

	temp = temp1 + temp3;

	temp.show ();
	cout << endl;


}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
Bybe!!
a = 0
b = 0
c = 0

a = 12
b = 16
c = 2.3

a = 5
b = 0
c = 0

Bybe!!
Bybe!!
a = 17
b = 16
c = 2.3

Bybe!!
Bybe!!
Bybe!!
Press any key to continue
============================
*/