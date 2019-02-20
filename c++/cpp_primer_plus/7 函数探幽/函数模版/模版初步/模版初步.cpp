# include <iostream>

template <typename id>
void Swap (id & x , id & y);
int main ()
{
	using namespace std ;

	int a = 3, b = 4;
	double  c = 2 , d = 3;
	
	Swap ( a , b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Swap ( c , d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	return 0 ;
}

template <typename id>
void Swap (id & x , id & y)
{
	id t ;
	t = x;
	x = y ; 
	y = t ;
}

/*
在 VC++ 6.0 中的输出结果是 ：
=============================
a = 4
b = 3
c = 3
d = 2
Press any key to continue

=============================
*/
