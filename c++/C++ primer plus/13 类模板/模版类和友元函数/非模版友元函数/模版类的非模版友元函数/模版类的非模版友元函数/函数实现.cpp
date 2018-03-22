# include "friends.h"

template <typename T>
int Base<T>::c = 0;


template <typename T>
Base<T> operator+ (Base<T>&a, Base<T>&b)
{
	Base<T> one;

	one.a = a.a + b.a;
	one.b = a.b + b.b;

	return one;
}

