# include <iostream>
# include <string>
# include <ctime>

int main ()
{
	using std::endl ;
	using std::string ;
	using std::cout ;
	using std::cin ;

	string SUM[10] = {
		"apiary" , "beetle" , "cereal" , "danger" , "ensign" , 
			"florid" , "garage" , "mangert" , "noncekl" , "stoledj" 
	};

	int a ;

	srand(time(0)) ;

	a = rand () % 10 ;

	cout << "猜吧 !!!" << endl ;

	int length = SUM[a].length() ; // size()
	string jin (length , '-') ;

	while (jin != SUM[a])
	{
		char ch ;

		cout << "你的猜测结果 : " << jin << endl ;
		cout << "请输入 : " << endl ;
		cin >> ch ;

		int b = SUM[a].find (ch) ;

		while (b != string::npos)
		{
			jin[b] = ch ;

			b = SUM[a].find (ch , b+1) ;
		}

	}

	cout << "输入正确 !!" << endl ;

	cout<< jin << endl ;

	return 0 ;
}