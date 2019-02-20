# include <iostream>
# include "name.h"


int main ()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int a ; 
	BrassPlus Name ("saligia" , 2013201890 , 5000 , 500 , 0.92 , 0 , 123456);

	

	while (1)
	{
		cout<< "请输入你的身份 :" << endl 
		<< "1 . 客户" << endl 
		<< "2. 工作人员" << endl;

		cin >> a ;
		if (a == 1)
		{
			while(1)
			{
				cout <<"存钱选择 1 " <<endl 
					<< "取钱选择 2" << endl
					<< "查看账户 3" << endl ;

				cin >> a ;
				if (a == 1)
				{
					double and ;
					cout << "请输入存钱金额" << endl ;
					cin >> and ;
					Name.Deposit (and);
					break;
				}
				else if (a == 2)
				{
					double and1 ;
					cout << "请输入取钱金额" << endl ;
					cin >> and1 ;
					Name.Withdraw(and1);
				}
				else if (a== 3)
					Name.Show ();
				else
					cout <<"输入错误" << endl ;

			}
		}
		else if (a == 2)
		{
			while(1)
			{
				long aj;
				cout << "请输入操作密码 ：" << endl ;
				cin >> aj;
					if(aj = Name.read ())
					{
						while(1)
						{
							int am ;
							cout << "1 . 查看账户" << endl 
								<< "2 . 更改利率" << endl 
								<< "3. 更改透支上限" << endl 
								<<"4 . 透支回零 " << endl ;
							cin >> am;

							if (am == 1)
								Name.Show();
							else if (am == 2)
							{
								double ajj;
								cout << "请输入新利率：" << endl ;
								cin >> ajj;
								Name.Reserate (ajj);
								cout << "设置成功" << endl ;
							}
							else if (am == 3)
							{
								double ajg;
								cout << "请输入新上限：" << endl ;
								cin >> ajg;
								Name.Reatmax (ajg);
								cout << "设置成功" << endl ;
							}
							else if (am == 4)
								Name.lingl ();
							else
								cout << "输入错误" << endl ;
							break;
							
						}
						
					}
					else
						cout << "密码错误" << endl ;

						break ;
			}
		}

		else
		{
			cout << "选择错误 重新选择" << endl ; 
			break ;
		}
	}


	return 0;
}