# ifndef NAME_H_
# define NAME_H_

class Stock
{
private :
	int a ;
	int b ;
	double c;
	void s_a () const ;
	void s_b () const ;
	void s_c () const ;

public:
	Stock ();                                                    // 默认构造函数
	explicit Stock (int x , int y = 0 , double z = 0 );          // 构造函数 （可用来进行类型转化 将普通变量转化成 类）
	~Stock ();                                                   // 析构函数

	void show () const;


	friend Stock operator + (const Stock & new1 , const Stock & new2); // 友元函数
};

# endif