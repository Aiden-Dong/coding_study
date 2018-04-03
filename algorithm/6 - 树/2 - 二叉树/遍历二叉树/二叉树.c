#include <stdio.h>

typedef struct _BinaryTree
{
	char data; // 数据存放
	struct _BinaryTree *lChild ; // 左孩子
	struct _BinaryTree *rChild ; // 右孩子 
}BinaryTree,*pBinaryTree; // 二叉树

void InitStack(pBinaryTree * tree );
void TravelStackFirst (pBinaryTree tree);

int main ()
{
	pBinaryTree one;
	puts ("请建立树结构 : ");

	InitStack(&one );
	TravelStackFirst(one);

	return 0;
}
void InitStack(pBinaryTree * tree )
{
	char sl = getchar ();
	if (sl != '#')
	{
		if (sl == ' ')
		{
			(*tree) = NULL;
		}
		else
		{
			(*tree) = (pBinaryTree) malloc (sizeof(BinaryTree));
			(*tree)->data = (sl);
			InitStack (&((*tree)->lChild) );
			InitStack (&((*tree)->rChild) );

		}
	}
}

void TravelStackFirst (pBinaryTree tree)
{
	if (tree != NULL)
	{
		printf (" %c ->",tree->data);
		TravelStackFirst(tree->lChild);
		TravelStackFirst(tree->rChild);
	}
}

