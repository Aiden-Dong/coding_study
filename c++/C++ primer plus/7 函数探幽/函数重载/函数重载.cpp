# include <iostream>

unsigned long left ( unsigned long num , unsigned ct );
char * left ( const char * str , int n = 1 );

int main ()
{
	using namespace std;
	
	char * trip = "Hellow world !!!";
	unsigned long n = 123456789;

	char * temp;

	for ( int i = 1 ; i < 10 ; i++)
	{
		cout << left (n , i ) << endl; 
		temp = left ( trip , i );
		cout << temp << endl;
		delete [] temp ;
	}

	return 0;
}

unsigned long left ( unsigned long num , unsigned ct )
{
	unsigned digits = 1; 
	unsigned long n = num ;

	if ( ct == 0 || num == 0)
		return 0;

	while (n/=10)
		digits++;

	if (digits > ct )
	{  
		ct = digits - ct ;	

		while (ct --)
			num /= 10;
	}

	return num;

}

char * left ( const char * str , int n  )
{
	if (n < 0)
		n = 0;

	char * p = new char [n+1];

	for (int i = 0 ; i < n ; i++)
		p[i] = str[i];

	p[i] = '\0';

	return p;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
1
H
12
He
123
Hel
1234
Hell
12345
Hello
123456
Hellow
1234567
Hellow
12345678
Hellow w
123456789
Hellow wo
Press any key to continue
=============================
*/