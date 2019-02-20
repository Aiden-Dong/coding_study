# include <iostream>

int main (void)
{
	using namespace std;

	int a[10];
	int i;

	for ( i = 0 ; i < 5 ; i ++)
	{
		cout << "请输入数据 :" << endl;

		while (!(cin >> a[i]))
		{
			cin.clear ();
			while (cin.get() != '\n');
			cout << "请重新输入" << endl;
			continue;
		}
	}
	cout << endl;
	for ( i = 0 ; i < 5 ; i ++)
		cout << "a [" << i << "] = " << a[i] << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入数据 :
k
请重新输入
12
请输入数据 :
34
请输入数据 :
j
请重新输入
45
请输入数据 :
90
请输入数据 :

887

a [0] = 12
a [1] = 34
a [2] = 45
a [3] = 90
a [4] = 887
Press any key to continue
===========================
*/