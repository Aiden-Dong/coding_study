#include <stdio.h>
#include <stdlib.h>

// 实现两个顺序表的归并

typedef struct _List
{
	int * elem ;
	int length ;
	int listsize;
}List , *pList;

void MerginList (pList p1 , pList p2 , pList p3);
void InitList (pList p);

int main ()
{
	int i ;

	List L1 , L2 , L3;
	InitList (&L1);
	L1.length = 7;
	InitList (&L2);
	L2.length = 9;
	for (i  = 0 ; i < L1.length ; i++)
		L1.elem[i] = i*2+1;
	for (i = 0 ; i < L2.length ; i++)
		L2.elem[i] = i*1+5;

	puts ("L1 :");
	for (i  = 0 ; i < L1.length ; i++)
		printf (" %d ",L1.elem[i]);
	printf ("\n");

	puts ("L2 :");
	for (i  = 0 ; i < L2.length ; i++)
		printf (" %d ",L2.elem[i]);
	printf ("\n");

	MerginList (&L1 , &L2 , &L3);

	puts ("L3 :");

	for (i = 0 ; i < L3.length ; i++)
		printf (" %d ",L3.elem[i]);
	printf ("\n");


	return 0;
}

void MerginList (pList p1 , pList p2 , pList p3)
{
	int i=0 , j = 0;
	int *p ;
	int listsize = p1->length + p2->length;

	p3->elem = (int *)malloc(listsize*sizeof(int));
	p3->length = listsize;
	p3->listsize = listsize;

	p = p3->elem ; 

	while (i < p1->length && j < p2->length)
	{
		if (p1->elem[i] < p2->elem[j])
		{
			(*p) = p1->elem [i];
			i++;
			p++;
		}
		else
		{
			(*p) = p2->elem[j];
			j++;
			p++;
		}

	}

	while (i < p1->length)
	{
		(*p) = p1->elem [i];
		i++;
		p++;
	}
	while (j < p2->length)
	{
		(*p) = p2->elem [j];
		j++;
		p++;
	}
}

void InitList (pList p)
{
	p->elem = (int *) malloc (sizeof(int)*10);
	p->length = 0;
	p->listsize = 10;
}