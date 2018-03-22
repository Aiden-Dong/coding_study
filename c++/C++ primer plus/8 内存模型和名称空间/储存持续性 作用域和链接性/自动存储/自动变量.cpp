# include <iostream>

int* h_shu (void);

int main ()
{
	using namespace std;

	int a = 1 , b = 2 , c = 3;
	int *p = &c;

	cout << "a = " << a << endl <<"b = " << b << endl << "c = " << c << endl;
	cout << "a = " <<(int) &a << endl <<"b = " << (int) &b << endl << "c = " << (int) &c << endl;


	p = h_shu ();

	cout << "a = " << a << endl <<"b = " << b << endl << "c = " << c << endl;
	cout << "a = " <<(int) &a << endl <<"b = " << (int) &b << endl << "c = " << (int) &c << endl;

	cout << "* (p) = " << * (p) <<"   " << (int) p << endl;

	return 0;
}
int* h_shu (void)
{
	using namespace std;
	int a = 5 , b = 10 , c = 15;

	cout << "a = " << a << endl <<"b = " << b << endl << "c = " << c << endl;
	cout << "a = " << (int) &a << endl <<"b = " << (int) &b << endl << "c = " << (int) &c << endl;

	return &a;
}