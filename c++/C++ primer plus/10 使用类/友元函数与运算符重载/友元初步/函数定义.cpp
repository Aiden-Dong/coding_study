# include <iostream>
# include "nameig.h"
# include <cstring>

student :: student ()
{
	End = new Card;
	End->next = NULL;
	Class.p1 = End;
	Class.p2 = End;
	Arrd = Class.p1 ;
	strcpy (End->name ,"string");
 
	top = 0; // 空栈
}

student::~student ()
{
	std ::cout<< "Bybe!!!"<< std::endl;
}

bool student:: Cla_ss ()const
{
	if (top >= 0 && top <= MAX)
		return 1;
	else
		return 0;
}

void student:: z_zhan ( Pcard &Student)
{
	Student->next = Class.p1;
	Class.p1 = Student;

	std::cout << "请输入学生姓名 : " << std:: endl;
	std::cin >> Student->name ;
	std::cout << "请输入学号 : " << std:: endl;
	std:: cin >> Student ->xuehao ;
	std:: cout << "请输入年龄 : " << std::endl;
	std::cin >> Student->age ;
	std::cout << "请输入成绩 : " << std::endl;
	std:: cin >> Student->grand ;

	top ++;

}

void student ::  j_zhan (  char * name1 ) 
{
	int a = 1 ;
	int i = 1;

	Arrd = Class.p1 ;
	Arrd1 = Class.p1 ;

	while ( strcmp(Arrd->name , name1) && Arrd  != Class.p2 )
	{
		a++;
		Arrd = Arrd->next ;
	}
	if (Arrd->name  == Class.p2->name )
		std :: cout << "此名称不存在 : " <<std:: endl;
	else
	{
		if ( a == 1 )
		{
			Class.p1 = Class.p1 ->next ;
			delete[]Arrd;
		}
		else
		{
			while(++i != a)
				Arrd1 = Arrd1->next;
			Arrd1->next = Arrd ->next ;
				delete []Arrd;
		}
		std::cout << "已成功删除此记录!!!!" << std::endl ;
	}

}

void student::show ()
{
	using std :: cout ;
	using std :: cin;
	using std :: endl;

	Arrd = Class.p1 ;

	if (Arrd != Class.p2 )
	{
		while (Arrd != Class.p2 )
		{
			cout << "姓名 : " << Arrd->name  << endl;
			cout << "年龄 : " << Arrd->age  << endl;
			cout << "学号 : " << Arrd->xuehao  << endl;
			cout << "成绩 : " << Arrd->grand  << endl;
			cout << endl;
			Arrd = Arrd->next ;
		}
	}
	else
		cout << "这是空栈 !!!!" << endl;
		
}

std::ostream & operator << (std::ostream & Os , student & Student)
{

	using std :: endl;

	Student.Arrd = Student.Class.p1 ;

	if (Student.Arrd != Student.Class.p2 )
	{
		while (Student.Arrd != Student.Class.p2 )
		{
			Os << "姓名 : " << Student. Arrd->name  << endl;
			Os << "年龄 : " << Student.Arrd->age  << endl;
			Os << "学号 : " << Student.Arrd->xuehao  << endl;
			Os << "成绩 : " << Student.Arrd->grand  << endl;
			Os << endl;
			Student.Arrd = Student.Arrd->next ;
		}
	}
	else
		Os << "这是空栈 !!!!" << endl;

	return Os;

}