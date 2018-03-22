# ifndef NAME_H_
# define NAME_H_

class stock
{
private:
	enum {STN = 14};

	int stone ;
	double left ;
	double pound ;

public:
	stock ();
	stock (double x);
	stock (int x , double y);
	~stock () ;
	void show_lbs () const ;
	void show_stn () const ;

	operator int () const ;                   // 转换函数必须是类方法（不可为友元函数）
	operator double () const ;                // 不可带参数跟返回值 

	double operator + (const double x)const
	{
		return (pound + x);
	}
};


# endif