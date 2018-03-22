# include <iostream>

int main ()
{
	using std::cout ;
	using std::ostream ;
	using std::ios_base ;

	int a ;

	cout.setf (ios_base::dec , ios_base::basefield) ;
	cout.setf (ios_base::fixed , ios_base::floatfield) ;
	cout.setf (ios_base::left , ios_base::adjustfield);
	cout.precision (2) ;// 位数过低 将转化为 科学计数法 ；
	cout.setf (ios_base::showpos);
	cout.setf (ios_base::showbase);
	cout.setf (ios_base::uppercase) ;
	cout.setf (ios_base::showpoint) ;

	cout.width (6) ;
	cout.fill ('*') ;
	cout << 12.5432 << std::endl ;
	cout << 12.5317 << std::endl ;
	
	cout << 46563  << std::endl ;

	return 0 ;
}