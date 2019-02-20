//  倒叙输出字符串
# include <iostream>
# include <string>

int main (void)
{
	using namespace std;

	string worlds;
	cout << "请输入一组字符串 :";
	getline ( cin , worlds );

	for ( int i = worlds.size ()-1 ; i >= 0 ; i-- )
	{
		cout << worlds[i];
	}
	cout << "\nBye\n";

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入一组字符串 :Hellow world!!!!

!!!!dlrow wolleH
 Bye
Press any key to continue
=============================
*/
