# include <iostream>
# include <new>

int main ()
{
	using namespace std;

	char str[45] = "Hellow world and I will hold on !!!";
	double * p = new (str) double ;

	cout << str << "   " << int(str) << endl;
	cout << p << endl;

	p[1] = 25.234;


	cout <<  str << "   " << int(str) << endl;
	cout << p << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
Hellow world and I will hold on !!!   1244952
0012FF18
Hellow w朇媗?9@ I will hold on !!!   1244952
0012FF18
Press any key to continue
============================
*/