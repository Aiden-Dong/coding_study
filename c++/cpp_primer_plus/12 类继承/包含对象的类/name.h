# ifndef NAME_H_
# define NAME_H_

# include <string>
# include <valarray>

class student
{
private:
	typedef std::valarray <double> array ;
	std::string name ;
	array scorces ;

public:

	student () : scorces (0){name = "no name";}      // 此证明可以不使用初始化列表
	explicit student (const std::string &s) ;        //同上
	explicit student (int n) : name ("no name") , scorces (n){}
	student (const std::string & s , int n ) : name (s) , scorces (n) {}
	student (const std::string & s  , int a, int b) : name (s) , scorces (a,b){}
	student (const std::string & s , double a[] , int b) : name (s) , scorces (a , b) {}

	void show () const ;
	void max () const ;
	void min () const ; 

	~ student (){}
};
# endif 