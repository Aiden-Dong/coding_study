# include <iostream>
# include "inherite.h"

int main ()
{
	using std::cout ;
	using std::endl ;

	Devire one ("saligia" , "2013201890" , 60 , 20) ;

	Base & pl = one ;	// 基类指针可以指向派生类对象
	Base * ji =  &one ;

	ji->show_massage () ;	//与下面引用不同 
	cout << endl ;

	one.show_massage () ;// 如果不是虚函数 则使用引用还是会调用引用类的函数
	cout << endl ;
	one.Base::show_massage () ;

	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
==========================
name : saligia
card : 2013201890
garde : 60
age : 20

name : saligia
card : 2013201890
garde : 60
Press any key to continue
==========================
*/