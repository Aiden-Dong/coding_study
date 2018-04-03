#include "binarysort.h"
#include <stdlib.h>
#include <stdio.h>

void CreateBinarySortTree (pBinaryTree * Tree , const int num)
{
	
	pBinaryTree one;

	if ((*Tree) == NULL)
	{
		// 初始化新结点
		one = (pBinaryTree) malloc (sizeof(BinaryTree));
		one->data = num;
		one->lchild = NULL;
		one->rchild = NULL;
		*Tree = one;
	}
	else if((*Tree)->data > num)  // 当父结点的数据大于 num 时候 去左子树 
	{
		//rand = (*Tree)->lchild;
		CreateBinarySortTree (&((*Tree)->lchild) , num);
	}
	else if ((*Tree)->data < num) // 当父结点的数据小于 num 时候 去右子树
	{
		CreateBinarySortTree (&((*Tree)->rchild) , num);
	}
	else
	{
		puts ("树中已经存在数据 无需再次插入");
		return;
	}

}

void TravelBinarySortTree (pBinaryTree Tree)
{
	if(Tree)
	{		
		TravelBinarySortTree (Tree->lchild); // 遍历左子树
		printf ("%d -> ",Tree->data);
		TravelBinarySortTree (Tree->rchild); // 遍历右子树
	}
	
}

int SearchBinarySortTree (pBinaryTree Tree , const int k , pBinaryTree *p)
{
	if (!Tree)
		return -1;
	else if (k == Tree->data)
	{
		(*p) = Tree ;
		return 0;
	}
	else if (k > Tree->data)
		return SearchBinarySortTree (Tree->rchild , k , p);
	else 
		return  SearchBinarySortTree (Tree->lchild , k , p);
}

/*
**********************************************************************************
 *
 *	删除操作主要分为三种情况 :
 *		1. 结点为叶子结点：
 *						当为叶子结点的时候 ，只要将叶子删掉然后将他的上一
 *						级结点置为 NULL 即可
 *
 *		2. 结点只有左子树或者右子树：
 *						当只有左子树或者只有右子树的时候 ， 将此节点删掉 ， 
 *						然后将他的下一层的子树给接上去即可
 *
 *		3. 结点既有左子树又有右子树：
 *						当既有左子树又有右子树的时候有两种处理方法 ：
 *								方法一：
 *										取左子树（下一级小值）的最右子树（最大值）
 *								方法而： 
 *										取右子树（下一级大值）的最左子树（最小值）
 *
*********************************************************************************
*/
int EarseBinarySortTree (pBinaryTree *Tree , const int k )
{
	if (!(*Tree))
		return -1;
	else
	{
		if (k == (*Tree)->data)
			return Delete(Tree);
		else if (k > (*Tree)->data)
			return EarseBinarySortTree (&((*Tree)->rchild) , k);
		else
			return EarseBinarySortTree (&((*Tree)->lchild) , k);
	}
}

int Delete (pBinaryTree *Tree)
{
	pBinaryTree T = (*Tree);
	pBinaryTree child , front= T;

	if ((*Tree)->lchild == NULL && (*Tree)->rchild == NULL)
	{
		(*Tree) = NULL;
		free (T);
	}
	else if ((*Tree)->lchild == NULL)
	{
		(*Tree) = (*Tree)->rchild;
		free (T);
	}
	else if ((*Tree)->rchild == NULL)
	{
		(*Tree) = (*Tree)->lchild;
		free(T);
	}
	else
	{
		child = (*Tree)->lchild;
		while (child->rchild != NULL)
		{
			front = child;
			child = child->rchild;
		}
		(*Tree)->data = child->data;
		
		if (front == T)
			front->lchild = child->lchild;
		else
			front->rchild = child->lchild;
		
		//front->lchild = child->lchild;
		//free(T);		
	}
}