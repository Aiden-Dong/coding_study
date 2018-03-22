# include <iostream>

int h_shu (int & rcs );
int h_shu (const int & r1 );
int h_shu (int * rcs );
int h_shu (const int * r1 ); 
//int h_shu (int rcs );
//int h_shu (const int r1 );               

int main ()
{
	using namespace std;
	int a = 5 , b = 5 ;
	const int  c = 5 , d = 5;

	cout << h_shu (a)  << endl;		// 调用了 非 const 的引用方式 	
	cout << h_shu (c)  << endl;		// 调用了 const 的引用方式
	cout << h_shu (&b) << endl;		// 调用了 非const 的指针模式
	cout << h_shu (&d) << endl;		// 调用了 const 的指针模式
	cout << h_shu (5)  << endl;		//  调用了 const 的右值引用模式

	return 0;
}
int h_shu (int & rcs )
{
	return (rcs) + 1;
}
int h_shu (const int & r1 )
{
	return (r1) ;
}
int h_shu (int * rcs )
{
	return (* rcs )+2;
}
int h_shu (const int * r1 )
{
	return (*r1)+3;
}
/*
int h_shu (int rcs )
{
	return ( rcs )+4;
}
int h_shu (const int r1 )
{
	return 0;
}
*/

/*
在 VC++ 6.0 中的输出结果是 ：
================================
6
5
7
8
5
Press any key to continue
================================
*/

