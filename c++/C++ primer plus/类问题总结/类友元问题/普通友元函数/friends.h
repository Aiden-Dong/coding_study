# ifndef FRIENDS_H_
# define FRIENDS_H_

class Base
{
private:
	static int a ;
	int c ;

public:
	Base (int j = 0 ) ;
	void show_base () const ;
	friend void show_friend () ;	// 友元函数不可使用 const !!
};

# endif 