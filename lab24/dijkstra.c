#include "dijkstra.h"

bool is_char_operator(int c)
{
	return (c == '-' ||
		c == '+' ||
		c == '*' ||
		c == '/' ||
		c == '^' ||
		c == '(' ||
		c == ')');
}

int get_priority(int c)
{
	if (c == '-' || c == '+')
		return 1;
	if (c == '/' || c == '*')
		return 2;
	if (c == '^')
		return 3;

	return -1;
}

bool is_dig(int c)
{
	return (c >= '0' && c <= '9');
}

bool is_char_operand(int c)
{
	return (c == 'x' || is_dig(c));
}

void io_free(Stack *out, Stack *tmp)
{
	stack_free(out);
	stack_free(tmp);
	return;
}

bool is_input_right(char *c)
{
	bool prev_operator = true;
	int operator_qty = 0;
	int operand_qty = 0;

	for(int i = 0; c[i] != '\0'; ++i)
	{
		if (c[i] == ')' || c[i] == '(')
			continue;

		if (i == 0 && is_char_operator(c[i]))
			return false;

		if (c[i + 1] == '\0' && is_char_operator(c[i]))
			return false;

		if (is_char_operator(c[i]))
		{
			if (prev_operator)
				return false;

			prev_operator = true;
			++operator_qty;
		}

		if (is_char_operand(c[i]))
		{
			if (!prev_operator)
				return false;

			prev_operator = false;
			++operand_qty;
		}
	}

	if (operand_qty - 1 != operator_qty)
		return false;

	return true;
}

void get_string(Stack *out)
{
	Stack *tmp = stack_create();
	char c[100];

	printf("Print polynomial:\n");
	scanf("%100[^\n]", c);

	if(!is_input_right(c)) {
		printf("Wrong input\n");
		return;
	}

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

			for (; is_dig(c[i + 1]); ++i)
			{
				out->current->symbol *= 10;
				out->current->symbol += c[i + 1] - '0';
			}

			continue;
		}

		printf("Wrong letter in polynomial %c\n", c[i]);
		io_free(out, tmp);
		return;
	}

	while (!stack_is_empty(tmp))
	{
		if (stack_top(tmp) == '(' || stack_top(tmp) == ')')
		{
			printf("Incorrectly placed parentheses\n");
			io_free(out, tmp);
			return;
		}

		stack_push(out, stack_top(tmp));
		stack_pop(tmp);
	}

	free(tmp);
	tmp = NULL;

	return;
}
