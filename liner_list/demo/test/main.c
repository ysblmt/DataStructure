#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	PT_Link list = LinkList_Create();
	int i = 0;
	
	LinkList_Insert(list, 9, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 20, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 3, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 8, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 1, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 17, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 26, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 5, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 13, END_INSERT, POS_EMPTY);
	LinkList_Insert(list, 12, END_INSERT, POS_EMPTY);
	
	PT_Link ret = (PT_Link)FindEndList(list);
	
	printf("the end data = %d\n",ret->data);
	
	LinkList_QuickSort(list, ret);
	
	for(i=1; i<=LinkList_Length(list); i++)
	{
		printf("data[%d] = %d\n",i,((PT_Link)LinkList_Get(list, i))->data);
	}
	
	
	return 0;
}

