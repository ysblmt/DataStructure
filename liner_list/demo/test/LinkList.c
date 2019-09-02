#include "LinkList.h"

/* 
 *@data 2019-08-31
 *@author ys_blmt@163.com
 *@brief 涉及到链表头的操作，全部采用定义结构体局部变量来进行操作，防止破坏头节结点
 */

LinkList* LinkList_Create() /* 创建带头单链表的表头 */
{
	/* 带头单链表：数据域没有数据 */
	PT_Link Node_Header = (PT_Link)malloc(sizeof(T_Link)); /* 头指针 */
	
	assert(NULL != Node_Header);
	Node_Header->data = -1;
	Node_Header->length = 0;
	Node_Header->next = NULL;
	
	return Node_Header; /* 返回表头结点 */
}

LinkList* LinkList_CreateNode(data_t data)
{
	PT_Link NewNode = (PT_Link)malloc(sizeof(T_Link)); /* 结点指针 */
	
	assert(NULL != NewNode);
	
	NewNode->data = data;
	NewNode->next = NULL;
	
	return NewNode;
}

void LinkList_Destroy(LinkList* HeaderList)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;

	assert(NULL != ptHeaderList);
	
	if(NULL == ptHeaderList->next)
	{
		free(ptHeaderList);
	}
	else
	{
		PT_Link ret = ptHeaderList;
		while(ret->next) // 先释放其它结点
		{
			ret = ret->next;
			free(ret);
		}
		free(ptHeaderList); // 再释放头结点
	}
}

void LinkList_Clear(LinkList* HeaderList)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	
	assert(NULL != ptHeaderList);
	
	if(NULL != ptHeaderList->next)
	{
		while(ptLink->next)
		{
			ptLink = ptLink->next; 
			free(ptLink);
		}
		ptHeaderList->next = NULL;
	}
	else
	{
		ptHeaderList->next = NULL; /* 指向NULL，但是分配的空间没有释放 */
	}
}

int LinkList_Length(LinkList* HeaderList)
{
#if 0
	int num = 0;
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	
	assert(NULL != ptHeaderList);
	
	while(NULL != ptHeaderList->next)
	{
		num++;
		ptHeaderList = ptHeaderList->next;
	}
	return num;
#endif
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	assert(NULL != ptHeaderList);
	
	return ptHeaderList->length; /* 将长度数据放在头结点中，其它结点不存放 */
}

void LinkList_Insert(LinkList* HeaderList, data_t data, int cmd, int pos)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = (PT_Link)LinkList_CreateNode(data);
	int i = 0;
	
	assert((NULL != ptHeaderList) && (NULL != ptLink));
	
	ptLink->data = data;
	
	switch(cmd)
	{
		case FRONT_INSERT:
			{
				// 头插
				PT_Link pTtmp = ptHeaderList;  // 防止破坏头节结点
				if(NULL == pTtmp->next)
				{
					pTtmp->next = ptLink;
				}
				else
				{
					ptLink->next = pTtmp->next; 
					pTtmp->next = ptLink;
				} 
			}
			break;
		case END_INSERT:
			{					
				// 尾插法 
				PT_Link pTtmp = ptHeaderList;  // 防止破坏头节结点
				if(NULL == pTtmp->next)
				{
					pTtmp->next = ptLink;
				}
				else
				{ 
					while(pTtmp->next)
					{
				    	pTtmp = pTtmp->next;
					}
					pTtmp->next = ptLink;
				} 
			}
			break;
		case LOCATION_INSERT:
			{
				// 指定位置插入 
				PT_Link pTtmp = ptHeaderList;  // 防止破坏头节结点
				if((0 < pos) && (pos <= ptHeaderList->length))
				{
					for(i=1; i<pos; i++)
					{
						pTtmp = pTtmp->next;
					}
					ptLink->next = pTtmp->next;
					pTtmp->next = ptLink;
				}
			}
			break;
		default:
			printf("please enter a valid command\n");
	}
	
	ptHeaderList->length++;
}

LinkList* LinkList_Get(LinkList* HeaderList, int pos) // 返回一个结点指针
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	int i = 0; 
	
	assert(NULL != ptLink);
	
	if((pos > 0) && (pos <= ptLink->length))
	{
		for(i=0; i<pos; i++)
		{
			ptLink = ptLink->next;
		}
	}
	return ptLink;
}

LinkList* LinkList_Delete(LinkList* HeaderList, int pos)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	PT_Link tmp;
	int i = 0;
	
	assert(NULL != ptLink);
	
	if((pos > 0) && (pos <= ptLink->length))
	{
		for(i=0; i<pos-1; i++)
		{
			ptLink = (PT_Link)ptLink->next;
		}
		tmp = ptLink->next;
		ptLink->next = tmp->next;
		free(tmp);
	}
	
	ptHeaderList->length--; /* 改变头结点中的长度值 */
	
	return ptHeaderList;
}

LinkList* LinkList_FindData(LinkList* HeaderList, data_t data)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	assert(NULL != ptLink);
	
	while(ptLink->next)
	{
		if(data == ptLink->next->data)
		{
			return ptLink->next;
		}
		ptLink = ptLink->next;
	}
	return NULL;
}

void LinkList_DelelteAllData(LinkList* HeaderList, data_t data)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList->next;
	assert(NULL != ptLink);
	
	do{
		if(data == ptLink->data)
		{
			PT_Link tmp = ptLink;
			ptLink = tmp->next;
			free(tmp);
			ptHeaderList->length--;
		}
		ptLink = ptLink->next;
	}while(ptLink);
}

void LinkList_PrintReverse(LinkList* HeaderList)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	if(NULL != ptLink)
	{
		LinkList_PrintReverse(ptLink->next);
		printf("%d\n",ptLink->data);
	}
}

/* 追赶法求链表中间结点 */
LinkList* Find_InterNode(LinkList* HeaderList)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	assert(NULL != ptHeaderList);
	PT_Link FastNode = ptHeaderList;
	PT_Link SlowNode = ptHeaderList;
	
	while((NULL != FastNode) && (NULL != FastNode->next))
	{
		FastNode = FastNode->next->next;
		SlowNode = SlowNode->next;
	}
	return SlowNode;
}

/* 追赶法求倒数第N个结点 */
LinkList* Find_NthNode(LinkList* HeaderList, int n)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	assert((NULL != ptHeaderList) && (n > 0));
	PT_Link FastNode = ptHeaderList;
	PT_Link SlowNode = ptHeaderList;
	int i = 0;
	
	for(i=0; i<n-1; i++) // 先让FastNode走N-1步
	{
		if(NULL != FastNode->next)
		{
			FastNode = FastNode->next;
		}
		else
		{
			return NULL;
		}
	}
	
	while(FastNode->next) // 剩下的一起走
	{
		FastNode = FastNode->next;
		SlowNode = SlowNode->next;
	}
	return SlowNode;
}


/********************* 链表排序 ************************/
/* 冒泡排序 */
void LinkList_BubbleSort(LinkList* HeaderList)
{
#if 0
	// 冒泡排序：只适用于数据域只存在单个变量的链表
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link p;
	PT_Link q;
	for(p=ptHeaderList->next; p!=NULL; p=p->next)
	{
		for(q=p->next; q!=NULL; q=p->next)
		{
			if(p->data > q->data)
			{
				int tempdata = p->data;
				p->data = q->data;
				q->data = tempdata;
			}
		}
	}
#endif
	// 直接交换两个结点位置进行冒泡排序
}

/* 快速排序 */
LinkList* FindEndList(LinkList* HeaderList)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link ptLink = ptHeaderList;
	while(ptLink->next)
	{
		ptLink = ptLink->next;
	}
	return ptLink;
}

LinkList* FindPiovt(LinkList* ListBegin, LinkList* ListEnd)
{
	/* 前后指针法 */
	PT_Link pivot = (PT_Link)ListBegin;
	PT_Link FrontNode = (PT_Link)ListBegin; // 表头
	PT_Link ptEndList = (PT_Link)ListEnd; //表尾
	assert(NULL != FrontNode && NULL != ptEndList);
	
	PT_Link NextNode = FrontNode->next;
	
	while((FrontNode != ptEndList) && (NextNode->next != NULL))
	{
		if(NextNode->data < pivot->data)
		{
			FrontNode = FrontNode->next;
			int swap_data = FrontNode->data;
			FrontNode->data = NextNode->data;
			NextNode->data = swap_data;
		}
		
		NextNode = NextNode->next;
	}
	int data = pivot->data;
	pivot->data = FrontNode->data;
	FrontNode->data = data;
	return FrontNode;
}

void LinkList_QuickSort(LinkList* ListBegin,LinkList* ListEnd)
{
	PT_Link ptListBegin = (PT_Link)ListBegin; // 表头
	assert(NULL != ptListBegin);
	PT_Link ptEndList = (PT_Link)ListEnd; //表尾
	if(ptListBegin != ptEndList)
	{
		if(-1 == ptListBegin->data)
		{
			ptListBegin = ptListBegin->next;
		}
		PT_Link pivot = (PT_Link)FindPiovt((LinkList*)ptListBegin, (LinkList*)ptEndList);
		LinkList_QuickSort((LinkList*)ptListBegin, (LinkList*)pivot);
		LinkList_QuickSort((LinkList*)pivot->next, (LinkList*)ptEndList);
	}
}
