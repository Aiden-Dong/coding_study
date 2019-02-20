# include <iostream>
# include <string>

int main (void)
{
	using namespace std;

	char t;
	int i , j;

	cout << "请输入一组字符串 :" << endl;

	string worlds;
	getline ( cin , worlds );

	for ( j = 0 , i = worlds.size()-1 ; j < i; j++, i--)
	{
		t = worlds[j];
		worlds[j] = worlds[i];
		worlds[i] = t;
	}

	cout << worlds << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入一组字符串 :
Hellow world!!!!

!!!!dlrow wolleH
Press any key to continue
=============================
*/