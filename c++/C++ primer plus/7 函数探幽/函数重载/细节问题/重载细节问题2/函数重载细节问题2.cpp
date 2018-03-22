# include <iostream>

void h_shu ( int a , int b );
//void h_shu (long a , long b );
void h_shu ( int * a , int * b );

int main ()
{
	using namespace std ;
	double a = 1.2 , b = 4.3;

	h_shu ( a , b );

	return 0;
}
void h_shu ( int a , int b )
{
	std::cout << "a = " << a << std::endl;
}
void h_shu ( int * a , int * b )
{
	std::cout << "a = " << a << std::endl;
}
/*void h_shu (long a , long b )
{
	std::cout << "a+1 = " << a << std::endl;
}*/