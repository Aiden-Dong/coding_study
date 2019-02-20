# include <string>

namespace pers
{

	struct person
	{
		std::string fname;
		std::string lname;
	};

	void g_person (person & a);
	void s_person (const person & a);

}

namespace debts
{
	using namespace pers;

	struct Debts
	{
		person name;
		double amout;
	};

	void g_debt(Debts & a);
	void s_debt(const Debts & b );
	double s_debts (const Debts ar[] , int n);
}