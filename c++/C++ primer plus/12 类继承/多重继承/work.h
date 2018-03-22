# ifndef WORK_H_
# define WORK_H_

# include <string.h>

using std::string ;

class worker
{
private:
	string fullname ;
	long id ;
protected:
	virtual void Date () const ;      // 在基类声明为虚的函数使得在所有派生类中都为虚 ;
	virtual void Get () ;
public:
	worker():fullname ("no one") , id (0L) {}
	worker (const string &s , long n) : fullname (s) , id (n) {}
	virtual ~ worker(){}
	virtual void set () = 0 ;         // 纯虚函数使得基类为抽象基类 ;  此处正显示出了纯虚函数的作用 ; 
	virtual void show () const = 0 ;
};

class waiter : virtual public worker       // virtual 提示为继承虚基类
{
private:
	int panache ;
protected:
	void Date () const ; 
	void Get ();
public:
	waiter() : worker () , panache (0) {}                 // 此处可以传递 ， C++禁止通过中间类传递给基类 （提示 中间类）
	waiter (const string &s , long n , int p = 0) : worker (s,n), panache(p){}
	waiter (const worker & wk , int p = 0) : worker (wk) , panache (p) {} 
	void set ();
	void show () const ;
};

class singer : virtual public worker
{
protected:
	enum {other , alto , contualto , aoprato , bass , baritual , tenor} ;
	enum {Vt = 7};
	void Date () const ; 
	void Get ();
private:
	static char *pv[Vt];
	int voice ;
public:
	singer () :  worker () , voice (0) {}
	singer (const string &s , long n , int v = 0) : worker (s,n) , voice (v){}
	singer (const worker & wk , int v = 0) : worker (wk) , voice (v){} 

	void set ();
	void show () const ;

};

class singwaiter : public singer , public waiter
{
protected:
	void Date () const ; 
	void Get () ;
public:
	singwaiter() {}   // 自动调用上一级的默认构造函数
	singwaiter(const string &s , long n ,int p = 0, int v = 0): worker (s,n),waiter (s,n,p),singer (s,n,v){}
	singwaiter(const worker & wk ,int p = 0, int v = 0): worker (wk), waiter (wk,p),singer (wk,v){}
	singwaiter(const waiter &wt, int v = 0): worker (wt),waiter(wt), singer (wt,v){}
	singwaiter(const singer &wt, int p = 0): worker (wt),waiter(wt,p), singer (wt){}

	void set ();
	void show () const ;

};
# endif