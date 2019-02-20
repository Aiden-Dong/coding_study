# include <iostream>

int main ()
{
	using namespace std;

	char * p[3] = {"Hellow world" , "I will hold on" , "thank you"};

	cout << p[1] << endl;

	cout << *p[0] << endl;

	cout <<int( &(*p[0])) << endl;

	cout <<int ( &(*p[1])) << endl;

	cout <<int ( &(*p[2])) << endl;

	cout <<int( & p[0]) << endl;

	cout <<int( & p[1] )<< endl;

	cout <<int( & p[2]) << endl;

	cout <<int(  p[0]) << endl;

	cout <<int(  p[1] )<< endl;

	cout <<int( p[2]) << endl;

	cout <<int ( p )<< endl;


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==================================
I will hold on
H
4649020
4649000
4648988

p[0] 1244988
p[1] 1244992
p[2] 1244996

4649020
4649000
4648988

p 的地址1244988

Press any key to continue
================================
*/