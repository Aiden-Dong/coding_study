# include <iostream>
# include "cases.h"
# include <cstring>

using std::cout ;
using std::endl ;

Case::Case ()
{
	strcpy (name , "No name") ;
	strcpy (Card , "0000000000") ;
	age = 0 ;
}

Case::Case (char *a , char *c , int b) 
{
	strcpy (name , a) ;
	strcpy (Card , c) ;
	age = b ;
}

bool Case::operator < (const Case & ex)
{
	if (strcmp (Card , ex.Card) <= 0)
		return true ;
	return false ;
}

bool Case::operator > (const Case & ex)
{
	if (strcmp (Card , ex.Card) >= 0)
		return true ;
	return false ;
}

std::ostream & operator << (std::ostream & Os , Case j)
{
	Os << "name : " << j.name << endl ;
	Os << "Card : " << j.Card << endl ;
	Os << "age : " << j.age << endl ;

	return Os ;
}

void Case::operator= (const Case & ex)
{
	strcpy (name , ex.name) ;
	strcpy (Card , ex.Card) ;
	age = ex.age ;
}

Case & Manage::operator[] (int a)
{
	return one[a] ;
}

void Manage::sort_manage ()
{
	Case t ;

	for (int i = 0 ; i < 4 ; i++)
		for (int j = 0 ; j < 4-i ; j++)
		{
			if (one[j] > one[j+1] )
			{
				t = one[j] ;
				one[j] = one [j+1];
				one[j+1] = t ;
			}
		}
}

void Manage::show() const 
{
	int i = 0 ;

	cout << endl << "=====================================" << endl ;
	for (i = 0 ; i < 5 ; i++)
		cout << one[i] << endl ;
	cout << "=====================================" << endl ;
}