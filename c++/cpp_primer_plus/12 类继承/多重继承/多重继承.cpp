# include <iostream>
# include <cstring>
# include "work.h"

const int SIZE = 5 ;

int main ()
{
	using std::cin ;
	using std::cout ;
	using std::endl ;

	worker * lolar [SIZE] ; 

	for (int i = 0 ; i < SIZE ; i++)
	{
		char choice ; 
		cout << "请选择选项 : " << endl
			<< "q. 放弃写入" << endl 
			<< "s. 写入一个singer 类" << endl 
			<< "w. 写入一个 waiter 类" << endl 
			<< "t. 写入一个多重继承类" << endl;

		cin >> choice ; 

		while (strchr ("wsqt",choice) == NULL)
		{
			cout << "选项错误 " << endl ;
			cin >> choice ;
		}

		if (choice == 'q')
			break ;
		switch (choice)
		{
		case 's' : 
			lolar[i] = new singer ;
			break;
		case'w':
			lolar[i] = new waiter ;
			break ;
		case't': 
			lolar[i] = new singwaiter;
			break;
		}
		cin.get();

		lolar[i]->set();
	}

	cout << "你的选择为 :" << endl ;

	for (int r = 0 ; r < i ; r++)
	{
		cout << endl ;
		lolar[r]->show();
	}
	for ( r = 0 ; r < i ; r++)
		delete lolar[r] ;

	cout << " Shut down" << endl ;

	return 0 ;
}