#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int index_prev = 0;
	int index_next = 0;
	char element;
} Node;

typedef struct _List {
	int count = 0;
	char *nodes = NULL;
} List;

void list_add_element(List *list, char add);
List *list_create();
void list_delete_element(List *list, char del);
void list_print(List *list);
int list_lenght(List *list);

#endif