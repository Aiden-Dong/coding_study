# include <iostream>

int main (void)
{
	using namespace std;

	char c1 , c2;

	cout << "请输入第一个字符 :" << endl ;
	cin.get (c1);

	cout<< "第二组字符 : " << endl ;
	cin.get (c2);

	cout << "c1 = " << c1 <<endl;
	cout <<"c2 = " << c2 << endl;

	cout << "c1 = " << int (c1) <<endl <<"c2 = "<< int (c2) <<endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入第一个字符 :
s
第二组字符 :
c1 = s
c2 =                         -------------------------c2 接受了一个换行符 其 ASCLL 码为 10； 

c1 = 115
c2 = 10
Press any key to continue
===========================
*/