# include <iostream>
# include <iomanip>

int main ()
{
	using namespace std ;

	int a = 1 , b = 2 , c = 3 ;

	// int ** q = {&a , &b , &c } ;	// 此处不被允许	   //    cannot convert from 'int *' to 'int ** '

	int * q[3] = {&a , &b , &c } ;	// 此处的意义为 :
												//   存在一个包含三个元素的数组 ;
												//	 其中的每一个元素为指向 int 型的指针
				// 也就是说明二维指针的使用也有理清头绪 不要盲目使用 ;

	cout << setw(3) << *q[0] << setw(3) << *q[1] << setw(3) << *q[2] << endl ;
	cout << setw(3) << q[0][0] << setw(3) << q[1][0] << setw(3) << q[2][0] << endl ;	// 向普通二维进步
//=====================================================================================
	for (int i = 0 ; i < 3 ; i++)
		q[i] = new int [4] ;	// 意义同上

	for (int y = 0 ; y < 3 ; y++)
		for (int x = 0 ; x < 4 ; x ++)
			q[y][x] = 2 ;
	
	for (y = 0 ; y < 3 ; y++)
		for (int x = 0 ; x < 4 ; x++)
			cout << setw (3) <<	q[y][x] << endl ;
//=====================================================================================

	return 0 ;
}