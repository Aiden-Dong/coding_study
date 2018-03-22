# ifndef FRIENDS_H_
# define FRIENDS_H_

template <typename T>
class Base
{
private:
	int a;
	T b;
	
public:

	static int c;
	Base(int aa, T bb) :a(aa), b(bb)
	{
		c++;
	}

	friend Base<T> operator+ (Base<T> &a, Base<T> &b);



};
# endif