# include <iostream>

int main (void)
{
	using namespace std;

	char ch;

	cin >> ch;

	while (  ch != '*' )
	{
		cout << "请输入 :" << endl ;

		cout << ch << endl;

		cin >> ch;
	}

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
不能用 '\n' 作为哨兵字符
不能用 " " 作为哨兵字符

 bfa kjhn*hnk
请输入 :
b
请输入 :
f
请输入 :
a
请输入 :
k
请输入 :
j
请输入 :
h
请输入 :
n
Press any key to continue
===========================
*/