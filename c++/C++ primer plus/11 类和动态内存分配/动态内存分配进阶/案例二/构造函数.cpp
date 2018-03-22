

# include <cstring>
# include <iostream>
# include "name.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

int String::and = 0 ;

String::String()
{
	len = 4 ;
	str = new char [1];
	str[0] = '\0';
	and ++;
	cout << and << " 创建一个对象实例 :" << str << endl;
}

String::String (const char * s)
{
	len = strlen (s);
	str = new char [len + 1];
	strcpy (str , s);
	and ++;
	cout << and << " 创建一个对象实例 :" << str << endl;
}
String::String (const String & s)
{
	len = s.len ;
	str = new char [len + 1];
	strcpy (str , s.str );
	and++;
	cout << and << " 创建一个对象实例 :" << str << endl;
}

String::~String ()
{
	and--;
	cout << and << " 释放一个对象实例 :" << str << endl;
	delete []str;
}

String & String::operator = (const String & s)
{
	if (this == &s)
		return *this ;
	delete[]str;
	len = s.len ;
	str = new char [len + 1];
	strcpy (str , s.str );
	return *this;
}

String & String::operator = (const char * s)
{
	delete []str;
	len = strlen (s);
	str = new char [len + 1];
	strcpy (str , s);

	return *this;
}

char & String::operator [] (int i)
{
	return str[i];
}

const char & String::operator [] (int i) const
{
	return str[i];
}

bool operator < (const String & s1 , const String & s2)
{
	return (strcmp (s1.str , s2.str ) < 0);
}

bool operator > (const String & s1 , const String & s2)
{
	return s2 < s1 ;
}

bool operator == (const String & s1 , const String & s2)
{
	return (strcmp (s1.str , s2.str ) == 0);		
}


ostream & operator << (ostream & s1 , const String & s2)
{
	s1 <<  s2.str << endl;
	return s1;
}

istream & operator >> (istream & s1 , String & s2)
{
		char temp[80];
		s1.get (temp , 80);
		if (s1)
			s2 = temp;
		else
		{
			s1.clear ();
			while (s1.get() != '\n');
		}
		while (s1 && s1.get ()!= '\n')
			continue ;

		return s1;

}
