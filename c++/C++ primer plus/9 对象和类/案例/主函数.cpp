# include <iostream>
# include "nameig.h"
# include <windows.h>
# include <ctime>

int main ()
{
	using namespace std;
	
	int a;
	char str[15];
	student student0 ;

	while (1)
	{
	
		cout << "请选择 :" << endl;
		cout << "1. 加入新名单 : "<< endl ;
		cout << "2. 删除名单 :" << endl ;
		cout << "3. 显示名单 :" << endl ;
		
		
		cin >> a ;
		system ("cls");
		
		switch (a)
		{
		case 1:		
			student0.z_zhan  ();
			break;
		case 2:
			cout << "请输入要删除的对象名称 : " << endl;
			cin >> str ;
			student0.j_zhan  (str);  // 出现错误
			break;
		case 3:
			student0.show  ();
			break;
		case 4:
			goto End;
		default:
			cout << "输入有误 , 重新输入 : " << endl;
			if (!cin )
			{
				cin.clear ();
				while (cin.get () != '\n');
			}
	
			
			
		}
		
	}

End:
	
	return 0;
} 
