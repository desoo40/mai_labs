#include "list.h"
#include "list_den.h"

int main(void)
{
    List *list = list_create();

    interface_1(list);
    list_destroy(&list);

    return 0;
}