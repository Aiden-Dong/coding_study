# include <iostream>

struct arm {
	char str[20];
	int n;
};

void str_ang ( arm *name);
void str_ang2 (arm name);
 
int main ()
{
	using namespace std;

	arm name;

	str_ang (&name);
	str_ang2 (name);

	return 0;
}
void str_ang (arm *name)
{
	using namespace std;

	cout << "请输入你的名字 :" << endl;
	cin >> name->str;
	cout << "请输入你的年龄 :" << endl;
	cin >> name->n;
}
void str_ang2 ( arm name)
{
	std::cout << "姓名 : " << name.str << std::endl;
	std::cout << "年龄 : " << name.n << std::endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
请输入你的名字 :
saligia
请输入你的年龄 :
20
姓名 : saligia
年龄 : 20
Press any key to continue
==============================
*/
