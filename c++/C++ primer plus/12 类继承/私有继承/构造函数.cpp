# include <string>
# include <iostream>
# include "student.h"

using std::string ;
using std::cout ;
using std::cin ;
using std::endl ;

student::student (const string &s )
{
	name = s ;
	grade = new double [5] ;
	for (int i = 0 ; i < 5 ; i++)
		grade[i] = 0 ;
} 

void student::write ()
{
	if (grade != NULL)
	{
		cout << "录入成绩 :" << endl ;
		for (int i = 0 ; i < 5 ; i++)
			cin >> grade[i] ;
	}
	else
		cout << "没有空间写入" << endl ;

}
student::~student()
{
	cout << "释放空间 : " << name << endl ; 
	delete [] grade ;
}
void Student::show ()
{
	double * grade1 = student::Grade ();
	string name1 = student::Name ();
	cout << "姓名 : " << name1 << endl ;
	cout << "语文 : " << grade1[0] << endl ;
	cout << "数学 : " << grade1[1] << endl ;
	cout << "英语 : " << grade1[2] << endl ;
	cout << "生物 : " << grade1[3] << endl ;
	cout << "物理 : " << grade1[4] << endl ;
}
