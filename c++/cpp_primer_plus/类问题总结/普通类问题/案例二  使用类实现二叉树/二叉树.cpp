/*
	二叉树算法
*/
# include <iostream>
# include "binarys.h"

int main ()
{
	using std::cout ;
	using std::endl ;

	Binary one (100000) ;
	one.show_binary () ;

	return 0 ;
}

/*
 在 VC++6.0 的运行环境中 :
 ===========================
 0 : 6225
 1 : 6289
 2 : 6238
 3 : 6256
 4 : 6270
 5 : 6279
 6 : 6258
 7 : 6290
 8 : 6284
 9 : 6211
10 : 6164
11 : 6166
12 : 6245
13 : 6333
14 : 6229
15 : 6263
Press any key to continue
 ===========================
 */