#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef unsigned int data_t;

typedef struct Link {
	data_t data; /* 数据域 */
	struct Link *next; /* 指针域 */
}T_Link,*PT_Link;

#endif
