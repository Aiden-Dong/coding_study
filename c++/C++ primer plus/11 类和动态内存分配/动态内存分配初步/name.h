# ifndef NAME_H_
# define NAME_H_
# include <iostream>

class Stringbad
{
private:
	char * str;
	int len;
	static int and;
public:
	Stringbad (const char *s );
	Stringbad ();
	~Stringbad ();
	friend std::ostream & operator << ( std::ostream & os , const Stringbad & st );
};
# endif