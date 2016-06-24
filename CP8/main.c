#include "list_arr.h"


int main(void)
{

	List *list = list_create();
	Iterator it = { list->head };
	printf(" 1 - add, 2 - print, 3 - delete letterochek, 4 - dlinna\n");
	while (1)
	{
		int s = 0;
		char c[100];

		scanf("%d", &s);

		if (s == 0)
			break;

		if (s == 1)
		{
			scanf("%s", &c);
			it = list_add_element(list, &it, c[0]);
			continue;
		}

		if (s == 2)
		{
			list_print(list);
			continue;
		}

		if (s == 3)
		{
			scanf("%s", &c);
			Iterator i, _last = last(list);
			for (i = first(list); i.node->letter != c[0] || not_equal(&i, &_last); next(&i));

			list_delete_element(list, &i);
			continue;
		}

		if (s == 4)
		{
			printf("Size if list: %d", list_lenght(list));
			continue;
		}
	}
}