#include "stack.h"
#include "in.h"

int main(void)
{
	Stack *out = stack_create();

	get_string(out);

	stack_print(out->current);

	return 0;
}