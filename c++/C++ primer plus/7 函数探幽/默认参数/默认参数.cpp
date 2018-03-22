# include <iostream>
# include <cstring>

void h_shu ( const char * str , int n = 1);
void h_shu ( const char * str = "no name" );

int main ()
{


	int a ;
	char *str = "Hellow World !!";
	


	std::cout << str << std::endl;

	std::cout << "请输入要显示的字符数 :" << std::endl;

	std::cin >> a;
	
	h_shu ( str , a );
//	h_shu ( str );		//	此函数具有选择二义性 ，

	return 0;
}
void  h_shu ( const char * str , int n )
{
	using namespace std;

	char * str1;
	int m = strlen(str);
	

	if ( n >= 0 && n <= m)                     // 此处的函数替换请看附录
	{
		str1 = new char [n+1];

		for ( int i = 0 ; i < n ; i++)
			str1[i] = str[i];                  

		str1[i] = '\0';

		cout << str1 << endl;
	}
	else
		cout << "您的输入有误 !!!" << endl;

	delete str1;                                   // 动态内存不要忘记释放
	
}
void h_shu ( const char * str  )
{
	using std::cout ;
	using std::endl ;

	cout << str << endl ;
}

/*
在 VC++ 6.0 中的输出结果是 ：
============================
Hellow World !!
请输入要显示的字符数 :
4
Hell
H
Press any key to continue



函数替换法 1 :

  int len = strlen (str);

  (len < n) ? len : n;

函数替换法 2:

 int m = 0;
  
 while (str[m] && m <= n)
	m++;

函数替换法 3:

  char * p = new char [n+1];

  for (int i = 0 ; i < n && str[i] ; i++)
	p[i] = str[i];
============================
*/