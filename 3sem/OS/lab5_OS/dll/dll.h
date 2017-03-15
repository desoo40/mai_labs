#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <windows.h>
#include <stdbool.h>

using namespace std;

typedef struct _qnode Que_node;
typedef struct _queue Queue;


extern "C" __declspec(dllexport) Queue *queue_create(int32_t elem);
extern "C" __declspec(dllexport) void queue_push(Queue *queue, int32_t elem);
extern "C" __declspec(dllexport) Que_node *que_node_create(int32_t elem);
extern "C" __declspec(dllexport) bool queue_is_empty(Queue *queue);
extern "C" __declspec(dllexport) void queue_pop(Queue *queue);
extern "C" __declspec(dllexport) void queue_destroy(Queue **queue);
extern "C" __declspec(dllexport) int queue_lenght(Queue *queue);
extern "C" __declspec(dllexport) Que_node *queue_top(Queue *queue);
extern "C" __declspec(dllexport) void queue_print(Queue *queue);
#endif