# include <iostream>
# include "name.h"

inline Stock::Stock()
{
	a = b = 0;
	c = 0.0;
}

Stock::Stock (int x , int y , double z)
{
	a = x ;
	b = y ;
	c = z ;
}

Stock::~Stock ()
{
	std::cout<< "Bybe!!" << std::endl ;
}

void Stock::s_a () const
{
	std:: cout << "a = " << a << std::endl ;
} 

void Stock::s_b () const
{
	std:: cout << "b = " << b << std::endl ;
}

void Stock::s_c () const
{
	std:: cout << "c = " << c << std::endl ;
}
void Stock::show () const
{
	s_a() ;
	s_b() ;
	s_c() ;
}

Stock operator +(const Stock & new1 , const Stock & new2 )
{
	Stock New;
	New.a  = new1.a + new2.a ;
	New.b  = new1.b + new2.b ;
	New.c  = new1.c + new2.c ;

	return New ;
}
