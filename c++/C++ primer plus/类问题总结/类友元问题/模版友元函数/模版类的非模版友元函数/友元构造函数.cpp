# include <iostream>
# include "friendone.h"

template <typename T>
Base<T>::Base (T it)
{
	items = it ;
	a ++ ;
}

template <typename T>
int Base<T>::a = 0 ;


// 实例化是用模版的特例

void count ()	// 模版类的非模版友元函数具有访问本模版的所有实例的权利
{
	std::cout << "int 型 : " << Base<int>::a << std::endl ; // 必须使用作用域解析运算符调用静态变量
	std::cout << "double 型 :" << Base<double>::a << std::endl ; // 同上
	//std::cout << "int " << Base::item << std::endl ;	// 友元函数无法直接访问 模版类的成员函数
}

// 为友元函数提供模板类参数，必须提供特定的具体化

void r_Base (Base<int> one , int a)	// 使用时必须显示调用特定的实例对象才能进行赋值 
{
	one.item = a ;
	std::cout << "Base<int> : " << one.item  << std::endl ;	
}


void r_Base (Base<double>one , double a)
{
	one.item = a ;
	std::cout << "Base<double> : " << one.item << std::endl ;
}

