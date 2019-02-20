# include <iostream>
# include "static.h"

int Element::a = 10 ;	// 类中的静态变量 拥有广义上的静态变量的影子
						// 就是说当第一次声明这种类的对象时 ， 将使用
						// 静态成员的变量赋值 ；
						// 否则一旦拥有了此类的对象 ， 将不再进行初始化时候的赋值运算 ， 而是直接使用原有数据
						// 所有的类对象共享一个 静态成员副本

Element::Element (){}

void Element::And () {a++ ;}


void Element::show_static ()  
{
	using std::cout ;
	using std::endl ;

	cout << "静态类变量 : " << a << endl ;
	And () ;
	
}
void Element::in_static (int b)
{
	a = b ;
}

int Element::virst ()	// static 成员函数不可访问非静态变量
{
	//Element::And () ;	// 也不可调用非静态 成员函数
	return a ;
}