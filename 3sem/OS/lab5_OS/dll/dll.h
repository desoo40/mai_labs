#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <windows.h>

using namespace std;
extern "C" __declspec(dllexport) void Func();
extern "C" __declspec(dllexport) void F(int a);



#include <stdbool.h>

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

extern "C" __declspec(dllexport) Queue *queue_create(int32_t *elem);
extern "C" __declspec(dllexport) void queue_push(Queue *queue, int32_t *elem);
extern "C" __declspec(dllexport) Que_node *que_node_create(int32_t *elem);
extern "C" __declspec(dllexport) bool queue_is_empty(Queue *queue);
extern "C" __declspec(dllexport) void queue_pop(Queue *queue);
extern "C" __declspec(dllexport) void queue_destroy(Queue **queue);
extern "C" __declspec(dllexport) int queue_lenght(Queue *queue);
extern "C" __declspec(dllexport) Que_node *queue_top(Queue *queue);
extern "C" __declspec(dllexport) void queue_print(Queue *queue);
#endif