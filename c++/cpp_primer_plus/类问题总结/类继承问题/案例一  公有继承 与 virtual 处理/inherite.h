# ifndef INHERITE_H_
# define INHERITE_H_

# include <string>

class Base
{
private:
	std::string name ;
	std::string card ;
	int garde ;
public:
	
	Base (char *a1 = "No name", char * b1 = "0000000000", int g = 0) ;
	virtual void show_massage ()const ;
	int r_garde () const ;
	
};

class Devire : public Base 
{
private:
	int age ;
public:
	
	Devire (Base one , int b = 0) ;
	Devire (char* a1 , char* a2 , int a , int b) ;
	void show_massage () const ;
	int r_age () const ;
} ;

# endif 