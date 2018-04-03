#ifndef BINARYSORT_H_
#define BINARYSORT_H_

//	查找二叉树


// 二叉树结构
typedef struct _BinaryTree
{
	int data;                    // 关键字
	struct _BinaryTree *lchild;  // 左子树
	struct _BinaryTree *rchild;  // 右子树
}BinaryTree , *pBinaryTree;

// 构建查找二叉树
void CreateBinarySortTree (pBinaryTree * Tree , const int num);

// 遍历二叉树 （中序遍历）
void TravelBinarySortTree (pBinaryTree Tree);

// 递归查找二叉排序树
int SearchBinarySortTree (pBinaryTree Tree , const int k , pBinaryTree *p);

// 删除二叉树的结点
int EarseBinarySortTree (pBinaryTree *Tree , const int k );

// 判断删除位置并执行删除操作
int Delete (pBinaryTree *Tree);

#endif