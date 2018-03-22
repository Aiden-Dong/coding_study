# include <iostream>
# include "name.h"

Victor::Victor ()
{
   a = b = c = 0;
}
Victor::Victor( int x , int y , int z )
{
	a = x;
	b = y;
	c = z;
}
Victor::~Victor ()
{
	std::cout << "Bye!!!" << std::endl ;
}

void Victor::c_a ()const
{
	std::cout << "a = " << a << std::endl ;
}
void Victor::c_b ()const 
{
	std::cout << "b = " << b << std::endl ;
}
void Victor::c_c ()const
{
	std::cout << "c = " << c << std::endl ;
}

Victor Victor::operator+ (const Victor & New)
{
	Victor NEW;

	NEW.a  = a + New.a ;
	NEW.b  = b + New.b  ;
	NEW.c  = c + New.c ;

	return NEW;

}