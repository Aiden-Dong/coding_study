# include <iostream>

int main (void)
{
	using namespace std;

	char * str = new char [20];

	cout << "请输入字符串 : " << endl;

	cin.getline ( str , 20 );

	cout << "str = " << str << endl ;

	delete str;

	char * str1;

	cout << "请输入字符串长度 : " << endl;
	
	int n;

	cin >> n;
	cin.get ();

	str1 = new char [n];                        // new 分配的内存块 也可为变量

	//cout << "str1 的长度为 : " << sizeof(str1) << endl;

	cout << "请输入字符串 : " << endl;

	cin.getline ( str1 , n );                     // cin.getline () 中的 n 可以为变量

	cout << "str1 = " << str1 << endl;

	delete str1;

	return 0; 
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
请输入字符串 :
hellow world!!
str = hellow world!!
请输入字符串长度 :
10
请输入字符串 :
qwertyuiop
str1 = qwertyuio
Press any key to continue
==============================
*/