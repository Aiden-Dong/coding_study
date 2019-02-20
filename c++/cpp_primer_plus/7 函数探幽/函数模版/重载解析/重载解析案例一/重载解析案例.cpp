# include <iostream>

struct debts{
	char name [50];
	double amount;
} ;

template <typename T>
void show (T arr[] , int n);

template <typename T>
void show (T *array[] , int n);

int main ()
{
	using namespace std;

	int things[6] = {13 , 32 , 21 , 52 , 41 , 36};

	debts mr[3] = {
		{"dfjashf" ,2400.2},
		{"ewrywerty" , 5132.4},
		{"ewtyhsdf" , 46534.21}
	};

	double *pd[3];

	for (int i = 0 ; i < 3 ; i++)
		pd[i] = & mr[i].amount;

	cout << "显示的内容如下: " << endl;
	show (things , 6);
	cout << "显示的内容如下: " << endl;
	show (pd , 3);


	return 0;
}

template <typename T>
void show (T arr[] , int n)
{
	using namespace std ;

	cout << "template A" << endl;

	for (int i = 0 ; i < n ; i ++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}
template <typename T>
void show (T *array[] , int n)
{
	cout << "template B" << endl;

	for (int i = 0 ; i < n ; i ++)
		cout << *arr[i] << "  ";

	cout << endl << endl;
}