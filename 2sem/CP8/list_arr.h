#ifndef __LIST_H__
#define __LIST_H__

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // MSCVER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 100

typedef struct _Node
{
	int next;
	char letter;
} Node;

typedef struct iterator
{
	int node;
} Iterator;

typedef struct list
{
	int head;
	int last;
	int top;
	Node data[POOL_SIZE + 1];
	int size;
} List;

bool equal(Iterator *first, Iterator *second);
bool not_equal(Iterator *first, Iterator *second);
Iterator next(Iterator *iter, List *list);
char fetch(Iterator *iter, List *list);
void store(Iterator *iter, List *list, char c);
bool empty(List *list);

List *list_create();
Iterator first(List *list);
Iterator last(List *list);
bool list_is_empty(List *list);
void list_delete_element(List *list, int del_num);
Iterator list_add_element(List *list, char ins, int before_elem);
void list_print(List *list);
int list_lenght(List *list);
void insert_k_times(List *l, int times);

#endif