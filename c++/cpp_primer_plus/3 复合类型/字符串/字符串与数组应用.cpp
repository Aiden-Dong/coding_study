# include <iostream>

int main (void)
{
	using namespace std;

	cout << "请输入一组数据 ：";
	int date;
	cin >> date ;

	cin.get();

	cout << "请输入一组字符串 :" <<endl;
	char str [20];
	cin.getline ( str , 20);
	cout << "str = " << str << endl;

	cin.get ();

	cout <<"date = "<<  date << endl;
	cout <<"str = " << str << endl;


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入一组数据 ：1994
请输入一组字符串 :
hellow world
str = hellow world
23
date = 1994
str = hellow world
Press any key to continue
============================
*/