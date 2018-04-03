#include <iostream>

int main ()
{
	using namespace std ;

	cout << "请输入要查找的范围 : " << endl ;

	int n ;

	cin >> n ;

	if (n < 2)
		exit(0);
	cout <<endl<< "========================================================"<< endl;
	for (int i = 2 ; i <= n ; i++)
	{
		for (int r = 2 ; r < i ; r++)
			if (i%r == 0)
				break;
		if (r == i)
			cout << i << endl;
	}
	cout <<endl<< "========================================================"<< endl;

	return 0 ;
}