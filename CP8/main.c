#include "list_arr.h"

int main(void)
{

	List *list = list_create();

	while (1)
	{
		int s = 0;
		char c = 0;

		scanf("%d", &s);

		if (s == 0)
			break;

		if (s == 1)
		{
			scanf("%c", &c);
			list_add_element(list, c);
			continue;
		}

		if (s == 2)
		{
			list_print(list);
			continue;
		}

		if (s == 3)
		{
			list_delete_element(list);
			continue;
		}

		if (s == 4)
		{
			printf("Size if list: %d", list_lenght(list));
			continue;
		}
	}
}