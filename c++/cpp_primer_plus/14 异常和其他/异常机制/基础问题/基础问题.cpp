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

	try{

		c = average (a , b) ;
	}

	catch (const char * s)	 // 接收异常 
	{
		cout << s << endl ;

		//exit (0);
	}

	cout << c << endl ;

	
	return 0;
}
double average (int a , int b ) 
{
	if (b == 2)
		throw "error ben";  // 异常为  char *s ;

	return ((double)a/b) ;
}
/*
 在 VC++6.0 的运行环境中 :
 ==============================
 6 2
error ben
-9.25596e+061
Press any key to continue
 ==============================
 */