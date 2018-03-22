# include <iostream>
# include <cstdlib>
# include <ctime>
# include "stack.h"

const int Num = 10 ;

int main()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;

	srand (time(0));

	

	int stacksize ;

	cout << "请输入栈区的最大存储量 : " << endl ;
	cin >> stacksize ;

	stack <const char *> st (stacksize) ; // 声明栈的实例对象

	const char * in [Num] = {
		"1. saligia" , "2. jindam",
		"3. hiteml" , "4. operamg" , 
		"5 . deamjin" , "6. hiled" ,
		"7. greanf" , "8. yrewan",
		"9 . fream" , "10. loprea"
	};

	const char * out [Num] ;
	
	int proces = 0 ;
	int next = 0 ;

	while (proces < Num)
	{
		if (st.isempty ())
			st.push (in[next++]) ; 
		else if (st.isfull ())
			st.pop(out[proces++]);
		else if (rand() %2 && next < Num)
			st.push (in[next++]);
		else
			st.pop(out[proces++]); 
	}

	for (int i = 0 ; i < Num ; i ++)
		cout << out[i] << endl ;

	return 0 ;
}