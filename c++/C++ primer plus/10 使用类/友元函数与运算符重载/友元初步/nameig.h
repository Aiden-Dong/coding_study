# ifndef NAMEIGH_H_
# define NAMEIGH_H_

# include <iostream>

typedef struct H_JINMF
{
	char name[15];
	long xuehao;
	int age;
	char grand;
	H_JINMF * next;
} Card , *Pcard;

typedef struct 
{
	Pcard p1;
	Pcard p2;
} F_xiang , *P_xing;


class student 
{
private:
	enum {MAX = 10};
	int top;    // 指明是否 栈空 或 栈满
	F_xiang Class;
	Pcard End;
	Pcard Arrd;
	Pcard Arrd1;

public:

	student();
	~student ();

	bool Cla_ss ()const;
	void z_zhan (Pcard &Student);
	void j_zhan ( char * name1);
	void show ();
	friend std::ostream &  operator << (std::ostream & Os , student & Student );  // 友元函数
};

# endif



