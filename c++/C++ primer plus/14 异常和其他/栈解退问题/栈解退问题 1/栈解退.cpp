# include <iostream>

int main ()
{
	using namespace std ;
	int a ;
	cin >> a ;

	cout << & a << endl ;

	try {

		if (a == 1)
			throw a ;		// 说明 栈解退 首先检查本栈内是否有try 块 ；如果有则不会释放栈 ！！！
	}
	catch (int &b)
	{
		cout << & b << endl ;	// 注意 地址不一样 ；
		cout << "error to input !" << endl ;
		cout << b << endl ;
	}

	return 0 ;
}
/*
在 VC++6.0 的运行环境中：
============================
1
0012FF34
0012FF2C
error to input !
1
Press any key to continue
============================
*/