#include "in.h"

bool is_char_operator(char c)
{
	return (c == '-' ||
		c == '+' ||
		c == '*' ||
		c == '/' ||
		c == '^' ||
		c == '(' ||
		c == ')');
}

int get_priority(char c)
{
	if (c == '-' || c == '+')
		return 1;
	if (c == '/' || c == '*')
		return 2;
	if (c == '^')
		return 3;

	return -1;
}

bool is_char_operand(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= '0' || c <= '9'));
}

void io_free(Stack *out, Stack *tmp)
{
	stack_free(out);
	stack_free(tmp);
	printf("Insert polynomial again:\n");
	get_string(out);
	return;
}

void get_string(Stack *out)
{
	Stack *tmp = stack_create();
	char c[100];

	printf("Print polynomial:\n");
	scanf("%100[^\n]", c);

	for (int i = 0; c[i] != '\0'; ++i)
	{
		if (c[i] == '\n' || c[i] == ' ')
			continue;

		if (c[i] == '(')
		{
			stack_push(tmp, c[i]);
			continue;
		}

		if (c[i] == ')')
		{
			while (stack_top(tmp) != '(')
			{
				if (tmp->current == NULL)
				{
					printf("Incorrectly placed parentheses\n");
					io_free(out, tmp);
					return;
				}
				stack_push(out, stack_top(tmp));
				stack_pop(tmp);
			}

			stack_pop(tmp);
			continue;
		}

		if (is_char_operator(c[i]))
		{
			int priority_curr = get_priority(c[i]);
			int priority_top = get_priority(stack_top(tmp));

			if (stack_is_empty(tmp) || priority_curr > priority_top)
			{
				stack_push(tmp, c[i]);
				continue;
			}
			
			while (priority_curr <= priority_top)
			{
				stack_push(out, stack_top(tmp));
				stack_pop(tmp);
				priority_top = get_priority(stack_top(tmp));
			}

			stack_push(tmp, c[i]);
			continue;
		}

		if (is_char_operand(c[i]))
		{
			stack_push(out, c[i]);
			continue;
		}

		printf("Wrong letter is polynomial %c\n", c[i]);
		io_free(out, tmp);
		return;
	}

	while (!stack_is_empty(tmp))
	{
		stack_push(out, stack_top(tmp));
		stack_pop(tmp);
	}

	return;
}
