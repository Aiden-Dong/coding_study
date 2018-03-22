# include <iostream>

int main ()
{
	using namespace std ; 

	for ( int x = 0 ; x < 100 ; x++)
	{
		if ( x > 0)
		{
			if (x == 10)
				break ;
		}
	}
	cout << x << endl ;

	return 0 ;
}