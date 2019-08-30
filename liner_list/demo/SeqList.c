#include "SeqList.h"


SeqList* SeqList_Create(int capacity) /* �������Ա�(������������) */
{
	PT_SeqList ret = NULL;
	if(capacity > 0)
	{
		ret = (PT_SeqList)malloc(sizeof(*ret) + sizeof(*(ret->data))*capacity);
		assert(NULL != ret);
		ret->capacity = capacity;
		ret->length = 0; /* δ������� */
	}
	return ret;
}

/* ���õ�ǰ���� */
SeqList* SeqList_Resetplace(SeqList** List, int new_capacity)
{
	PT_SeqList pt = NULL;
	PT_SeqList tmp = NULL;
	PT_SeqList* ret = (PT_SeqList *)List; /* Q1:Ϊʲô&(*(PT_SeqList)List)���� */
	
	assert(NULL != List);
	
	if((ret != NULL) && (new_capacity > 0) && ((*ret)->length <= new_capacity))
	{
		pt = (PT_SeqList)malloc(sizeof(*pt) + sizeof(*(pt->data)) * new_capacity);
		tmp = pt;
		int len = ((*ret)->capacity < new_capacity)?(*ret)->capacity:new_capacity;
		
		for(int i = 0; i < len; i++)
		{
			tmp->data[i] = (*ret)->data[i];
		}
		
		tmp->length = (*ret)->length;
		tmp->capacity = new_capacity;
		
		free(*List);
	}
	*List = pt;
	return pt;
}

void SeqList_Destroy(SeqList* List)
{
	free(List);
}

void SeqList_Clean(SeqList* List)
{
	PT_SeqList ptList = (PT_SeqList)List;
	
	assert(NULL != ptList);
	
	ptList->length = 0;
}

int SeqList_Length(SeqList* List) /* ��ȡ��ǰ�������ݵĳ��� */
{
	PT_SeqList ptList = (PT_SeqList)List;
	int ret = -1;
	
	if(ptList != NULL)
	{
		ret = ptList->length;
	}
	return ret;
}


int SeqList_capacity(SeqList* List)
{
	PT_SeqList ptList = (PT_SeqList)List;
	int ret = -1;
	
	if(ptList != NULL)
	{
		ret = ptList->capacity;
	}
	return ret;
}

int SeqList_Insert(SeqList* List, SeqListNode* node, int pos)
{
	/* ������Ԫ�غ����Ԫ�غ���һ��λ��->����Ԫ�ؼ�1->���Ա��ȼ�1 */
	PT_SeqList ptList = (PT_SeqList)List;
	assert(ptList != NULL);
	int ret = -1;
	int i = 0;
	
	if((ptList->length + 1 <= ptList->capacity) && (0 <= pos))
	{
		if(pos >= ptList->length)
		{
			pos = ptList->length;
		}
		
		for(i=ptList->length; i>pos; i--)
		{
			ptList->data[i] = ptList->data[i-1]; /* ���Ƹ�ֵ */
		}
		
		ptList->data[i] = (*(data_t *)node);
		
		ptList->length++;
		
		ret = 0;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

SeqListNode* SeqList_Get(SeqList* List, int pos)
{
	PT_SeqList ptList = (PT_SeqList)List;
	SeqListNode* ret = NULL;
	
	assert(ptList != NULL);
	
	if((0 <= pos) && (pos < ptList->length))
	{
		ret = (SeqListNode *)&(ptList->data[pos]);
	}
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* List, int pos)
{
	PT_SeqList ptList = (PT_SeqList)List;
	SeqListNode* ret = SeqList_Get(List, pos);
	
	assert(ret != NULL);
	
	for(int i=pos+1; i<ptList->length; i++)
	{
		ptList->data[i-1] = ptList->data[i];
	}
	
	ptList->length--;
	
	return ret;
}
