# include <iostream>
# include "cases.h"

int main()
{
	using std::endl ;
	using std::cout ;
	using std::cin ;

	Manage first ;

	char name1[10] ;
	char card1[15];
	int age1 ;

	for (int i = 0 ; i < 5 ; i ++)
	{
		cout << "请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--" << endl; 
		cin >> name1 ;
		cin >> card1 ;
		cin >> age1 ;
		first[i] = Case (name1 , card1 , age1);	// 只有一个参数的可以用作默认转换函数
												// 否则必须显示调用
		
	}

	first.sort_manage () ;

	first.show () ;
	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
============================
请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--
saligia
2013201890
12
请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--
wial
2018201523
13
请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--
kila
2013201420
14
请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--
file
2012201879
13
请输入你的信息 -- 姓名 -- -- 学号-- -- 年龄--
hilem
2013122031
41

=====================================
name : file
Card : 2012201879
age : 13

name : hilem
Card : 2013122031
age : 41

name : kila
Card : 2013201420
age : 14

name : saligia
Card : 2013201890
age : 12

name : wial
Card : 2018201523
age : 13

=====================================
Press any key to continue
============================
*/
