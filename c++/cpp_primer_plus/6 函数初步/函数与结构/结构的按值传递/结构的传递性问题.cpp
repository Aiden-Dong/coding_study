# include <iostream>

struct arm {
	char str2[10];
	int str1;
	};

void str_ang1 (arm name);
arm str_ang2 (arm name);

int main ()
{
	using namespace std;

	arm name;

	name = str_ang2 (name);
	
	str_ang1 (name);

	return 0;
}
void str_ang1 (arm name)
{
	std::cout << "你的名字是 : " << name.str2 << std::endl;
	std::cout << "你的年龄是 " << name.str1  << std::endl;
}
arm str_ang2 (arm name)
{
	using namespace std;

	cout << "请输入你的名字 :"<< endl;
	cin >> name.str2 ;

	cout << "请输入你的年龄 :" << endl;
	cin >> name.str1;

	return name;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入你的名字 :
saligia
请输入你的年龄 :
20
你的名字是 : saligia
你的年龄是 20
Press any key to continue
=============================
*/