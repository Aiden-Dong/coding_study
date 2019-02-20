# ifndef NAME_H_
# define NAME_H_

# include <iostream>

using std::ostream;
using std::istream;

class String
{
private:
	char * str;
	int len;
	static and;
   // 常量的另一种表达
public:
	String ();
	String (const char * s);
	String (const String & s);
	~String ();

	int length () {return len;}

	String & operator = (const String & s);
	String & operator = (const char * s);
	char & operator [] (int i);
	const char & operator [] (int i) const ;
	friend bool operator < (const String & s1 , const String & s2);
	friend bool operator > (const String & s1 , const String & s2);
	friend bool operator == (const String & s1 , const String & s2);
	friend ostream & operator << (ostream & s1 , const String & s2);
	friend istream & operator >> (istream & s1 ,  String & s2);

	static int How ();
};
# endif

