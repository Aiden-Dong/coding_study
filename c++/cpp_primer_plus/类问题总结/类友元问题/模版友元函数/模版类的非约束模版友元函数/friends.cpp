# include <iostream>

template <typename T>
class Friends
{
private:
	T item ;
public:
	Friends (T a) : item(a){}

	void show ()
	{
		std::cout << item << std::endl ;
	}

	template <typename B>
		friend void show_run (Friends<B> &s , B gil)	// 模版类的非约束模版友元函数可以直接访问 对象数据
	{						        	// 真正具有遍历此模版所有实例的特性 ；
	
		s.item =  gil ;
	}


} ;

int main ()
{
	Friends<int> one (10) ;

	one.show () ;

	show_run (one , 13) ;
	one.show () ;



	return 0 ;
}