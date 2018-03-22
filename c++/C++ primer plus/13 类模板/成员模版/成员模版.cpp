# include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

template <typename T>
class bate
{
private:
	template <typename V>
	class hold
	{
	private:
		V val ;
	public:
		hold (V v = 0) : val (v) {}
		void show() const {cout << val << endl ;}
		V Value () const {return val ;}
	};

	hold <T> q ;
	hold <int> n;

public :
	bate (T t , int i ) : q (t) , n (i) {}
	template <typename U>
		U blab (U u , T t){return (n.Value() + q.Value() ) * u / t ; }
	void show () const {q.show() ; n.show ;}
};

int main ()
{
	bate <double> guy (3.5 , 3) ; 
	cout << "当 guy 声明为 double 时候 : "<< endl ;
	guy.show () ;
	
	cout << "调用类中的函数 blab () 时候 : "<< endl ;
	cout << guy.blab (10 , 2.3) << endl ;
	cout << guy.blab (10.0 , 2.3) << endl ;

	return 0;
}
/*
也可以将模版类的定义放在类外 ：

	如

	template <typename T>
	class bate
	{
	private:
		template <typename V>
		class hold;

		hold <T> q ;
		hold <int> n;

	public :
		bate (T t , int i ) : q (t) , n (i) {}
		template <typename U>
			U blab (U u , T t) ;
		void show () const {q.show() ; n.show ;}
	};

  template <typename T>
	template <typename V>
		class bate<T>::hold
		{
		private:
			V val ;
		public:
			hold (V v = 0) : val (v) {}
			void show() const {cout << val << endl ;}
			V Value () const {return val ;}
		};                                     // 此处不能遗忘 分号 

	template <typename T>
	template <typename U>
		U bate<T>::blab (U u , T t)
		{
			return (n.Value() + q.Value() ) * u / t ; 
		}

在 VC++ 6.0 中的输出结果是 ：
=====================================
当 guy 声明为 double 时候 :
3.5
调用类中的函数 blab () 时候 :
28
28.2609
Press any key to continue
===================================
 */