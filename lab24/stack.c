#include "stack.h"
#include "dijkstra.h"

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

Node *node_create(int sym)
{
	Node *node = (Node*)malloc(sizeof(Node));

	if (is_dig(sym))
	{
		node->symbol = sym - '0';
		node->is_char = false;
	}
	else
	{
		node->symbol = sym;
		node->is_char = true;
	}


	node->prev = NULL;

	return node;
}

void stack_push(Stack *stack, int sym)
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
		if (node->is_char)
			printf("%c\n", node->symbol);
		else 
			printf("%d\n", node->symbol);

		node = node->prev;
	}
	printf("BOTTOM\n");

	return;
}

char stack_top(Stack *stack)
{
	if (stack->current == NULL)
		return 0;

	return stack->current->symbol;
}

void stack_free(Stack *stack)
{
	while (!(stack_is_empty(stack)))
		stack_pop(stack);

	return;
}

void stack_destroy(Stack *stack)
{
	stack_free(stack);
	stack = NULL;
	return;
}