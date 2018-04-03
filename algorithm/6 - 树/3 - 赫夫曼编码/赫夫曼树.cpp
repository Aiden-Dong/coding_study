#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "huffman.h"

int main ()
{
	int i ;
	HuTree one = {0 , NULL}; // 建立一个队列指针
	pHuffman Tree = NULL;    // 赫夫曼结点数组
	int * Market = NULL;     // 用于做标记
	char ** Cording;		 // 赫夫曼编码
	FILE *fp ;               
	fp = fopen ("huffman.txt","w");
	FILE *fin;
	fin = fopen ("赫夫曼文件.txt","r");
	FILE *fout ;
	fout = fopen("加密文件.txt","w");
	FILE *ffout;
	ffout = fopen ("解密文件.txt","w");

	if (fin == NULL)
	{
		puts("error to open file!!");
		return 0;
	}

	// 将 赫夫曼文件 读入并建立字符队列
	char b;
	while((b = fgetc(fin)) != EOF)
	{
		InitHuffQue (&one , b);
	}

	// 建立标记位 并初始化
	Market = (int *)malloc(2*one.Num * sizeof(int));
	for (i = 0 ; i < 2*one.Num ; i++)
		Market[i] = 0;
	// 初始化密码结构
	Cording = (char **) malloc ((one.Num+1)*sizeof(char*));
	// 将队列的值赋给赫夫曼结点数组
	InitHuffTree (&Tree , &one);
	// 组建赫夫曼树
	int First = HuffmanTree (Tree,Market);
	// 建立赫夫曼编码
	HuffCoding (Tree , Cording);

	rewind (fin);

	char c;
	while((c = fgetc(fin))!= EOF)
	{
		for (i = 1 ; i <= one.Num ; i++)
		{
			if (c == Tree[i].data)
			{
				fprintf (fout,"%s",Cording[i]);
				continue;
			}
		}
	}

	for (i = 1 ; i <= one.Num ; i++)
		fprintf (fp , "%c -- %s\n",Tree[i].data , Cording[i]);

	fclose (fp);
	fclose (fin);
	fclose (fout);

	FILE *ffin = fopen ("加密文件.txt","r");
	
	char ch;
	
	while (ch != EOF)
	{
		int Head = First ;
		
		while (Tree[Head].data == -1 && (ch = fgetc(ffin)) !=EOF )
		{
			if (ch == '0')
				Head = Tree[Head].lchild;
			else if (ch == '1')
				Head = Tree[Head].rchild;
		}

		if (Tree[Head].data !=-1)
			fprintf (ffout,"%c",Tree[Head].data);

	}	
	
	fclose (fin);
	fclose (ffout);
	return 0;
}

