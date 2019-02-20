# include <iostream>
# include "namesp.h"

void other ();
void another ();

int main ()
{
	using debts::Debts ;
	using debts::s_debt ;

	Debts golf ;
	golf.name.fname = "Mr"; 
	golf.name.lname  = "Sajibn";
	golf.amout  = 120.0;

	s_debt (golf);
	other ();
	another ();

	return 0;

}
void other ()
{
	using std::cout ;
	using std::endl;

	using namespace debts;

	person dg ;
	dg.fname  = "Mr.";
	dg.lname  = "Samfja";

	s_person (dg);

	cout << endl;
	Debts hat[3];


	for (int i = 0 ; i < 3 ; i ++)
		g_debt (hat[i]);

	cout << "Total debts : $" << s_debts(hat,3) << endl;



}

void another ()
{
	using pers::person ;

	person one;// 
	one.fname  = "Mrs";
	one.lname ="JInmd";

	pers::s_person (one);
	std::cout << std::endl;
}