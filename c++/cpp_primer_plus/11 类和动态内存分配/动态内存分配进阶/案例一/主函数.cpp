# include <iostream>
# include "name.h"
const int A =10;
const int B = 81;

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl;

	String name ;
	cout << "请输入姓名 : " << endl;

	cout << name << "请输入 10 个谚语 :" << endl;

	String say[10];
	char temp[81];

	for (int i = 0 ; i < 10 ; i++)
	{
		cout << i+1 << ": ";
		cin.get (temp , 81);
		while (cin && cin.get () != '\n');

		if (!cin || temp[0] == '\0')
			break;
		else
			say[i] = temp;
	}

	int total = i;

	if (total > 0)
	{
		cout << "你的输入为 : " << endl;
		for (i = 0 ; i < total ; i++)
			cout << "say[i] = " << say[i] << endl;
	}
}
