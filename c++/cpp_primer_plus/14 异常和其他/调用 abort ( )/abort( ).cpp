# include <iostream>

double average (int a , int b ) ;

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;

	int a ,  b ;
	double c ;

	cin >> a >> b ;
	
	if ( b == 0 )
	{
		cout << "error" << endl ;
		abort () ;           // 调用异常
		
	}

	c = average (a , b) ;

	cout << c << endl ;

	
	return 0;
}
double average (int a , int b ) 
{
	return ((double)a/b) ;
}