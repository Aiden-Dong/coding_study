#ifndef HASHTABLE_H_
#define HASHTABLE_H_

// 定义哈希表的大小 
#define HASHSIZE 12 
#define NULLKEY -32768

// 哈希表结构
typedef struct _HashTable
{
	int * elem ; // 元素基址 ， 动态分配数组
	int count ;  //当前数组元素个数 
} HashTable , *pHashTable ;


//  初始化哈希表 
int InitHashTable (pHashTable Hash);

// 实用化除留余数法 来构造 哈希函数
int Hash (int Key);

// 将关键字插入哈希表
void InsertHash (pHashTable Hash , int key);

// 在哈希表中查找关键字
int searchHash (pHashTable Hash , int key , int *addr );

#endif