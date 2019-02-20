# include <iostream>
# include <string>
# include <cstring>

int main (void)
{
	using namespace std;
	
	string str1 ;
	char str2[20] , str3 [20];

	cout <<"str1 = " << sizeof (str1) <<endl;

	cout << "请输入 :" << endl;
	cin >> str1 ;
	cout <<"str1 = " << str1 <<endl;
	cout <<"str1 = " << str1.size() <<endl;
	cout <<"str1 = " << sizeof (str1) <<endl;

	cin.get () ;
	
	cout << "请输入 :" << endl;
	cin.getline ( str2 , 20 );
	cout <<"str2 = " << str2 <<endl;
	cout <<"str2 = " << sizeof(str2) <<endl;

	cout << "请输入 :" << endl;
	cin.getline ( str3 , 20 );
	cout <<"str3 = " << str3 <<endl;
	cout <<"str3 = " << sizeof(str3) <<endl;
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
str1 = 0
请输入 :
hellow world!!!!!

str1 = hellow world!!!!!
str1 = 17
请输入 :
str2 =
str2 = 20
请输入 :
hellow
str3 = hellow
str3 = 20
Press any key to continue
============================
*/