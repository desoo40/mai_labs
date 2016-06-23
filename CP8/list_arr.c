#include "list_arr.h"

List *list_create()
{
	List *l = (List*) malloc(sizeof(List));

	if (!l)
		return NULL;

	for (int i = 0; i < POOL_SIZE; ++i) 
		l->data[i].next = &(l->data[i+1]);

	l->data[POOL_SIZE - 1].next = NULL;
	l->head->next = l->head;
	l->top = &(l->data[0]);
	l->size = 0;

	return list;
}

Iterator list_add_element(List *list, Iterator *i, Letter elem)
{
	Iterator res = list->top;

	if(!res.node)
		return last(list);

	l->top = l->top->next;

	res.node->data = elem;
	res.node->next = i->node->next;
	i->node->next = res.node;

	++l->size;

	return res;
}

Iterator list_delete_element(List *list, Iterator del);
{
	Iterator res = last(l);
	if (equal(del, &res))
		return res;

	i->node = i->node->next;
	res.node = i->node;

	res.node->next = l->top;
	res.node->next = NULL;

	return res;
}

Iterator first(List *list)
{
	return list->head;
}

Iterator last(List *list)
{
	return 
}

void list_print(List *list)
{

}

int list_lenght(List *list)
{
	return sizeof(list->nodes) / sizeof(Node);
}