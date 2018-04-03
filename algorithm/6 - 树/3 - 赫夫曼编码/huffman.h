#ifndef HUFFMAN_H_
#define HUFFMAN_H_

// 存放赫夫曼树的结点
typedef struct _Huffman
{
	char data;          // 存放数据
	int Weight;         // 存放权值 
	int parent ; // 存放父结点
    int lchild , rchild; // 存放左右子结点
	
}Huffman , *pHuffman;

// 存放数据原始队列
typedef struct _HuffQue
{
	char data ; // 存放数据值
	int Weight; // 存放权值
	struct _HuffQue * next; // 存放下一个结点
}HuffQue , *pHuffQue;

// 存放队列中的待建立赫夫曼树的结点
typedef struct _HuTree
{
	int Num ;      // 存放结点数量 
	pHuffQue Tree; // 存放结点队列
}HuTree , *pHuTree; 

// 初始化赫夫曼队列,将字符以及权值组建完毕
void InitHuffQue(pHuTree one , const char ch);
// 初始化赫夫曼树带插入元素队列
void InitHuffTree (pHuffman * Tree,pHuTree Que);
// 从结点数组中查找最小的两个值
void BinaryTree (pHuffman Tree , int i , int *a , int *b , int*Market);
// 建立赫夫曼树 并返回头结点指针
int HuffmanTree (pHuffman Tree, int * Market);
// 求出赫夫曼编码
void HuffCoding (pHuffman Tree , char ** Coding);
// 遍历赫夫曼树结构
void TraHuffTree (pHuffman Tree);



#endif