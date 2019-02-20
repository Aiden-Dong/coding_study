# include <iostream> 

const int Arize = 10;

void strcon (const char * str);

int main ()
{
	using namespace std;

	char input[Arize];


	cout << "输入一句话 :" << endl;
	

	while (cin.get (input , Arize))
	{
		while (cin.get()!='\n');

		strcon (input);
		cout << "Enter next line :" << endl;

	}

	cout << "Bybe!!!!" << endl;

	return 0;
}
void strcon (const char * str)
{
	using namespace std;

	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" contain " << endl;
	while (*str++)
		count ++;

	total += count;

	cout << count << " 本次字符数!!" << endl;
	cout << total << " 总共字符数!!" << endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=================================
输入一句话 :
najinsdfg ds
"najinsdfg" contain
9 本次字符数!!
9 总共字符数!!
Enter next line :
sa;igj
"sa;igj" contain
6 本次字符数!!
15 总共字符数!!
Enter next line :
jinfg
"jinfg" contain
5 本次字符数!!
20 总共字符数!!
Enter next line :
sd df ds
"sd df ds" contain
8 本次字符数!!
28 总共字符数!!
Enter next line :

Bybe!!!!
Press any key to continue

=================================
*/