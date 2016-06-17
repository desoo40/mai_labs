#include "queue.h"

Queue *queue_create(Tree *tree)
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));

	queue->first = que_node_create(tree);
	queue->last = queue->first;

	return queue;

}

Que_node *que_node_create(Tree *tree)
{
	Que_node *node = (Que_node*)malloc(sizeof(Que_node));

	node->next = NULL;
	node->tree = tree;

		return node;
}

void queue_push(Queue *queue, Tree *tree)
{
	if (queue == NULL)
		return;

	if (queue_is_empty(queue))
	{
		queue->first = que_node_create(tree);
		queue->last = queue->first;
	}

	else
	{
		Que_node *node = que_node_create(tree);

		node->next = queue->first;
		queue->first = node;
	}

	return;
}

void queue_pop(Queue *queue)
{
	if (queue == NULL)
		return;

	if (queue_lenght(queue) == 1)
	{
		free(queue->first);
		queue->first = NULL;
		queue->last = NULL;
		return;
	}

	Que_node *tmp = queue->first;

	while (tmp->next != queue->last)
		tmp = tmp->next;

	free(queue->last);
	queue->last = NULL;

	queue->last = tmp;
	queue->last->next = NULL;
	return;
}

Que_node *queue_top(Queue *queue)
{
	return queue->last;
}

bool queue_is_empty(Queue *queue)
{
	return !queue->first;
}

void queue_destroy(Queue **queue)
{
	Que_node *tmp = (*queue)->first;

	while (!queue_is_empty(*queue))
	{
		tmp = (*queue)->first->next;

		free((*queue)->first);
		(*queue)->first = NULL;

		(*queue)->first = tmp;
	}

	free(*queue);
	*queue = NULL;
}

int queue_lenght(Queue *queue)
{
	if (queue == NULL)
		return 0;

	if (queue->first == NULL)
		return 0;

	Que_node *tmp = queue->first;
	int size = 1;

	while (tmp != queue->last)
	{
		tmp = tmp->next;
		++size;
	}

	return size;
}
//
//void queue_print(Queue *queue)
//{
//	if (queue_is_empty(queue))
//	{
//		printf("Queue is empty\n");
//		return;
//	}
//
//	Que_node *tmp = queue->first;
//
//	while (tmp)
//	{
//		if (tmp->tree->is_char)
//			printf("%c\n", tmp->tree->symbol);
//		else
//			printf("%d\n", tmp->tree->symbol);
//
//		tmp = queue->first->next;
//	}
//
//	return;
//}