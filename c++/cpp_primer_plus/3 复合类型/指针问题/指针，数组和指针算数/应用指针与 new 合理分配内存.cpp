# include <iostream>
# include <cstring>

using namespace std;

char * getname ( void );

int main (void)
{
	char * name;
	name = getname ();

	cout << "name = " << name << endl;

	delete name;

	name = getname ();
	cout << "name = " << name << endl;
	delete name;                          //注意不要忘记释放内存！！！！！！！！！！！

	return 0;
}
char * getname (void)
{
	char temp[80];

	cout << "请输入一组字符串 :" << endl;
	cin.getline ( temp , 80 );

	char * pn = new char [ sizeof(temp)+1 ];     // new 以堆的形式分配内存 所以当函数使用完毕时 pn 仍然存在
	strcpy ( pn , temp );

	return pn;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入一组字符串 :
Hellow world!!!
name = Hellow world!!!
请输入一组字符串 :
hellow everyone and I believe you!!!
name = hellow everyone and I believe you!!!
Press any key to continue
===========================
*/