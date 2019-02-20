# include <iostream>
# include "static.h"

int main ()
{
	using std::endl ;
	using std::cout ;

	int a ;

	Element one ;

	one.show_static () ;
	one.in_static (7) ;	// 一般不允许使用成员函数改变静态变量的值
						// 防止造成混乱

	Element two ;

	two.show_static () ;

	Element three ;

	cout << Element::a << endl ;

	three.show_static () ;
	
	cout << three.virst () << endl  ;

	cout << Element::virst () << endl ;		//  静态类成员函数的另类访问方式

	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
===========================
静态类变量 : 10
静态类变量 : 11
静态类变量 : 12
Press any key to continue
===========================
*/