#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef unsigned int data_t;
typedef void SeqList;
typedef void SeqListNode;

typedef struct SeqList{
	int capacity; /* 总容量大小 */
	int length; /* 当前线性表尾指针 */
	data_t data[];
}T_SeqList,*PT_SeqList; /* 定义柔性数组 */



SeqList* SeqList_Create(int data_len); /* 创建线性表(创建柔性数组) */
SeqList* SeqList_Resetplace(SeqList** List, int new_capacity); /* 重置内存空间 */
void SeqList_Destroy(SeqList* List);
void SeqList_Clean(SeqList* List);
int SeqList_Length(SeqList* List); /* 获取当前包含数据的长度 */
int SeqList_capacity(SeqList* List);
int SeqList_Insert(SeqList* List, SeqListNode* node, int pos);
SeqListNode* SeqList_Get(SeqList* List, int pos);
SeqListNode* SeqList_Delete(SeqList* List, int pos);

#endif
