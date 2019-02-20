# include <iostream>

int main (void)
{
	using namespace std;
	
	char str1[10] , str2[10] , ch1, ch2,ch3,ch4;
	int t ,a ;

	cout << "请输入 :" << endl;
	cin.get (str1 , 5 );
	cout << "str1 = " << str1 << endl;

	cout << "请输入 :" << endl;
	cin >> t;
	cout << "t  = " << t << endl;

	cin.clear ();                //----------------如果没有 cin.clear(),将出现错误；

	cout << "请输入 :" << endl;
	cin >> ch2;
	cout << "ch2 = " << ch2 << endl;

	cout << "请输入 :" << endl;
	cin.get (ch1);
	cout << "ch1 = " <<int( ch1) << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入 :
hello
str1 = hell
请输入 :
t  = -858993460
请输入 :
ch1 = 111
Press any key to continue
=============================
*/
