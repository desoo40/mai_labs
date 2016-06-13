#include "stack.h"
#include "dijkstra.h"

int main(void)
{
	Stack *out = stack_create();

	get_string(out);
	stack_print(out->current);

	stack_free(out);
	out = NULL;
	return 0;
}
