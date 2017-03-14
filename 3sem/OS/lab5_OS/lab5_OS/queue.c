#include "queue.h"

Queue *queue_create(int32_t *elem)
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));

	queue->first = que_node_create(elem);
	queue->last = queue->first;

	return queue;

}

Que_node *que_node_create(int32_t *elem)
{
	Que_node *node = (Que_node*)malloc(sizeof(Que_node));

	node->next = NULL;
	node->elem = elem;

		return node;
}

void queue_push(Queue *queue, int32_t *elem)
{
	if (queue == NULL)
		return;

	if (queue_is_empty(queue))
	{
		queue->first = que_node_create(elem);
		queue->last = queue->first;
	}

	else
	{
		Que_node *node = que_node_create(elem);

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

void queue_print(Queue *queue)
{
	if (queue_is_empty(queue))
	{
		printf("Queue is empty\n");
		return;
	}

	Que_node *tmp = queue->first;

	while (tmp)
	{
			printf("%p\n", tmp->elem);

		tmp = queue->first->next;
	}

	return;
}