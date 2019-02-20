# include <iostream>
# include <fstream>
# include <cstdlib>
# include <cstring>
# include <iomanip>

struct plan{
	char name [12] ;
	int a ;
	int b  ;
};

int main ()
{
	using namespace std ;
	
	plan p1 ;

	strcpy (p1.name ,"saligia" ) ;
	p1.a =2 ;
	p1.b = 4 ;

	ofstream fout ;
	fout.open ("name.dat" , ios_base::out|ios_base::binary) ;

	

	if (!fout.is_open ())
	{
		cerr << "Can't to open it !!! " << endl ;
		exit (-1) ;
	}
	fout.write ((char*) &p1 , sizeof p1 );				// 写入文件

	fout.close () ;

	plan p2 ;

	ifstream fin ("name.dat" , ios_base::in|ios_base::binary);

	if (!fin.is_open ())
	{
		cerr << "Can't to open it !!! " << endl ;
		exit (-1) ;
	}
	fin.read ((char *) & p2 , sizeof p2) ;			// 读取文件内容

	cout << p2.name << std::setw(6) << p2.a << std::setw(6) << p2.b << endl ;

	return 0 ;
}