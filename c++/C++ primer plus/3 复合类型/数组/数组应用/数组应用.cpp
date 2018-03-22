# include <iostream>
//# include <cstring>

int main (void)
{
	using namespace std;

	char str1[5];
	char str2[15];
	char ch;
	int t ; 

	cout << "请输入一组字符串 :";

	cin.getline (str1 , 5);

	cout << str1 << endl;

	cin.clear ();//------------------------------???????????????????????/

	cout << "请输入第二组字符串 :";
	cin.getline (str2 , 15);
	cout << str2 <<endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入一组字符串 :hellow world!!!
hell
请输入第二组字符串 :ow world!!!
Press any key to continue
===========================
*/