#include "stack.h"
#include "dijkstra.h"
#include "tree.h"
#include "queue.h"

int main(void)
{
	Stack *out = stack_create();

	get_string(out);
	/*stack_print(out->current);*/

	Tree *tree = NULL;
	tree = tree_build(out);
	/*tree_print(tree, 0);*/

	tree_simplifier(tree);
	tree = tree_on_x(tree);

	printf(" = ");
	tree_DFS_print(tree);
	printf("\n");
	tree_BFS_print(tree);

	stack_destroy(&out);
	tree_destroy(&tree);
	return 0;
}
