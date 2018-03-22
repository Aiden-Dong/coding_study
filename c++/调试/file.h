#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>

class File
{
private:
	char name[10];
	ifstream fin; 
	ofstream fout;
public:
	File();
	~File ();
	const char * ReadFile ();
	bool WriteFile ();
};

#endif