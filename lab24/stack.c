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

Data* data_create(int sym)
{
	Data *data = (Data*)malloc(sizeof(Data));

	if (is_dig(sym))
	{
		data->symbol = sym - '0';
		data->is_char = false;
	}
	else
	{
		data->symbol = sym;
		data->is_char = true;
	}

	return data;
}

Node *node_create(int sym)
{
	Node *node = (Node*)malloc(sizeof(Node));

	node->data = data_create(sym);
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

	free(stack->current->data);
	stack->current->data = NULL;
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
		if (node->data->is_char)
			printf("%c\n", node->data->symbol);
		else 
			printf("%d\n", node->data->symbol);

		node = node->prev;
	}
	printf("BOTTOM\n");

	return;
}

Data *stack_top(Stack *stack)
{
	if (stack->current == NULL)
		return NULL;

	return stack->current->data;
}

void stack_free(Stack *stack)
{
	while (!(stack_is_empty(stack)))
		stack_pop(stack);

	return;
}

void stack_destroy(Stack **stack)
{
	stack_free(*stack);
	free(*stack);
	*stack = NULL;
	return;
}