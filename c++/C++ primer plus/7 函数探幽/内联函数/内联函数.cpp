# include <iostream>

inline double square ( double x ) { return x * x ;} // 内联函数关键字 inline 使用结构较小的函数；减少调用时间；

int main (void)
{
	using namespace std;

	double x;

	cin >> x;

	cout << "x*x = " << square(x) << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
34.5
x*x = 1190.25
Press any key to continue
==============================
*/