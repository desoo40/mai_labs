#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "tree.h"
#include "stack.h"

typedef struct _qnode Que_node;
typedef struct _queue Queue;

struct _qnode
{
	Que_node *next;
	Tree *tree;
};

struct _queue
{
	Que_node *first;
	Que_node *last;
};

Queue *queue_create(Tree *tree);
void queue_push(Queue *queue, Tree *tree);
Que_node *que_node_create(Tree *tree);
bool queue_is_empty(Queue *queue);
void queue_pop(Queue *queue);
void queue_destroy(Queue **queue);
int queue_lenght(Queue *queue);
Que_node *queue_top(Queue *queue);
//void queue_print(Queue *queue);

#endif