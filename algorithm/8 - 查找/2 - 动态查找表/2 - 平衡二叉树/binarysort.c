#include "binarysort.h"
#include <stdlib.h>
#include <stdio.h>

int CreateBinarySortTree (pBinaryTree * Tree , const int num , int * taller)
{
	if (!*Tree)		// 当寻到 叶子结点的时候 说明已经找到了插入位置 
	{
		*Tree = (pBinaryTree) malloc (sizeof(BinaryTree));
		(*Tree)->data = num;
		(*Tree)->rchild = (*Tree)->lchild = NULL;
		(*Tree)->bf = EH;
		(*taller) = 1 ;
	}
	else
	{
		if (num == (*Tree)->data)      // 如果查找到有这么一个数据 则放弃插入数据 返回 0 
		{
			*taller = 0;
			return 0;
		}

		else if (num < (*Tree)->data)  // 进行左子树的查找过程
		{
			// 如果插入失败 则递归结束后则 直接层层退栈 结束函数调用
			if (!CreateBinarySortTree (&(*Tree)->lchild , num , taller))
				return 0 ; 

			if (*taller)               // 插入新元素成功
			{
				switch ((*Tree)->bf)  
				{
				case LH :              // 原左子树高度高于右子树
					LeftBalance (Tree); 
					// 如果是原先就已经左边高 则必须进行作调整 因为插入了一个元素之后 
					// 就会造成 平衡树 “紊乱”
					*taller = 0;
					break;
				case EH:               // 原左右子树处于平衡状态
					(*Tree)->bf = LH;
					*taller = 1;
					break;
				case RH:               // 原右子树高度高于左子树
					(*Tree)->bf = EH;
					*taller = 0;      // 添加左子树后 左右平衡状态
					break;
				}
			}
		}

		else
		// 
		{
			if (!CreateBinarySortTree (&(*Tree)->rchild , num , taller))
				return 0 ;
			if (*taller)
			{
				switch ((*Tree)->bf)
				{
				case LH :  // 如果是左边高
					(*Tree)->bf = EH;
					*taller = 0;
					break;
				case EH:   // 如果是右边高
					(*Tree)->bf = RH;
					*taller = 1;
					break;
				case RH:
					RightBalance (Tree);
					*taller = 0;
					break;

				}
			}
		}
	}
}

// 执行 做平衡操作
// Tree 是引起紊乱的根节点
void LeftBalance (pBinaryTree *Tree) 
{
	pBinaryTree L , Lr ; 
	
	// L为 根节点的左子树
	L = (*Tree)->lchild ;

	// 探测 L 的 平衡因子
	switch (L->bf)
	{
		// 说明根节点左子树存在左子树 深度大于右子树
	case LH:
		(*Tree)->bf = L->bf = EH ;
		R_Rotate (Tree);
		break;

		// 说明左子树存在右子树 深度大于左子树
	case RH:
		// Lr 赋值为 左子树的右子树
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case LH:
			(*Tree)->bf = RH;
			L->bf = EH ;
			break;
		case EH:
			(*Tree)->bf = L->bf = EH ;
			break;
		case RH:
			(*Tree)->bf = EH ;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		
		// 先对 根结点左子树进行左旋 后对跟结点执行右旋
		L_Rotate(&(*Tree)->lchild);  
		R_Rotate(Tree); 
	}

}
void L_Rotate (pBinaryTree *Tree)
{
	pBinaryTree rc = (*Tree)->rchild ;
	p->rchild = 
}

