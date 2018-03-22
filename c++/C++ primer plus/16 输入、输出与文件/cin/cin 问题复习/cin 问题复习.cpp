# include <iostream>

int main ()
{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	using std::ios_base ;

	char a[10] ;

	cin.exceptions (ios_base::failbit); // 调用异常方法  ios_base::failbit 

	try {
		cin.get (a , 10) ;
	}

	catch (ios_base::failure & bf)		// failbit 异常的处理方法 ；
	{
		cout << "error : "  ;
		cout << bf.what () <<endl ;  
	}

	//cin.ignore (5 , ' ') ;	// 从头开始 

	if (cin.peek () == '\n')
		cin.get () ;

	cin.get (a, 10);	// 最多抽取 n-1 个 

	cout << a << endl ;
	cout << cin.gcount () << endl ;			// 返回最后一个非格式输入的字符数 

	return 0 ;
}