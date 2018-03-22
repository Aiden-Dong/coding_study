# include <iostream>

int a = 20;

void h_shu (void);

int main ()
{
	using namespace std;

	for (int i = 0 ; i <= 100 ; i ++)
		a++;

	h_shu ();

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
now!!!
121
Press any key to continue
===========================
*/
