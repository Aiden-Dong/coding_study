# include <cstring>
# include "name.h"

int Stringbad::and = 0;  // 需使用作用域解析运算符
using std::cout ;
using std::endl ;

Stringbad::Stringbad ()
{
	len = 3 ;
	str = new char [len + 1];
	strcpy (str , "C++");
	and++;
	cout << and << "产生了一个新的对象 :" << str << endl ;
}

Stringbad::Stringbad (const char * s )
{
	len = strlen (s);
	str = new char [len+1];
	strcpy (str , s);
	and++;
	cout << and << "产生了一个新的对象 :" << str << endl ;
}

Stringbad::~Stringbad ()
{
	-- and;
	cout << and << "释放掉一个空间 : " << str << endl ;
	delete[]str;
}

std::ostream & operator << (std::ostream & os , const Stringbad & st)
{
	os << st.str  << endl;
	return os;
}