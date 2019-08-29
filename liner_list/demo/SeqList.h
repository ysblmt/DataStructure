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
	int capacity; /* ��������С */
	int length; /* ��ǰ���Ա�βָ�� */
	data_t data[];
}T_SeqList,*PT_SeqList; /* ������������ */



SeqList* SeqList_Create(int data_len); /* �������Ա�(������������) */
SeqList* SeqList_Resetplace(SeqList** List, int new_capacity); /* �����ڴ�ռ� */
void SeqList_Destroy(SeqList* List);
void SeqList_Clean(SeqList* List);
int SeqList_Length(SeqList* List); /* ��ȡ��ǰ�������ݵĳ��� */
int SeqList_capacity(SeqList* List);
int SeqList_Insert(SeqList* List, SeqListNode* node, int pos);
SeqListNode* SeqList_Get(SeqList* List, int pos);
SeqListNode* SeqList_Delete(SeqList* List, int pos);

#endif
