#include "list_arr.h"

bool equal(Iterator *first, Iterator *second)
{
	return first->node == second->node;
}

bool not_equal(Iterator *first,Iterator *second)
{
	return !equal(first, second);
}

Iterator next(Iterator *iter, List *list)
{
	iter->node = list->data[iter->node].next;
	return *iter;
}

char fetch(Iterator *i, List *l)
{
	return l->data[i->node].letter;
}

void store(Iterator *i, List *l, char c)
{
	l->data[i->node].letter=c;
}

bool empty(List *l)
{
	return l->head == l->last;
}

List *list_create()
{
	List *list = (List*) malloc(sizeof(List));

	int i;
	for (i = 0; i < POOL_SIZE; i++)
		list->data[i].next = i + 1;

	list->data[POOL_SIZE - 1].next= -1;
	list->head = list->last = POOL_SIZE;
	list->size = 0;
	list->top = 0;
}

Iterator first(List *l)
{
	Iterator res = { l->head };
	return res;
}

Iterator last(List *l)
{
	Iterator res = { l->last };
	return res;
}


int list_lenght(List *l)
{
	return l->size;
}

Iterator list_add_element(List *list, char elem, int before_elem)
{
	Iterator res = { list->top };
	Iterator tmp, tmp1;

	int i = 1;

	if (res.node == -1)
		return last(list);

	list->top = list->data[list->top].next;
	list->data[res.node].letter = elem;

	for(tmp = first(list); ((before_elem != i) && (tmp.node!= last(list).node)); next(&tmp,list))
	{
		tmp1=tmp;
		i++;
	}

	if (tmp.node == first(list).node)
	{
		list->data[res.node].next = tmp.node;
		list->head=res.node;
	}

	else
	{
		list->data[tmp1.node].next = res.node;
		list->data[res.node].next = tmp.node;
	}

	++list->size;
	return res;
}

void list_print(List *l)
{
	if(empty(l))
		printf("List is empty\n");
	
	else
	{
		printf("List: \n");

		Iterator i = first(l);
		Iterator j = last(l);

		for (i; not_equal(&i, &j); next(&i, l))
			printf("%c ",fetch(&i, l));

		printf("\n");
	}
}

void list_delete_element(List *list, int del_num)
{
	if (empty(list))
	{
		printf("List is empty\n");
		return;
	}	

	Iterator tmp,tmp1;
	int i = 1;
	
	for(tmp = first(list); del_num != i && (tmp.node!=last(list).node); next(&tmp, list))
	{
		tmp1 = tmp;
		++i;
	}

	if (tmp.node == first(list).node)
		list->head = list->data[tmp.node].next;

	else if (tmp.node == last(list).node)
	{
		printf("Cannot find element\n");
		return;
	}

	else
		list->data[tmp1.node].next = list->data[tmp.node].next;

	list->data[tmp.node].next = list->top;
	list->top = tmp.node;
	--list->size;
}

void insert_k_times(List *l, int times)
{
	char ins = l->data[list_lenght(l) - 1].letter;

	for (int i = 0; i < times; ++i)
	{
		list_add_element(l, ins, 1);
	}
}
