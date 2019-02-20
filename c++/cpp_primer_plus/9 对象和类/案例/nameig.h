# ifndef NAMEIGH_H_
# define NAMEIGH_H_

typedef struct H_JINMF
{
	char name[15];
	long xuehao;
	int age;
	char grand;
	H_JINMF * next;
} Card , *Pcard;	// 栈中的每一个元素

typedef struct 
{
	Pcard p1;
	Pcard p2;
} F_xiang , *P_xing; //栈指针 


class student 
{
private:
	enum {MAX = 10};	// 在 类中 声明的变量 
	int top;    // 指明是否 栈空 或 栈满
	F_xiang Class;
	Pcard End;	// 尾栈标记
	Pcard Arrd;	// 搜索栈标记
	Pcard Arrd1;// 辅助搜索栈标记

public:

	student();	// 默认构造函数
	~student ();// 析构函数 

	bool Cla_ss ()const;
	void z_zhan ();
	void j_zhan (char * name1);
	void show ();

};

# endif



