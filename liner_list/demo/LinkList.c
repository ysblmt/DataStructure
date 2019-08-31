#include "LinkList.h"

LinkList* LinkList_Create() /* 创建带头单链表的表头 */
{
	/* 带头单链表：数据域没有数据 */
	PT_Link Node_Header = (PT_Link)malloc(sizeof(T_Link)); /* 头指针 */
	
	assert(NULL != Node_Header);
	Node_Header->length = 0;
	Node_Header->next = NULL;
	
	return Node_Header;
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
	
	return ptHeaderList->length;
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
				if(NULL == ptHeaderList->next)
				{
					ptHeaderList->next = ptLink;
				}
				else
				{
					ptLink->next = ptHeaderList->next; 
					ptHeaderList->next = ptLink;
				} 
			}
			break;
		case END_INSERT:
			{					
				// 尾插法 
				if(NULL == ptHeaderList->next)
				{
					ptHeaderList->next = ptLink;
				}
				else
				{ 
					PT_Link ret = ptHeaderList;  // 为了防止程序数据更新出错，需要进行数据获取 
					while(ret->next)
					{
				    	ret = ret->next;
					}
					ret->next = ptLink;
				} 
			}
			break;
		case LOCATION_INSERT:
			{
				// 指定位置插入  
				if((0 < pos) && (pos <= ptHeaderList->length))
				{
					PT_Link ret = ptHeaderList;
					for(i=1; i<pos; i++)
					{
						ret = ret->next;
					}
					ptLink->next = ret->next;
					ret->next = ptLink;
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
	int i = 0; 
	
	assert(NULL != ptHeaderList);
	
	if((pos > 0) && (pos <= ptHeaderList->length))
	{
		for(i=0; i<pos; i++)
		{
			ptHeaderList = (PT_Link)ptHeaderList->next;
		}
	}
	return ptHeaderList;
}

LinkList* LinkList_Delete(LinkList* HeaderList, int pos)
{
	PT_Link ptHeaderList = (PT_Link)HeaderList;
	PT_Link tmp;
	int i = 0;
	
	assert(NULL != ptHeaderList);
	
	if((pos > 0) && (pos <= ptHeaderList->length))
	{
		for(i=0; i<pos-1; i++)
		{
			ptHeaderList = (PT_Link)ptHeaderList->next;
		}
		tmp = ptHeaderList->next;
		ptHeaderList->next = tmp->next;
		free(tmp);
	}
	
	ptHeaderList->length--;
	
	return ptHeaderList;
}

