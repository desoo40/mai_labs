#include "list_arr.h"

List *list_create()
{
	List *list = (List*) malloc(sizeof(List));

	if (!list)
		return NULL;

	list->count = 0;
	list->nodes = NULL;

	return list;
}
void list_add_element(List *list, char add)
{
	if (!count)
		list->nodes = (Node *) malloc(sizeof(Node));
	else
		list->nodes = (Node *) realloc(list->nodes, sizeof(Node) * (count + 1));

	++count;

	list->nodes[count - 1] = add;
}
void list_delete_element(List *list, char del);
{
	int i = 0;
	while (i < list->count) {
		if (del == list->nodes[i])

	}
}
void list_print(List *list);

int list_lenght(List *list)
{
	return sizeof(list->nodes) / sizeof(Node);
}