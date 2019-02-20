# include <iostream>

int main (void)
{
	using namespace std;

	char ch;

	cin.get (ch);        

	while ( ch != 'L')
	{
		cout << ch << " = " << (int) ch << endl;  // cin.get () 会接受包括 空字符 换行符 等的一切字符；
		cin.get (ch);
	}
	cin.get (ch);

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
ashf lkaf l;ajf
a = 97
s = 115
h = 104
f = 102
  = 32
l = 108
k = 107
a = 97
f = 102
  = 32
l = 108
; = 59
a = 97
j = 106
f = 102
  = 32

 = 10
L
Press any key to continue
===========================
*/