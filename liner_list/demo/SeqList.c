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
	PT_SeqList gt_List = (PT_SeqList)List;
	
	assert(NULL != gt_List);
	
	gt_List->length = 0;
}

int SeqList_Length(SeqList* List) /* ��ȡ��ǰ�������ݵĳ��� */
{
	PT_SeqList gt_List = (PT_SeqList)List;
	int ret = -1;
	
	if(gt_List != NULL)
	{
		ret = gt_List->length;
	}
	return ret;
}


int SeqList_capacity(SeqList* List)
{
	PT_SeqList gt_List = (PT_SeqList)List;
	int ret = -1;
	
	if(gt_List != NULL)
	{
		ret = gt_List->capacity;
	}
	return ret;
}

int SeqList_Insert(SeqList* List, SeqListNode* node, int pos)
{
	/* ������Ԫ�غ����Ԫ�غ���һ��λ��->����Ԫ�ؼ�1->���Ա��ȼ�1 */
	PT_SeqList gt_List = (PT_SeqList)List;
	assert(gt_List != NULL);
	int ret = -1;
	int i = 0;
	
	if((gt_List->length + 1 <= gt_List->capacity) && (0 <= pos))
	{
		if(pos >= gt_List->length)
		{
			pos = gt_List->length;
		}
		
		for(i=gt_List->length; i>pos; i--)
		{
			gt_List->data[i] = gt_List->data[i-1]; /* ���Ƹ�ֵ */
		}
		
		gt_List->data[i] = (*(data_t *)node);
		
		gt_List->length++;
		
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
	PT_SeqList gt_List = (PT_SeqList)List;
	SeqListNode* ret = NULL;
	
	assert(gt_List != NULL);
	
	if((0 <= pos) && (pos < gt_List->length))
	{
		ret = (SeqListNode *)&(gt_List->data[pos]);
	}
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* List, int pos)
{
	PT_SeqList gt_List = (PT_SeqList)List;
	SeqListNode* ret = SeqList_Get(List, pos);
	
	assert(ret != NULL);
	
	for(int i=pos+1; i<gt_List->length; i++)
	{
		gt_List->data[i-1] = gt_List->data[i];
	}
	
	gt_List->length--;
	
	return ret;
}
