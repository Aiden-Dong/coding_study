# ifndef NAME_H_
# define NAME_H_

# include <string>

class Brass
{
private :
	std::string Name ;    // 存储姓名
	long Num ;            // 帐号
	double balance ;      // 账户余额

public:
	Brass(const std::string & s = "Null name", long n = -1 , double bal = 0.0 );
	void Deposit (double atm) ;  // 存钱；
	virtual void Withdraw (double atm) ; // 取钱 
	virtual void Show ()const ;
	double reature ()const {return balance ;}
	virtual ~Brass (){}
};

class BrassPlus : public Brass    // 此处只有一个冒号
{
private:
	
	double max ; // 透支上限 
	double rate ; // 透支贷款利率
	double owes ; // 欠费
	long number ; // 操作密码

public:

	BrassPlus(const std::string & s = "Null name" , long n = -1 , double bal = 0.0 , double ml = 500 , double r = 0.0125 , double ow = 0 , long nul = 123456);
	BrassPlus (const Brass & ba , double ml = 500 , double r = 0.0125 , double ow = 0 , long nul = 123456) ; 

	virtual void Show ()const ;
	virtual void Withdraw (double atm) ; 
	void Reatmax (double m){max = m;}  // 设置透支上限
	void Reserate (double r){rate = r;} // 设置贷款利率
	long read ()const {return number ;}
	void lingl () {owes = 0 ;}
};

#endif 