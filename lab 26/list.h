#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sdata sData;
typedef struct listnode ListNode;
typedef struct list List;


struct sdata {
    int key;
    int value;
};

struct listnode {
    sData data;
    ListNode *next;
    ListNode *prev;
};

struct list {
    ListNode *head;
    ListNode *tail;
};

List *list_create(); // создает 
void list_destroy(List **list); //  уничтожает под корень
void list_delete(List *list); // отряхивает листву
void list_print(List *list); // выводит 
bool list_is_empty(List *list); // проверяет на пустоту
size_t list_size(List *list); // возвращает размер
size_t list_lenght(List *list); // возвращает длину
void list_insert(List *list); // ввод списка
ListNode *list_insert_front(List *list, sData ins_data); // добавляет элемент в начало
ListNode *list_insert_last(List *list, sData ins_data); // добавляет элемент в конец
ListNode *list_insert_after_elem(ListNode *prevnode, sData ins_data); // добавляет элемент после элемента
ListNode *list_insert_before_elem(ListNode *nextnode, sData ins_data); // добавляет элемент перед элементом
void list_insert_first_elem(ListNode *inserted, List *list); // добавляет первый элемент списка
void list_delete_elem(List *list, ListNode *node); // удаляет элемент
ListNode *find_elem(List *list, size_t key); // ищет элемент по ключу

#endif