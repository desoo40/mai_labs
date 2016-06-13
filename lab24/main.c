#include "stack.h"
#include "dijkstra.h"
#include "tree.h"

int main(void)
{
	Stack *out = stack_create();

	get_string(out);
	stack_print(out->current);

	Tree *tree = NULL;
	tree = tree_build(tree, out);
	tree_print(tree, 0);

	stack_destroy(&out);
	return 0;
}
