#include "stack.h"

Stack *stack_create()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));

	stack->current = NULL;

	return stack;
}

bool stack_is_empty(Stack *stack)
{
	return !(stack->current);
}

Node *node_create(char sym)
{
	Node *node = (Node*)malloc(sizeof(Node));

	node->symbol = sym;
	node->prev = NULL;

	return node;
}

void stack_push(Stack *stack, char sym)
{
	if (stack_is_empty(stack))
	{
		stack->current = node_create(sym);
		return;
	}
	
	Node *tmp = node_create(sym);
	
	tmp->prev = stack->current;
	stack->current = tmp;

	return;
}

void stack_pop(Stack *stack)
{
	if (stack_is_empty(stack))
	{
		printf("Stack is empty\n");
		return;
	}

	Node *tmp = stack->current->prev;

	free(stack->current);
	stack->current = NULL;

	stack->current = tmp;

	return;
}

void stack_print(Node *node)
{
	printf("TOP\n");
	while (node != NULL)
	{
		printf("%c\n", node->symbol);
		node = node->prev;
	}
	printf("BOTTOM\n");

	return;
}