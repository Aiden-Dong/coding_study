#include <iostream>
# include <cmath>
# include <iomanip>

int main ()
{
	using namespace std ;

	int p;

	cout << "请输入要查找的范围 : " << endl ;

	int n ;

	cin >> n ;

	if (n < 3)
		exit(0);

	
	cout <<endl<< "========================================================"<< endl;
	cout << setw(6) << setfill ('=')<< 2 ;

	for (int i = 3 ; i <= n ; i+=2)
	{
		p = sqrt(i)+1;

		for (int r = 3 ; r <  p ; r=r+2)
			if (i%r == 0)
				break;

		if (r >= p)
			cout << setw(6) << setfill('=') << i ;
	}
	cout << endl << "========================================================"<< endl;

	return 0 ;
}