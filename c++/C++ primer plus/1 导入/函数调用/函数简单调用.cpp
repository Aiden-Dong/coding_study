# include <iostream>

using namespace std ;

void simon ( int );

int main (void)
{
	simon (3);

	cout << "Pick an integer : ";

	int count ;
	cin >> count ;
	
	simon (count);

	cout << "Done !!"
		<<endl;

	return 0;
}

void simon ( int n )
{
	cout << "Simon says touch your toes "
		<< n
		<< " times."
		<<endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
Simon says touch your toes 3 times.
Pick an integer : 23
Simon says touch your toes 23 times.
Done !!
Press any key to continue
=================================
*/