#include "list.h"

List *list_create()
{
	List *list = (List*) malloc(sizeof(List));

	if (list == NULL)
		return NULL;

	list->head = NULL;
	list->tail = NULL;

	return list;
}

void list_destroy(List **plist)
{
	List *list = *plist;

	while (list->head != NULL) {
		ListNode *n = list->head->next;
		free(list->head);
		list->head = n;
	}

	free(list);
	*plist = NULL;
}

void list_delete(List *list)
{
	free(list);
	list->head = NULL;
}

bool list_is_empty(List *list)
{
	return (list->head == NULL); 
}

void list_insert_first_elem(ListNode *inserted, List *list)
{
	inserted->next = NULL;
	inserted->prev = NULL;
	list->head = inserted;
	list->tail = inserted;
}

ListNode *list_insert_front(List *list, sData ins_data)
{
	ListNode *inserted = (ListNode*) malloc(sizeof(ListNode));

	if (inserted == NULL)
		return NULL;
	if (list_is_empty(list))
		list_insert_first_elem(inserted, list);

	else {
		inserted->next = list->head;
		inserted->prev = NULL;
		list->head->prev = inserted; 
		list->head = inserted;
	}

	inserted->data = ins_data;

	return inserted;
}

ListNode *list_insert_last(List *list, sData ins_data)
{
	ListNode *inserted = (ListNode*) malloc(sizeof(ListNode));

	if (inserted == NULL)
		return NULL;
	if (list_is_empty(list))
		list_insert_first_elem(inserted, list);

	else {
		inserted->next = NULL;
		inserted->prev = list->tail;
		list->tail->next = inserted; 
		list->tail = inserted;
	}

	inserted->data = ins_data;

	return inserted;
}

ListNode *list_insert_after_elem(ListNode *prevnode, sData ins_data)
{
	ListNode *inserted = (ListNode*) malloc(sizeof(ListNode));

	if (inserted == NULL)
		return NULL;
	// if (list_is_empty(list))
		// list_insert_first_elem(inserted, list);
	else {
		inserted->next = prevnode->next;
		inserted->prev = prevnode;
		prevnode->next = inserted;
	}

	inserted->data = ins_data;

	return inserted;
}

ListNode *list_insert_before_elem(ListNode *nextnode, sData ins_data)
{
	ListNode *inserted = (ListNode*) malloc(sizeof(ListNode));

	if (inserted == NULL)
		return NULL;
	// if (list_is_empty(list))
		// list_insert_first_elem(inserted, list);
	else {
		inserted->next = nextnode;
		inserted->prev = nextnode->prev;
		nextnode->prev = inserted;
	}

	inserted->data = ins_data;

	return inserted;
}

void list_delete_elem(List *list, ListNode *node)
{
	if (node == NULL)
		return;
		
	if (node->prev == NULL && node->next == NULL) { // всего один элемент в списке
		list->head = NULL;
		list->tail = NULL;
	}

	if (node->prev == NULL && node->next != NULL) { // более одного элемента в списке и удаляемый первый
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	
	if (node->next == NULL && node->prev != NULL) { // больше одного элемента в списке и удаляемый последний
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	
	if (node->next != NULL && node->prev != NULL) { // больше одного элемента в списке и удаляемый в середине
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	free(node);
}

void list_print(List *list)
{
	ListNode *node = list->head;
	if(node == NULL){
		printf("List is empty\n");
		return;
	}

	int i=0;
	while (node != NULL) {
		printf("Node: %d Key: %d Value: %d\n", i, node->data.key, node->data.value);
		node = node->next;
		++i;
	}
}

size_t list_size(List *list)
{
	ListNode *node = list->head;
	int i = 0;

	while (node != NULL) {
		node = node->next;
		++i;
	} 

	return i * sizeof(List);
}

ListNode *find_elem(List *list, size_t key)
{
	ListNode *node = list->head;

	while (node != NULL)
	{
		if (node->data.key == key)
			return node;

		node = node->next;
	}
	
	printf("Node by key %u not found\n", key);
	return NULL;
}

size_t list_lenght(List *list)
{
	return list_size(list) / sizeof(List);
}

void list_insert(List *list)
{
	printf("1 - add element back, 0 - enough\n");
	
    while(1)
    {
        int n = 0;

        scanf("%d", &n);

        if (n == 1) {
            int key = 0;
            int value = 0;
            
            scanf("%d%d", &key, &value);

            sData ins_data = {
                key, value
            };

            list_insert_last(list, ins_data);
            continue;
        } 
        if (n == 0)
            break;

        printf("Wrong input, try again\n");
    }
}