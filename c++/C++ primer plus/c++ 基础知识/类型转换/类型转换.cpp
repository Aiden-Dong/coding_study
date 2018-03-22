# include <iostream>

void x_gai (const int *p) ;

int main ()
{
	using namespace std ;

	int a = 7 ;
	double b = 1.6782 ;
	int v = static_cast<int>(b) ;

	cout << v << endl ;

	x_gai (&a);

	cout << a << endl ;

	return 0 ;
}
void x_gai (const int *p) 
{
	int  *q ;
	q = const_cast<int*  > (p) ;  // 自身不可修改 但返回一个可修改的指针 ；// 不可使用引用   ？？？

	 *q = 12 ;

}