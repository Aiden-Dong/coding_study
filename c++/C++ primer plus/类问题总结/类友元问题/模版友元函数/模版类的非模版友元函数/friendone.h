# ifndef FRIENDONE_H_
# define FRIENDONE_H_

template <typename T>
class Base
{
private:
	T item ;
	static int a ;
public:
	Base (T it) ;

	friend void count () ;
	friend void r_Base (Base<T> one , T a) ;
} ;

# endif 