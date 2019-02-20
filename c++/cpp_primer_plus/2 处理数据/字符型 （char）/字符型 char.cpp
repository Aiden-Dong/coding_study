# include <iostream>

int main ( void )
{
	using namespace std;

	char ch1 ;
	//char16_t ch2;
	wchar_t ch2 = L'p';

	cout << "please enter any char :" << endl;

	cin >> ch1;

	cout << "ch1 = " << ch1 << endl;
	wcout << L"ch2 = " << ch2 << endl;

	cout << "wchar 所占的字节数为 : " << sizeof (ch2) << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
please enter any char :

d
ch1 = d
ch2 = 112
wchar 所占的字节数为 : 2
Press any key to continue
=============================
*/