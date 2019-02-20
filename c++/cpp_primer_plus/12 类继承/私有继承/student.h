# ifndef STUDENT_H_
# define STUDENT_H_

# include <string>
# include <iostream>

using std::string ;

class student
{
private:
	string name ;
	double * grade ;
public:
	student () : name ("no name") , grade (NULL) {}
	student (const string &s ) ;
	void write () ; 
	string & Name () {return name ;}
	double * Grade ()  {return grade ;}
	~student();
};

class Student : private student
{
public:
	Student() : student (){}
	Student (string &s) :student (s) {}
	void write () {student::write ();}
	void show () ;
	~Student(){}

};
# endif