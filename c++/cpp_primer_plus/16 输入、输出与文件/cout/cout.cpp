# include <iostream>
# include <iomanip>

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;
	using std::ios_base ;

	char a ;
	ios_base::fmtflags jin = cout.setf (ios_base::hex , ios_base::basefield) ;
	cout.setf (ios_base::fixed , ios_base::floatfield ) ;
	cout.setf (ios_base::right , ios_base::adjustfield );

	while ( cin.get(a) )
	{
		cout.put (a) ;

		if (a == '\n')
			break ;
	}
	cout << endl ;

	int b ;
	double d ;
	cout.fill ('*') ;

	cin >> d >> b;
	cout.precision (3) ;
	cout.setf (ios_base::showpoint) ;
	cout.setf (ios_base::showbase) ;
	cout.setf (ios_base::uppercase);


	cout.width (8) ;			//	只能设置第一个的格式 
	cout << d << "   "<< b<< endl  ;

	cout.setf (jin , ios_base::floatfield) ;

	cout << std::setw (6) << d << std::setw (6) << b << endl ;
	cout.setf (jin , ios_base::basefield) ;	
	cout << std::setw (6) << d << std::setw (6) << b << endl ;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
dfa f d
dfa f d

23.4 15
**23.400   0XF
**23.4***0XF
**23.4****15
Press any key to continue
============================
*/