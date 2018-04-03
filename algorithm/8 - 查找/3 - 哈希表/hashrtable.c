#include <stdio.h>
#include "hashtable.h"
#include <stdlib.h>

int InitHashTable (pHashTable Hash)
{
	int i ;
	Hash->count = HASHSIZE;
	Hash->elem = (int *)malloc(HASHSIZE * sizeof(int));

	if (Hash->elem == NULL)
	{
		puts("内存分配错误");
		return -1;
	}

	// 初始化每一个数组元素
	for (i = 0 ; i < HASHSIZE ; i++)
		Hash->elem[i] = NULLKEY;

	return 0;
}

int Hash (int Key)
{
	return Key % HASHSIZE ;
}

void InsertHash (pHashTable Hash , int key)
{
	int addr ;
	addr = Hash (key);
	while (Hash->elem[addr] != NULLKEY)
		addr = (addr +1) %HASHSIZE;
	Hash->elem[addr] = key;
}

int searchHash (pHashTable Hash , int key , int *addr )
{
	*addr = Hash(key);  // 使用哈希函数查找 
	while (Hash->elem[*addr] != key)
	{
		*addr = (*addr+1) % HASHSIZE;
		if (Hash->elem[*addr] == NULLKEY || *addr == Hash(key))
			return -1;
	}

	return 0;
}