# include <iostream>
# include <string>
# include "inherite.h"

Base::Base (char * a1 , char*b1 , int g )
{
	name = a1 ;
	card = b1 ;
	garde = g ;
}

void Base::show_massage()const
{
	std::cout << "name : " << name << std::endl ;
	std::cout << "card : " << card << std::endl ;
	std::cout << "garde : " << garde << std::endl ;
}
int Base::r_garde ()const 
{
	return garde ;
}

Devire::Devire (Base one , int b ) : Base(one) , age(b)
{
	
}
Devire::Devire (char* a1 , char* a2 , int a , int b) : Base (a1 , a2 , a) , age(b)
{
}

void Devire::show_massage ()const
{
	Base::show_massage () ;
	std::cout << "age : " << age << std::endl ;
}

int Devire::r_age () const 
{
	return age ;
}


