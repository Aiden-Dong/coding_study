# include <iostream>
# include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	using std::endl;

	void g_person (person & a)
	{
		cout << "输入你的姓 :" << endl;
		cin >> a.fname ;
		cout << "输入你的名: " << endl;
		cin >> a.lname ;
	}

	void s_person (const person & a)
	{
		cout << a.fname  << "  " << a.lname  << endl;
	}
}
namespace debtss
{

	using namespace pers ;

	void g_debts(Debts & a)
	{
		g_person (a.name );
		cout << "输入 Debt :" << endl;
		cin >> a.amout ;
	}

	void s_debt(const Debts & b )
	{
		s_person (b.name );
		cout << ": $" << b.amout  << endl;
	}
	double s_debts (const Debts ar[] , int n)
	{
		double total = 0;

		for (int i = 0 ; i <n ; i ++)
		{
			total += ar[i].amout ;
		}
		return total;
	}

}