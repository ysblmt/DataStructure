#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FRONT_INSERT 0
#define END_INSERT 1
#define LOCATION_INSERT 2
#define POS_EMPTY -1

typedef void LinkList;
typedef unsigned int data_t;

typedef struct Link {
	data_t data; /* 数据域 */
	int length; /* 表尾 */
	struct Link *next; /* 指针域 */
}T_Link,*PT_Link;

LinkList* LinkList_Create(); /* 创建带头单链表的表头：返回表头结点指针 */
LinkList* LinkList_CreateNode(data_t data); /* 创建结点 */
void LinkList_Destroy(LinkList* HeaderList); /* 销毁链表 */
void LinkList_Clear(LinkList* HeaderList); /* 清空链表 */
int LinkList_Length(LinkList* HeaderList); /* 获取链表长度 */
void LinkList_Insert(LinkList* HeaderList, data_t data, int cmd, int pos); /* 插入数据元素 */
LinkList* LinkList_Get(LinkList* HeaderList, int pos); /* 获取数据元素 */
LinkList* LinkList_Delete(LinkList* HeaderList, int pos); /* 删除数据元素 */
void LinkList_PrintReverse(LinkList* HeaderList); /* 逆向打印 */
LinkList* Find_InterNode(LinkList* HeaderList);
LinkList* Find_NthNode(LinkList* HeaderList, int n);
void LinkList_BubbleSort(LinkList* HeaderList);
LinkList* FindEndList(LinkList* HeaderList);
LinkList* FindPiovt(LinkList* ListBegin, LinkList* ListEnd);
void LinkList_QuickSort(LinkList* ListBegin,LinkList* ListEnd);

#endif
