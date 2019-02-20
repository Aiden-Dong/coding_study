# include <iostream>

int main (void)
{
	using namespace std;

	int count , variable;

	cout << "please input a numble!!"<<endl;
	cin >>  count;               //----------------cin 与 c 中的 scanf 类似
	cout << "您输入的为 "
		<< count << endl;
	cout << "请继续输入"<<endl;
	cin >> variable;
	cout << "variable = "
		<< variable << endl;


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
please input a numble!!
23
您输入的为 23
请继续输入
42
variable = 42
Press any key to continue
============================
please input a numble!!
m23
您输入的为 -858993460
请继续输入
variable = -858993460
Press any key to continue
===========================
*/