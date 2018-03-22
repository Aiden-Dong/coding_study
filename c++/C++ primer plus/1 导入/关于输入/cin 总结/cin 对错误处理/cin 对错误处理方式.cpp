# include <iostream>

int main (void)
{
	using namespace std;
	
	int a;
	char ch;
	
	cout << "请输入 :" << endl;
	cin >> a;
	cout << "a = " << a <<endl;

	cin.clear ();             //-----------如果去掉 则出错
	
	cout << "请输入 :" << endl;
	cin >> ch;
	cout << "ch = " << ch << endl;
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
================================
请输入 :
s
a = -858993460
请输入 :
ch = s
Press any key to continue
================================
*/