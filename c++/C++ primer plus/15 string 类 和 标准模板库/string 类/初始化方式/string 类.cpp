# include <iostream>
# include <string>

int main ()
{
	using std::cout ;
	using std::endl ;
	using std::string ;

	string gil ; 
	gil= "dasfgag";

	string one ("hellow world !!!") ;  // 第一种
	string two (12 , 's') ;		// 第二种
	string three  = one + two  ;   // 第三种 

	char * str = "saligia !!"	;	// str 字符串 

	string four (str , 20) ;	//第四种		// 当超出所有字符时 ， 仅读取字符串（结尾空字符影响）

	string five (str+2 , str+5);	//第五种
	string six (one , 4 , 10);		//第六种

	cout << one << endl ;
	cout << two << endl ;
	cout << three << endl ;
	cout << four << endl ;
	cout << five << endl ;
	cout << six << endl ;

	cout << int (four [14]) << endl;	// 此时可读取  是因为  他只初始化字符串内部字符  ， 在外部无读取权 ;

	return 0 ;

}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
hellow world !!!
ssssssssssss
hellow world !!!ssssssssssss
saligia !!
lig
ow world !
Press any key to continue
============================
*/