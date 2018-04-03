#ifndef BINARYSORT_H_
#define BINARYSORT_H_

//	平衡二叉树

#define LH 1
#define EH 0
#define RH -1

// 二叉树结构
typedef struct _BinaryTree
{
	int data;					 // 关键字
	int bf ;					 // 平衡因子	
	struct _BinaryTree *lchild;  // 左子树
	struct _BinaryTree *rchild;  // 右子树
}BinaryTree , *pBinaryTree;

// 构建平衡二叉树
int CreateBinarySortTree (pBinaryTree * Tree , const int num , int * taller);

// 遍历平衡二叉树二叉树 （中序遍历）
void TravelBinarySortTree (pBinaryTree Tree);

// 递归查找二叉排序树
int SearchBinarySortTree (pBinaryTree Tree , const int k , pBinaryTree *p);

// 左平衡代码
void LeftBalance (pBinaryTree *Tree);

// 右平衡代码
void RightBalance (pBinaryTree *Tree);

// 左旋转代码
void L_Rotate (PBinaryTree *Tree);

#endif