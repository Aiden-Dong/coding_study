# include <iostream>
# include <fstream>

int main ()
{
	using namespace std ;
	char * str = new char [20] ;

	ofstream finout ;

	finout.open ("name.txt" ,ios_base::out) ;

	if (!finout.is_open ())
	{
		cerr << "error to open it !!" << endl ;
		exit (-1) ;
	}

	int i = 0 ;
	while (i ++ != 20)
		finout.put ('F') ;
	i = 0 ;
	while (i ++ != 20)
		finout.put ('V') ;
	i = 0 ;
	while (i ++ != 20)
		finout.put ('H') ;
	i = 0 ;
	while (i ++ != 20)
		finout.put ('K') ;

	finout.close () ;

	ifstream fin ("name.txt" , ios_base::in) ;

	if (!fin.is_open ())
	{
		cerr << "error to open it !!" << endl ;
		exit (-1) ;
	}

	fin.seekg (0) ;
	fin.get (str, 20) ;
	cout << str << endl ;

	fin.seekg (20);
	fin.get (str, 20) ;
	cout << str << endl ;
	fin.seekg (40);
	fin.get (str, 20) ;
	cout << str << endl ;
	

	return 0 ;
}
