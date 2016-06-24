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
			printf("Insert char: \n");
			scanf("%s", &c);
			printf("Insert after each to add: \n");
			scanf("%d", &s);

			it = list_add_element(list, c[0], s);
			continue;
		}

		if (s == 2)
		{
			list_print(list);
			continue;
		}

		if (s == 3)
		{
			printf("Num of deleted element? \n");
			scanf("%d", &s);
			list_delete_element(list, s);
			continue;
		}

		if (s == 4)
		{
			printf("Size if list: %d", list_lenght(list));
			continue;
		}

		if (s == 5)
		{
			if (empty(list))
			{
				printf("List is empty \n");
				return;
			}

			printf("How many times add?\n");
			scanf("%d", &s);

			if (POOL_SIZE - list_lenght(list) <= s) {
				printf("No no no mon petit cherie, you want's too many...\n");
				break;
			}

			insert_k_times(list, s);
			continue;
		}
	}
}