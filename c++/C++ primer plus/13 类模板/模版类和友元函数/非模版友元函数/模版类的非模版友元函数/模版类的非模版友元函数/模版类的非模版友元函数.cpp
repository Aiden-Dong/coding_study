# include <iostream>


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
	Base() : a(0), b(0)
	{
		c++;
	}

	friend Base<T> operator+ (Base<T> &a, Base<T> &b)
	{
		Base<T> one;

		one.a = a.a + b.a;
		one.b = a.b + b.b;

		return one;
	}

};
template <typename T>
int Base<T>::c = 0;

int main()
{
	using std::cout;
	using std::endl;

	Base<int> first (1 , 4);
	Base<int>second(2, 8);

	cout << Base<int>::c << endl;
	Base<int> third;

	third = first + second;

	cout << Base<int>::c << endl;

	system("pause");
	return 0;
}