# ifndef ARRAYTP_H_
# define ARRAYTP_H_

# include <iostream>
# include <cstdlib>

template <class T , int n>    // int n 为 表达式参数或非类型参数
class ArrayTP
{
private:
	T ar [n] ; // n 必须为常量表达式且不可更改
public:
	ArrayTP () {}
	explicit ArrayTP (const T & v) ;
	virtual T & operator [] (int i) ; 
	virtual T operator [] (int i) const ;
};

template <class T , int n>
ArrayTP<T,n>::ArrayTP (const T & v)    // 在模版中 ， ArrayTP 不是模版名 ArrayTP<T,n> 才是模版名称
{									   // 因为不同的参数生成不同的类声明
	for (int i = 0 ; i < n ; i++)
		ar[i] = v ;
}

template<class T , int n>
T& ArrayTP<T,n>::operator [] (int i)     // 传递引用的意义在于要进行对原变量的赋值工作 ；
{
	if (i < 0 || i >= n)
		exit (-1);
	return ar[i] ;
}

template<class T , int n> 
T ArrayTP<T,n>::operator [] (int i) const   // 而 const 在于要进行对其他数据的赋值 （传递到外部）
{
	if (i < 0 || i >= n)
		exit (-1);
	return ar[i] ;

}

# endif 
