# ifndef NAME_H_
# define NAME_H_

class Victor
{
private:  //-----------------------------隐藏部分（代码封装）
	int a;
	int b;
	int c;
public:  // -----------------------------公共接口
	Victor();                           //默认构造函数
	Victor(int x , int y , int z);      //构造函数
	~Victor ();                         //析构函数

	void c_a ()const;
	void c_b ()const;
	void c_c ()const;

	Victor operator + (const Victor & New); // 运算符重载方式之一
};

# endif