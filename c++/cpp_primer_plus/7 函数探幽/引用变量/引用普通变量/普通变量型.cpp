# include <iostream>

void squrt (int &a ,int &b );      // & 符号再次是声明引用
int main ()
{
	using namespace std;

	int a ;
	int b;

	cout << "请输入要转换的值 : " << endl;

	cin >> a;
	cin >> b;
	squrt (a,b);                    // 引用 主要用作函数中 ， 是对原型进行操作 
									// 类似与指针
	cout << "a = " << a << endl ;
	cout << "b = " << b << endl ;

	return 0;
}
void squrt (int &a , int &b )    //此处只能用 不可用非左值
{
	int t;                      // 如果想使用非左值 则可使用 const 这样 如果是非左值传递  则会按值传递 
	t = a; 
	a = b;
	b = t;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
请输入要转换的值 :
34 5
a = 5
b = 34
Press any key to continue
===============================
*/