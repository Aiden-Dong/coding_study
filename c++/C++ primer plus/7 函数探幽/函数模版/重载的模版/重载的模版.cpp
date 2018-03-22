# include <iostream>

template <typename T>
void swap ( T &a, T &b );

template <typename T>
void swap (T &a , T &b , int n = 1);
int main ()
{
	using namespace std ;

	int a = 6 , b = 7;

	swap( a , b , 8);

	return 0 ;
}

template <typename T>
void swap ( T &a, T &b )
{
	using namespace std ;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

template <typename T>
void swap ( T &a, T &b , int n)
{
	using namespace std ;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "n = " << n << endl;
}