# ifndef BINARY_H_
# define BINARY_H_

typedef struct Note{
	int a ;
	Note * p1 ;
	Note * p2 ;
} NOTE , *PNOTE ;

class Binary 
{
private:
	NOTE first ;
	NOTE second [2];
	NOTE third [4] ;
	NOTE forth [8] ;
	NOTE Een_binary [16] ;
	void init_binary () ;
public :
	Binary () ;
	void show_binary () const ;
}