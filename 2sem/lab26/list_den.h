#ifndef __LIST_DEN_H__
#define __LIST_DEN_H__

#include "list.h"

struct _list {
	ListNode *head;
	ListNode *tail;
};

struct _listnode {
	sData *data;
	ListNode *next;
	ListNode *prev;
};

struct _sdata {
	int key;
	int value;
};

void annotation();
void annotation_2();
List *merge(List *first, List *second, List *result);
List *merge_sort(List *list);
void interface_1(List *list);
void interface_2(List *list);
void two_elem_list_reverse(List *list);

#endif