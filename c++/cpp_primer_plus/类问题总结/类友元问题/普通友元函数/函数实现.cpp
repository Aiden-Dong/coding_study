# include <iostream>
# include "friends.h"

int Base::a = 10 ;

void Base::show_base () const 
{
	std::cout << "a = " << a << std::endl ;
	std::cout << "c = " << c << std::endl ;
}

Base::Base (int j) : c(j) {}

void show_friend ()
{
	std::cout << "a = " << Base::a << std::endl; // 此处友元成员函数访问静态类成员时 要使用作用域解析运算符 
}