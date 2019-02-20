# ifndef CASES_H_
# define CASES_H_

# include <iostream>

class Case
{
private :
	char name[10] ;
	char Card [15];
	int age ;
public :
	Case () ;
	Case (char * a, char * c , int b) ;

	bool operator < (const Case & ex) ;
	bool operator > (const Case & ex) ;
	void operator = (const Case & ex) ;
	
	
	friend std::ostream & operator << (std::ostream & Os , Case j) ;

} ;

class Manage 
{
private :
	Case one [5] ;
public:
	Case & operator [] (int a) ;	// 不能有默认参数
	void sort_manage () ;
	void show() const ;


} ;

# endif 