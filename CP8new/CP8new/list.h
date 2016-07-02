#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 100

typedef struct _Node {
	struct _Node *next;
	char letter;
} Node;

typedef struct iterator {
	Node* node;
} Iterator;

typedef struct list {
	Node *head;
	Node *top;
	Node data[POOL_SIZE + 1];
	int size;
} List;


#endif 