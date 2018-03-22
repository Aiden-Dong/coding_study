# include <iostream>
# include "student.h"

void s_tudent1 (student & ant)
{
	using namespace std;

	cout << "请输入 姓名:" << endl;
	cin >> ant.name;

	cout << "请输入年龄 :" << endl;
	cin >> ant.age;

	cout << "请输入成绩 :" << endl;
	cin >> ant.and ;

	cout << "请输入学号 :"<< endl;
	cin >> ant.card ;
}

