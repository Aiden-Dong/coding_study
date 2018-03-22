# include <iostream>
# include <iomanip>

int main ()
{
	using namespace std ;

	int a [] = {12.1 , 23.5 , 12.7 , 12.5 , 13.1 } ;	// 允许存在类型转换

	for (int i = 0 ; i < 5; i++)
	cout << std::setw (4) << a[i] ;

	cout << endl ;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
  12  23  12  12  13
Press any key to continue
============================
*/