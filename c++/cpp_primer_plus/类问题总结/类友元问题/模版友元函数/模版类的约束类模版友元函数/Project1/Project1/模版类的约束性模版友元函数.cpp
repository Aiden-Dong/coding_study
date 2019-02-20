# include <iostream>

template <typename T> void counts();
template <typename T> void report(T &);

template <typename  TT>
class Base
{
private:
	int a;
	static int b; 
public :
	Base() { a = 0; b++; }
	Base(int t) :a(t) { b++; }
	~Base() {}
	friend void counts <TT>();
	friend void report<TT>(Base<TT>&bs);
};
template<typename T>
int Base<T>::b = 0;

template <typename T>
void counts()
{
	std::cout << "b =  " <<  Base<T>::b << std::endl;
}
template <typename T>
void report(Base<T>&bs)
{
	std::cout << "a = " << bs.a << std::endl; 
}

int main()
{
	using std::cout;
	using std::endl;

	Base <int> one;

	counts<int>();
	report <int>(one);

	Base<double> two;

	counts<double>();
	report <double>(two);
	system("pause");
	return 0;
}

