# include <exception>  // 定义了异常类 
# include <iostream>
# include <cmath>

void hui (void);

int main ()
{
	using namespace std ;

	int a[4] = {0} ;
	int b ;
	float j ;

	set_terminate (hui);
	
	try {
		cin >> b ;
		cout << a[b] << endl ;
		cout << asin(b) ;
		cin >> j ;
	}
	catch(int d)
	{
		cout << d << endl ;
		cout << "bybe" << endl ;
	}
	return 0 ;
}
void hui (void)
{
	std::cout << "error" << std::endl ;
	exit (-1);
}