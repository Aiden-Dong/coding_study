# include <iostream>
# include "name.h"
# include <windows.h>

using std::cout ;
using std::endl ;
using std::string ;  // 包含在name.h 中

Brass::Brass(const std::string & s , long n , double bal )
{
	Name = s ;
	Num = n ; 
	balance = bal ;
}

void Brass::Deposit (double atm)     // 存钱
{
	if (atm <= 0 )
		cout << "你要存的金钱数错误 !!!" << endl ;
	else 
		balance += atm ;
}

void Brass::Withdraw (double atm)  // 取钱
{
	if (atm <= 0 )
		cout << "你要提取的金钱数错误 !!!" << endl ;
	else 
	{
		balance -= atm ;
		cout << "取钱成功" << endl ;
	}
}

void Brass::Show ()const
{
	system ("cls");
	cout << "用户的基本信息" << endl ;
	cout << "姓名 : " << Name << endl ; 
	cout << "账户 : " << Num  << endl ;
	cout << "余额 : " << balance << endl ;
}


BrassPlus::BrassPlus(const std::string & s , long n , double bal , double ml , double r , double ow , long nul)
					: Brass (s , n , bal )
{
	max = ml ;
	rate = r ; 
	owes = ow ;
	number = nul ;
}

BrassPlus::BrassPlus(const Brass & ba , double ml , double r , double ow , long nul)
					 : Brass (ba)
{
	max = ml ;
	rate = r ; 
	owes = ow ;
	number = nul ;
}

void BrassPlus::Show ()const
{
	Brass::Show ();
	cout << "透支上限 : " << max << endl ; 
	cout << "透支利率 : " << rate << endl ;
	cout << "透支金额 : " << owes << endl ;

}
void BrassPlus::Withdraw (double atm)
{
	if ( reature() >= atm )
		Brass::Withdraw (atm);
	else if (atm - reature() <= max) 
	{
		double a = reature() ;
		Brass::Withdraw( reature());
		owes = (atm - a) * (1+rate);
	}
	else
		cout <<"取款失败" << endl ;

	BrassPlus::Show();
}
