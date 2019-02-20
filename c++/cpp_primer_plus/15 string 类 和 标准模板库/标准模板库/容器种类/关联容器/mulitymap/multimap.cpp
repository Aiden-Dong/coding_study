# include <iostream>
# include <map>
# include <string>

int main ()
{
	using namespace std ;

	multimap <int , string> one ;

	while (1)
	{
		int a ;
		string b ;

		cin >> a >> b ;

		one.insert (pair <const int , string >(a, b) );

		if (a == 10)
			break ;
	}

	multimap<int , string>::iterator f1 ;
	for (f1 = one.begin () ; f1!= one.end() ; f1++)
	{
		cout  << " " << (*f1).first << " " << (*f1).second << endl ; 
	}
	cout << "1 : " << one.count (1) << endl ;
	cout << "2 : " << one.count (2) << endl ;

	pair <multimap <int , string>::iterator , multimap <int , string>::iterator> range  = one.equal_range (1) ;

	cout << "1 : " << endl ;
	for (f1 = range.first ; f1 != range.second ;f1++)
	{
		cout << (*f1).second << endl ;
	}

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==========================
1 nije 1 wejin 2 jike 1 gile 2 bileg 1 saligia 2 file 10 gijn
 1 nije
 1 wejin
 1 gile
 1 saligia
 2 jike
 2 bileg
 2 file
 10 gijn
1 : 4
2 : 3
1 :
nije
wejin
gile
saligia
Press any key to continue
===========================
*/
