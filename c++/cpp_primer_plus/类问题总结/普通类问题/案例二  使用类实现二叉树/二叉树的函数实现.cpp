# include <iostream>
# include "binarys.h"
# include <cstdlib>
# include <ctime>
# include <iomanip>


void Binary::init_binary ()
{
	for (int i = 0 ; i < 16 ; i++)
	{
		End_binary[i].p1 = NULL ;
		End_binary[i].p2 = NULL ;
		End_binary[i].a = 0 ;
	}
	for (i = 0 ; i < 8 ; i++)
	{
		forth[i].p1 = & End_binary[2*i] ;
		forth[i].p2 = & End_binary[2*i+1] ;
		forth[i].a = 0 ;
	}
	for (i = 0 ; i < 4 ; i ++)
	{
		third[i].p1  = & forth[2*i] ;
		third[i].p2  = & forth[2*i+1] ;
		third[i].a = 0 ;
	}
	for (i = 0 ; i < 2 ; i ++)
	{
		second [i].p1 = & third[2*i] ;
		second [i].p2 = & third[2*i+1] ;
		second[i].a = 0 ;
	}
		first.p1 = & second[0] ;
		first.p2 = & second[1] ;
		first.a = 0 ;
}

Binary::Binary (int a)
{
	init_binary () ;

	for (int i = 1 ; i <= a ; i ++)
		set_binary (& first) ;

}
void Binary::set_binary (PNOTE Pil)
{


	int a = rand () % 2 ;

	if (Pil->p1 != NULL)
	{

		if (a == 0)
			set_binary (Pil->p1) ;
		else 
			set_binary (Pil->p2) ;
	}
	else 
		Pil->a ++ ;


}
void Binary::show_binary () const
{
	using std::cout ;
	using std::endl ;

	for (int i = 0 ; i < 16 ; i++)
		cout << std::setw(2) << i << " : " << End_binary[i].a << endl ;
}

