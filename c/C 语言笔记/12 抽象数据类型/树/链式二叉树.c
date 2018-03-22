//=========链式二叉树==============

# include <stdio.h>
# include <stdlib.h>

typedef struct Binary{
	char Date ;
	struct Binary * p1 ;
	struct Binary * p2 ;
} Bina , *pBina ;

pBina Init_binary (void) ;

void Traverse_first (pBina Pi) ;	// 先序遍历
void Traverse_secound (pBina Pi) ;	// 中序遍历
void Traverse_third (pBina Pi) ;	// 后续遍历

int main ()
{
	pBina p1 = Init_binary () ;

	printf ("先序遍历 : \n") ;
	Traverse_first (p1) ;
	printf ("\n") ;
	
	printf ("中序遍历 : \n") ;
	Traverse_secound(p1) ;
	printf ("\n") ;

	printf ("后序遍历 : \n") ;
	Traverse_third (p1) ;
	printf ("\n") ;

	return 0 ;
}

pBina Init_binary (void)	// 初始化二叉树 ;
{	
	pBina pA = (pBina ) malloc (sizeof (Bina)) ;
	pBina pB = (pBina ) malloc (sizeof (Bina)) ;
	pBina pC = (pBina ) malloc (sizeof (Bina)) ;
	pBina pD = (pBina ) malloc (sizeof (Bina)) ;
	pBina pE = (pBina ) malloc (sizeof (Bina)) ;
	pBina pF = (pBina ) malloc (sizeof (Bina)) ;
	pBina pG = (pBina ) malloc (sizeof (Bina)) ;

	pA->Date = 'A' ;
	pB->Date = 'B' ;
	pC->Date = 'C' ;
	pD->Date = 'D' ;
	pE->Date = 'E' ;
	pG->Date = 'G' ;
	pF->Date = 'F' ;

	pA->p1 = pB ;
	pA->p2 = pC ;
	pB->p1 = pD ;
	pB->p2 = pE ;
	pD->p1 = pG ;
	pD->p2 = NULL ;
	pE->p1 = pE->p2 = NULL ;
	pG->p1 = pG->p2 = NULL ;
	pC->p1 = pF ;
	pC->p2 = NULL ;
	pF->p1 = NULL ;
	pF->p2 = NULL ;

	return pA ;

}

void Traverse_first (pBina Pi)
{
	printf (" %c " , Pi->Date );

	if (Pi->p1 != NULL)
		Traverse_first (Pi->p1) ;
	if (Pi->p2 != NULL)
		Traverse_first (Pi->p2) ;
}
void Traverse_secound (pBina Pi)
{

	
	if (Pi->p1 != NULL)
		Traverse_secound (Pi->p1) ;

	printf (" %c " , Pi->Date );

	if (Pi->p2 != NULL)
		Traverse_secound (Pi->p2) ;
	
}

void Traverse_third (pBina Pi) 
{
	if (Pi->p1 != NULL)
		Traverse_third (Pi->p1) ;
	if (Pi->p2 != NULL)
		Traverse_third (Pi->p2) ;

	printf (" %c " , Pi->Date );
}