# ifndef BINARYS_H_
# define BINARYS_H_

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
	NOTE End_binary [16] ;

	void init_binary () ;
	void set_binary (PNOTE Pil) ;
public :
	Binary (int a = 1) ;	
	void show_binary () const ;
 
} ;	// 不要忘记最后的分号

# endif 