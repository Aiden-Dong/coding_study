# include <iostream>
# include "name.h"

using std::cout ;
using std::endl ;

student ::student (const std::string &s)
{
	name = s ;
	scorces = 0 ;
}

void student::show () const
{
	int i = scorces . size ();
	cout << "name : " << name << endl << endl;
	cout << "语文 : " << scorces [0] << endl; 
	cout << "数学 : " << scorces [1] << endl;  // 调用对象方法
}
void student::max () const
{
	cout << "最高分 : " << scorces.max() << endl ;
}

void student::min () const
{
	cout << "最低分 : " << scorces.min() << endl ;
}