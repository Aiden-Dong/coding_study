# include <iostream>

int main (void)
{
	using namespace std;
	
	int s = 101;
	int *p;

	p = &s;

	cout << "s 的地址为 : " << p << endl; // s 的显示格式 为 16 进制模式 

	cout << "s = " << * p << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
s 的地址为 : 0012FF44
s = 101
Press any key to continue
============================
*/