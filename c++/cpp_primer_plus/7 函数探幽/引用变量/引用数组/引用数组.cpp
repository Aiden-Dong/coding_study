# include <iostream>


int main ()
{
	using namespace std;

	int a[5] = {1 , 2 , 3 , 4 , 5};
	int *p = a;

	int  *(& b) = p;      
//	int  *(& b) = a;       //数组暂且不可
	cout << b << endl; 
	cout << p << endl ;

	cout << b[3] << endl; 
	cout << p[3] << endl ;


	return 0;
}
