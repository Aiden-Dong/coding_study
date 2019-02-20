# include <iostream>
# include "name.h"
# include <string>
int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;
	using std::string ;

	double grade [2] ;
	string name ;

	cout << "请输入你的姓名 : " << endl ;
	cin >> name ;
	cout << "请输入你的成绩 : " << endl ;
	
	for (int i = 0 ; i < 2 ; i++)
		cin >> grade[i] ;

	student one (name , grade , 2);
	//student two ;

	//two.show () ;

	one.show() ;
	one.max () ;
	one.min () ;

	return 0 ;

}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入你的姓名 :
saligia
请输入你的成绩 :
46.2
29.1
name : saligia

语文 : 46.2
数学 : 29.1
最高分 : 46.2
最低分 : 29.1
Press any key to continue
===========================
*/