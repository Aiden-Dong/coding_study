#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "huffman.h"


// 初始化赫夫曼队列 ， 将每一个字符的使用频率跟字符信息组合在一起， 并建立队列
void InitHuffQue(pHuTree one , const char ch)
{
	pHuffQue Tra = one->Tree;
	pHuffQue Insert;

	while (Tra != NULL)
	{
		// 如果在队列中查到字符的存在则将字符的频率加一
		if (Tra->data == ch)
		{
			Tra->Weight ++;
			break;
		}

		Tra = Tra->next;
	}

	// 说明是一个新的字符并不在原始队列中 ， 则分配内存插入到队列中，并存储新字符的信息
	if (Tra == NULL)
	{
		one->Num++;
		Insert = (pHuffQue)malloc(sizeof(HuffQue));
		Insert->data = ch;
		Insert->Weight = 1;
	
		Insert->next = one->Tree;
		one->Tree = Insert;
	}
}

// 将字符频率及信息转化为赫夫曼结点数组 并 建立n-1个中间结点用于链接叶子结点
void InitHuffTree (pHuffman * Tree,pHuTree Que)
{
	// 分配 Que->Num*2+1 个树节点 使得前n 个为叶子结点 ,后n-1个为中间结点
	(*Tree) = (pHuffman)malloc((Que->Num*2)*sizeof(Huffman));   
	if (*Tree == NULL)
	{
		puts("error to malloc some memery space !!");
		return ;
	}
	
	pHuffQue Tra=Que->Tree;
	(*Tree)[0].Weight = Que->Num;

	// 初始化叶子结点将子结点以及父结点暂时存储为 -1
	for (int i = 1 ; i <= Que->Num ; i++)
	{
		(*Tree)[i].data = Tra->data;
		(*Tree)[i].Weight = Tra->Weight;
		(*Tree)[i].lchild = -1;
		(*Tree)[i].rchild = -1;
		(*Tree)[i].parent = -1;
		Tra = Tra->next;
	}
	
	// 初始化叶子结点
	for(i = Que->Num+1 ; i < Que->Num*2 ; i++)
	{
		(*Tree)[i].data = -1;
		(*Tree)[i].Weight = -1;
		(*Tree)[i].lchild = -1;
		(*Tree)[i].rchild = -1;
		(*Tree)[i].parent = -1;
	}
}
// 从赫夫曼数组中找到叶子结点中权值最小的两个结点 并返回他的位置
void BinaryTree (pHuffman Tree , int i , int *a , int *b,int*Market)
{
	int x , y;
	int j ;

	// 找寻最初的可以比较的第一个字符的位置
	for (x = 1 ; x <= i ; x++)
	{
		if (Market[x] == 0)
			break;
	}

	// 遍历比较 找权值最小并且标志位为0 的叶子结点 并将标志为重置为1
	for (j = 1 ; j <= i; j++)
	{
		if (Tree[j].Weight< Tree[x].Weight && Market[j]==0)
			x = j;
	}
	Market[x] = 1;

	// 找寻第二个位置 与以上相同
	for (y = 1 ; y <= i ; y++)
		{
			if (Market[y] == 0)
				break;
		}
	for (j = 1 ; j <= i ; j++)
	{
		if (Tree[j].Weight<Tree[y].Weight && Market[j]==0)
			y = j;
	}
	Market[y] = 1;

	(*a)=x , (*b)=y;
}

// 组建赫夫曼树 ， 按照 左子树为0 右子树为1 的原则 
int HuffmanTree (pHuffman Tree , int * Market)
{
	int  i , a , b ; // 用于随机遍历数组元素
	
	// 建立赫夫曼树 
	for (i = Tree[0].Weight+1 ; i < 2*Tree[0].Weight ; i++)
	{
		// 从前i -1 个结点中寻找两个权值最小的结点 并且将第i个结点与以上两个结点链接
		BinaryTree (Tree , i-1 , &a , &b ,Market);  
		Tree[i].lchild = a;
		Tree[i].rchild = b;
		Tree[i].Weight = Tree[a].Weight+Tree[b].Weight; 
		Tree[a].parent = i;
		Tree[b].parent = i;  
	}

	// 返回根节点位置
	return i-1;
}


// 将每个叶子结点字符的赫夫曼编码写出来
void HuffCoding (pHuffman Tree , char ** Coding)
{
	char str[200];
	int Front ;
	int Tra = 1;
	// 查找每一个叶子结点 使用逆序
	for (Tra = 1 ; Tra <= Tree[0].Weight ; Tra++)
	{
		char *ptr = &str[198];
		memset(str,0,sizeof(str));
		for (Front = Tra ; Front != -1 ; Front = Tree[Front].parent)
		{
			if (Tree[Tree[Front].parent].lchild ==Front)	
			{
				(*ptr) = '0';
				ptr--;
			}
			if(Tree[Tree[Front].parent].rchild ==Front)
			{
				(*ptr) = '1';
				ptr--;
			}
		}
		int len = strlen(++ptr);

		Coding[Tra] = (char *)malloc(len*sizeof(char));
		strcpy (Coding[Tra] , ptr);
	}
}

void TraHuffTree (pHuffman Tree)
{
	int Num = Tree[0].Weight*2;

	for (int i = 0 ; i < Num ; i++)
	{
		printf ("%c -- %d -- %d -- %d -- %d\n",
			Tree[i].data , Tree[i].Weight , Tree[i].parent , Tree[i].lchild , Tree[i].rchild);
	}
}