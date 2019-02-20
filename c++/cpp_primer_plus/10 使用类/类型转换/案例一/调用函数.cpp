# include <iostream>
# include "name.h"

using std::cout;
using std::endl;

inline stock::stock()
{
	stone = left = pound = 0;
}

stock::stock (double x)
{
	stone = int (x) / STN ;
	left = int (x) % STN + x - int(x);
	pound = x;
}

stock::stock (int x , double y)
{
	stone = x ;
	left = y ;
	pound = x * STN + y;
}

stock::~stock ()
{
	cout << "Bybe!!!" << endl;
}

void stock::show_lbs ()const
{
	cout << "stone = " << stone << endl;
}
void stock::show_stn ()const
{
	cout << "pound = " << pound << endl;
}

stock::operator double ()const
{
	return pound;
}
stock::operator int ()const
{
	return int (pound +0.5);
}