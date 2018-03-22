# include <iostream>
# include <iomanip>

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;
	using std::ios_base ;
	
	int a , b , c ;
	char ch ;
	char str[20] ;

	cin >> a ;

	cin.ignore (20 , 't') ;  // 抽取从下一位置到 't'字符处 ；
	cin >> b ;
	cout << std::setw (4) << a << std::setw (5) << b << endl ;
							// 此处的 cin 遗留 换行符在流中 ;

	if (cin.peek() == '\n')  // peek () 检查输入流中的下一个字符
	{
		cin.get () ;
		cin.putback ('g') ;  // putback () 插入字符 
	}

	cin.exceptions (ios_base::failbit) ;	//设置异常

	try{
		cin.get(str , 20) ;		//  get 的一大缺点就是自身都容不下 换行符 还抽取完字符时不清掉!!!!!!
	}

	catch (ios_base::failure & bf )
	{
		cout << bf.what () << endl  ;		//	调用了类方法检查错误 ；
		cout << "error to get it !!!! " << endl ;
	}
	cout << str << endl ;
	cout << cin.gcount () << endl ;
	
	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
12 jdit34
  12   34
i will hold on
gi will hold on
15
Press any key to continue
=============================
*/