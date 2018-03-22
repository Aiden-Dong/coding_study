# include <iostream>
# include <string>

struct String{
	std::string name ;
	int  a ;
};

int main ()
{
	using namespace std ;

	string name ;

	name = "hellow world !!!" ;

	cout << name  << endl ;

	String one ;
	one.name = "saligia" ;	// ??????
	return 0 ;
}