# include <iostream>

using std::cout ;
using std::endl ;

template <typename T>
class One
{
private:
	T item ;
public:
	One (const T & s) : item (s) {}
	template <typename C , typename D> friend void show2 (One<C> & c , One<D> & d);   // 非约束模板友元函数的声明方式 
};																			// 对于非约束友元 ， 友元模板类型参数与模板类型参数
																			// 是不同的
template <typename C , typename D> void show2 (One<C> & c , One<D> & d)
{																			//模板友元函数访问类时候要记得使用准确的---类名
	cout << c.item << "  " << d.item << endl ; 
}

int main ()
{
	One <int> first (10) ; 
	One <int>secound (20) ;
	One <double> third (10.5) ;

	cout << "first , secound : " ;
	show2 (first , secound) ;

	cout << "first , third : " ;
	show2 (first , third) ;


	return 0 ;
}