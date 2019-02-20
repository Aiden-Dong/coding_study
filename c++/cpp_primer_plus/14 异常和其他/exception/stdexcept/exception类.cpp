# include <stdexcept>
# include <iostream>
# include <cmath>

int main ()
{
	using namespace std ;

	int a[4] = {0} ;
	int b ;
	float j ;

	try {
		cin >> b ;
		cout << a[b] << endl ;
		cout << asin(b) ;
		cin >> j ;
	}
	catch (logic_error & p)
	{
		cout << "error to input !!" << endl ;
		
	}
	catch (runtime_error & h)
	{
		cout << h.what ();
		cout << "bybe" << endl ;
	}

	return 0 ;
}