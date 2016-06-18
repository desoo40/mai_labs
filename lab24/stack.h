#ifndef _STACK_H_
#define _STACK_H_

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _node Node;
typedef struct _stack Stack;
typedef struct _data Data;

struct _data
{
	int symbol;
	bool is_char;
};

struct _node {
	Data *data;
	Node *prev;
};

struct _stack {
	Node *current;
};

Stack *stack_create();
Data* data_create(int sym);
Node *node_create(int sym);
bool stack_is_empty(Stack *stack);
void stack_push(Stack *stack, int sym);
void stack_pop(Stack *stack, char s); // s == 'd' - data delete, s == 'n' don't
void stack_print(Node *node);
Data *stack_top(Stack *stack);
void stack_free(Stack *stack);
void stack_destroy(Stack **stack);

#endif
