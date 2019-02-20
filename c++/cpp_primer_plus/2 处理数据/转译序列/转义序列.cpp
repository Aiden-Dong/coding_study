# include <iostream>

int main (void)
{
	using namespace std;

	cout << "\aOperation \" HyperHype\" is now actived !\n";
	cout << "Enter your agent code :__________\b\b\b\b\b\b\b\b\b\b";

	long code;

	cin >> code;

	cout << "\aYou entered " << code << ".....\n";

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
Operation " HyperHype" is now actived !
Enter your agent code :23________
You entered 23.....
Press any key to continue
=============================
*/