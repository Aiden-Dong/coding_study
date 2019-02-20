# include <iostream>

int main (void)
{
	using namespace std;

	int a;

	cout << "请输入一组数据 :" << endl;
start:
	cin >> a;

	switch ( a )
	{
	case 1:
		cout << "1 < 0\n";
		break;
	case 2:
		cout << "2" << endl;
		break;
	case 3:
		cout << "3" << endl;
		break;
	default:
		cout << "请重新输入 :" << endl;
		goto start;
	}

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入一组数据 :
6
请重新输入 :
5
请重新输入 :
4
请重新输入 :
3
3
Press any key to continue
=============================
*/