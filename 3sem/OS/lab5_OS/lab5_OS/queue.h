#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _qnode Que_node;
typedef struct _queue Queue;

struct _qnode
{
	Que_node *next;
	int32_t *elem;
};

struct _queue
{
	Que_node *first;
	Que_node *last;
};

Queue *queue_create(int32_t *elem);
void queue_push(Queue *queue, int32_t *elem);
Que_node *que_node_create(int32_t *elem);
bool queue_is_empty(Queue *queue);
void queue_pop(Queue *queue);
void queue_destroy(Queue **queue);
int queue_lenght(Queue *queue);
Que_node *queue_top(Queue *queue);
void queue_print(Queue *queue);

#endif