#include <iostream>


int main( void )
{
	using namespace std;

    char str[8];
	
	cout << "请第一次输入 :" << endl ;
    cin.getline(str, 5);
    cout<<str<<endl;

	//cin.get();

	cin.clear ();  //--------------------------????????????????????
	
	cout << "请第二次输入 :" << endl ;
    cin.getline(str, 5);
    cout<<str<<endl;

    return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请第一次输入 :
abcdefgh
abcd
请第二次输入 :

Press any key to continue
=============================
*/
