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

struct _node {
	char symbol;
	Node *prev;
};

struct _stack {
	Node *current;
};

Stack *stack_create();
bool stack_is_empty(Stack *stack);
void stack_push(Stack *stack, char sym);
void stack_pop(Stack *stack);
void stack_print(Node *node);
char stack_top(Stack *stack);
void stack_free(Stack *stack);

#endif
