# include <iostream>

int main (void)
{
	using namespace std;

	char str[10], ch1 , ch2 , ch3;
	int a1 , a2 , a3;

	cout << "请输入 :" << endl;

	cin.get ( str , 6 );
	cout << "str = " << str <<endl;

	cout << "请输入 :" << endl;
	cin >> ch1 ;
	cout << "ch1 = " << ch1 << endl;

	cout << "请输入 :" << endl;
	cin >> ch2 ;
	cout << "ch2 = " << ch2 << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
================================
请输入 :
hellow!
str = hello
请输入 :
ch1 = w
请输入 :
ch2 = !
Press any key to continue
================================
*/