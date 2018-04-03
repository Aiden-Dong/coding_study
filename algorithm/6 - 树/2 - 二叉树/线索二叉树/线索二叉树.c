#include <stdio.h>
#include <stdlib.h>


// 线索二叉树标志位
// Link(0) 表示左右孩子的指针
// Thread(1) 表示指向前驱后继的线索
typedef enum {Link , Thread} PointerTag;


typedef struct _BinaryTree
{
	char data; // 数据存放
	struct _BinaryTree *lchild; // 左孩子结点
	struct _BinaryTree *rchild; // 右孩子结点
	PointerTag ltag;            // 左标志位
	PointerTag rtag;            // 右标志位
}BinaryTree , *pBinaryTree; 

// 全局变量 记录遍历的前一个结点
pBinaryTree pre ;

// 使用前序遍历方式创建二叉树
void CreateBiTree (pBinaryTree * one);  

// 为中序遍历线索化做初始化设置
void InitThreading (pBinaryTree * one , pBinaryTree T);

// 中序遍历二叉树 创建线索化
void TraBiTree (pBinaryTree one);       

// 中序遍历二叉树，非递归法
void TravelBinaryTree (pBinaryTree T);

int main ()
{
	pBinaryTree one , P;

	CreateBiTree (&one);	
	InitThreading (&P,one);

	puts ("中序遍历结果 :");
	TravelBinaryTree (P);
	return 0;
}

void CreateBiTree (pBinaryTree * one)
{
	char ch = getchar ();

    // 以 # 作为终结循环标志 
	if (ch != '#')  
	{
		if (ch == ' ')
			(*one) = NULL;
		else
		{
			(*one) = (pBinaryTree) malloc (sizeof(BinaryTree));  // 首先分配内存 为数据存放做准备
			(*one)->data  = ch;									 // 存放数据 
			(*one)->ltag = Link;								 // 将新的数据块的左右标志位设置为指向左右孩子
			(*one)->rtag = Link;

			CreateBiTree (&(*one)->lchild);						// 进入下一个递归
			CreateBiTree (&(*one)->rchild);
		}
	}
}

// 线索化的初始化条件
void InitThreading (pBinaryTree * P , pBinaryTree one)
{
	// 初始化 p 指针 申请内存区 
	(*P) = (pBinaryTree) malloc (sizeof(BinaryTree));
	(*P)->ltag = Link;       // 左子树标记为指向左孩子 
	(*P)->rtag = Thread;     // 右子树标记为指向后驱
	(*P)->rchild = *P;       // 右子树初始化为指向自身

	// 如果二叉树为空的话 , p 的左子树为指向空
	if (!one)
	{
		(*P)->lchild = one;
	}

	else
	{
		(*P)->lchild = one;  // p 的左子树为指向要线索化的二叉树
		pre = *P;            // 将全局变量 pre 初始化为指向 P
		TraBiTree (one);     // 对 one 进行线索化 
		pre->rchild = *P;    // 将 one 最后一个结点的右子树指向为 p
		pre->rtag = Thread;
		(*P)->rchild = pre;  // 将 p 的右子树指向为最后一个结点
	}
}

// 线索化的核心实现代码
void TraBiTree (pBinaryTree one)
{
	if(one != NULL)
	{
		// 递归访问最左子树
		TraBiTree (one->lchild);  

		// 如果该结点的左子树为空 ，  设置左标志位为 指向前驱 ， 并把lchild 设置为前一个访问的结点
		if (one->lchild == NULL) 
		{
			one->ltag = Thread ;
			one->lchild = pre;  
		}
		// 如果前一个结点的右子树为空 ， 则设置 ，右标志位为 指向后继 , 并把 rchild 设置为当前结点
		if (pre->rchild == NULL)
		{ 
			pre->rtag = Thread;
			pre->rchild = one;
		}

		// 将当前的结点保留为下一次的上一个结点
		pre = one;

		// 访问右子树
		TraBiTree (one->rchild);
	
	}
}


void TravelBinaryTree (pBinaryTree T)
{
	pBinaryTree p;

	// 将 p 指向二叉树的头结点
	p = T->lchild;

	// 将 标志结点作为终结标志
	while (p != T)
	{ 
		// 访问最左的孩子
		while (p->ltag == Link)
			p = p->lchild; 
		printf ("%c -> ",p->data);

		// 循环访问后继元素
		while (p->rtag == Thread && p->rchild != T)  // 重点处
		{
			p = p->rchild;
			printf ("%c -> ",p->data);
		}

		// 访问 左子树
		p=p->rchild;
	}

	printf ("End\n");
}