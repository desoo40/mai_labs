#ifndef __LIST_H__
#define __LIST_H__

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // MSCVER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 100

typedef struct _Node{
	struct _Node *next;
	char letter;
} Node;

typedef struct iterator{
	Node* node;
} Iterator;

typedef struct list{
	Node *head;
	Node *top;
	Node *free_elem;
	Node data[POOL_SIZE + 1];
	int size;
} List;

List *list_create();
Iterator first(List *list);
Iterator last(List *list);
bool list_is_empty(Iterator a, Iterator b);
Iterator list_delete_element(List*, Iterator*);
Iterator list_add_element(List*, Iterator*, char);
void list_print(List *list);
int list_lenght(List*);

Iterator next(Iterator*);
bool not_equal(Iterator *, Iterator *);
typedef bool bulochka;
bulochka equal(Iterator *, Iterator *);
bool empty(List *l);

#endif