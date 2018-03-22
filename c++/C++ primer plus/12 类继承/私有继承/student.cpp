# include <iostream>
# include <string>
# include "student.h"

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl;
	using std::string ;

	string str;

	cout << "请输入你的姓名 : " << endl ;

	cin >> str ;

	Student one (str) ;

	one.write ();
	one.show () ;

	return 0 ;
}

/*
在 VC++ 6.0 中的输出结果是 ：
==================================
请输入你的姓名 :
saligia
录入成绩 :
23
12
41
53
21
姓名 : saligia
语文 : 23
数学 : 12
英语 : 41
生物 : 53
物理 : 21
释放空间 : saligia
Press any key to continue
==================================
*/