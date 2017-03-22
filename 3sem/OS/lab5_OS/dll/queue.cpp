#include "queue.h"

struct _qnode
{
	Que_node *next;
	int32_t elem;
};

struct _queue
{
	Que_node *first;
	Que_node *last;
};

extern "C" __declspec(dllexport) Queue *queue_create(int32_t elem) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->first = que_node_create(elem);
    queue->last = queue->first;

    return queue;

}

extern "C" __declspec(dllexport) Que_node *que_node_create(int32_t elem) {
    Que_node *node = (Que_node*)malloc(sizeof(Que_node));

    node->next = NULL;
    node->elem = elem;

    return node;
}

extern "C" __declspec(dllexport) bool queue_push(Queue *queue, int32_t elem) {
    if (queue == NULL)
        return false;

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

    return true;
}

extern "C" __declspec(dllexport) bool queue_pop(Queue *queue) {
    if (queue == NULL)
        return false;

    if (queue->first == NULL) {
        return false;
    }

    if (queue_lenght(queue) == 1)
    {
        free(queue->first);
        queue->first = NULL;
        queue->last = NULL;
        return true;
    }

    Que_node *tmp = queue->first;

    while (tmp->next != queue->last)
        tmp = tmp->next;

    free(queue->last);
    queue->last = NULL;

    queue->last = tmp;
    queue->last->next = NULL;
    return true;
}

extern "C" __declspec(dllexport) Que_node *queue_top(Queue *queue) {
    return queue->last;
}

extern "C" __declspec(dllexport) bool queue_is_empty(Queue *queue) {
    return !queue->first;
}

extern "C" __declspec(dllexport) void queue_destroy(Queue **queue) {
    if (*queue == NULL) {
        return;
    }

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

extern "C" __declspec(dllexport) int queue_lenght(Queue *queue) {
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

extern "C" __declspec(dllexport) void queue_print(Queue *queue) {
    if (queue_is_empty(queue))
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Que_node *tmp = queue->first;

    while (tmp)
    {
        cout << "[" << tmp->elem << "]";
        tmp = tmp->next;
        if (tmp)
            cout << "-> ";
    }
    cout << endl;
    return;
}