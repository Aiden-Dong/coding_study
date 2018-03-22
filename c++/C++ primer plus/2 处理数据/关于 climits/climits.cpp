# include <iostream>
# include <climits>

int main (void)
{
	using namespace std;

	int n_max = INT_MAX;
	int n_bit = sizeof(int);

	cout << "关于 int 型变量的最值与计算机字长问题"
		<< endl;
	cout << endl;
	cout << "int 型变量的最大值为 : "
		<< n_max << endl << endl;
	cout << "int 型变量所占的位数为 : "
		<< n_bit << endl << endl;
	
	char ch;
	cout <<"请输入 enter键 来结束程序" << endl;

	cin.get (ch);
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
关于 int 型变量的最值与计算机字长问题

int 型变量的最大值为 : 2147483647

请输入 enter键 来结束程序

Press any key to continue
============================
*/