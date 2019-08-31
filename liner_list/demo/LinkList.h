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
	int length;
	struct Link *next; /* 指针域 */
}T_Link,*PT_Link;

LinkList* LinkList_Create(); /* 创建带头单链表的表头 */
LinkList* LinkList_CreateNode(data_t data);
void LinkList_Destroy(LinkList* HeaderList);
void LinkList_Clear(LinkList* HeaderList);
int LinkList_Length(LinkList* HeaderList);
void LinkList_Insert(LinkList* HeaderList, data_t data, int cmd, int pos); /* 头插法保持指针固定在表头 */
LinkList* LinkList_Get(LinkList* HeaderList, int pos);
LinkList* LinkList_Delete(LinkList* HeaderList, int pos);

#endif
