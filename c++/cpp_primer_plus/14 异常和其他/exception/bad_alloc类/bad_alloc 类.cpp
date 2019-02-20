# include <iostream>
# include <new>

int main ()
{
	using namespace std ;
	int * p ;

	try {
		p = new int [9900000999999999999] ;
	}
	catch (bad_alloc & a)
	{
		cout << "cant to run it " << endl ;
		cout << a.what () << endl ;
	}

	delete [] p ;

	return 0 ;
}