# include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

template <typename T>    
class One
{
private:
	T item ;
	static int c ;
public :
	One (const T & s) : item (s) {c++;}
	~One () {c-- ;}

	friend void reports (One<T> &s);   // 调用了次类模版的引用？？？？？
	friend void counts<One<T> > () ;
};

template <typename T>            // 静态变量初始化也要使用此开头
int One<T>::c = 0 ;		

template <typename T>
void reports (One<T> & s)     
{
	cout<<s.item << endl ;
}
template <typename T>
void counts () 
{
	cout << "长度 : " << sizeof (One<T>) << "  "
		<< "ct = " << One<T>::c << endl ;
}

int main ()
{

	counts<int> () ;
	One <int> first(6) ;

	reports (first);     // 调用了 int 类的 模板友元

	counts<int> () ;     // 调用 int 型的 友元模板  

	return 0 ;
}
