#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int POOL_SIZE = 1000;
typedef char Letter;

typedef struct _Node{
	struct _Node *next;
	Letter letter;
} Node;

typedef struct {
	Node* node;
} Iterator;

typedef struct {
	Node *head;
	Node *free_elem;
	Node data[POOL_SIZE + 1];
	int size;
} List;

List *list_create();
Iterator first(List *list);
Iterator last(List *list);
bool list_is_empty(Iterator a, Iterator b);
void list_delete_element(List *list, char del);
void list_print(List *list);

#endif