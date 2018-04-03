#ifndef SSTABLE_H_
#define SSTABLE_H_

// 静态查找表
typedef struct _ssTable
{
	int Market ; // 标志关键字
	char name[10];
}ssTable , *pssTable;

// 创建 查找表
void Create (pssTable table , int n);

// 从查找表中 查找某个记录并返回
int Traverse (pssTable table,int n ,const char *str );

#endif
