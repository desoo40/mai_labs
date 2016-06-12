#include "stack.h"

int main(void)
{
	Stack *stack = stack_create();

	while(1)
	{
		int s = 0;
		scanf("%d", &s);

		if (s == 1)
		{
			char *c;
			scanf("%s", c);

			stack_push(stack, c[0]);
			continue;
		}

		if (s == 2)
		{
			stack_pop(stack);
			continue;
		}

		if (s == 3)
		{
			if (stack_is_empty(stack))
				printf("empry");
			stack_print(stack->current);
		}

		if (s == 4)
		{
			return 0;
		}
	}
}