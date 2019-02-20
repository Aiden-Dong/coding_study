# include <iostream>

extern double warming;

void update (double dt);
void local ();

using namespace std;

void update (double dt)
{
	warming += dt ;

	cout << "Updating global warming to " << warming  << " degrees." << endl;

}
void local ()
{
	double warming = 0.8;

	cout << "local warming is  " << warming << " degrees." << endl;

	cout << "But global warming = " << ::warming << endl;  // 使用全局变量

}