#include "list.h"
#include "list_den.h"

// List *merge(List *first, List *second, List *result)
// {
// 	if (list_is_empty(first) && list_is_empty(second)) 
// 		return result;

// 	if (list_is_empty(first)) {
// 		if (list_is_empty(result))
// 			return second;

// 		result->tail->next = second->head;
// 		second->head->prev = result->tail;

//         list_delete(first);
//         list_delete(second);

// 		return result;
// 	}

// 	if (list_is_empty(second)) {
// 		if (list_is_empty(result))
// 			return first;

// 		result->tail->next = first->head;
// 		first->head->prev = result->tail;

//         list_delete(first);
//         list_delete(second);

// 		return result;
// 	}


//     if (first->head->data->key <= second->head->data->key) {
//     	list_insert_last(result, first->head->data);
//     	list_delete_elem(first, first->head);
//     } else {
//     	list_insert_last(result, second->head->data);
//     	list_delete_elem(second, second->head);
//     }

//     // list_print(result);
//     return merge(first, second, result);
// }

List *merge_sort(List *list)
{
    if (list->head == NULL)
        return NULL;

    if (list_lenght(list) < 2)
        return list;

    if (list_lenght(list) == 2) {
        if (list->head->data->key < list->tail->data->key)
            two_elem_list_reverse(list);

        return list;
    }

    if (list_lenght(list) > 2) {

    }

}

int main(void)
{
    List *list = list_create();

    interface_1(list);
    list_destroy(&list);

    return 0;
}