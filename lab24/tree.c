#include "tree.h"

Tree *tree_create(Data *data)
{
	Tree *tree = (Tree*)malloc(sizeof(Tree));

	tree->left = NULL;
	tree->right = NULL;
	tree->data = data;

	return tree;
}

bool is_d (Data *data)
{
	return (!data->is_char || data->symbol == 'x');
}

bool is_t (Data *data)
{
	return data->is_char;
}

void tree_add_elem(Tree *tree, Data *data)
{
	if (tree->right != NULL) {
		if (is_t(tree->right->data)) {
			tree_add_elem(tree->right, data);
			return;
		}
			
		if (is_d(tree->right->data)) {
			if (tree->left != NULL) {
				//BUG WAS HERE!
				//tested via 1+2-3*4-(6*7+8)
				if (is_t(tree->left->data))
				{
					tree_add_elem(tree->left, data);
					return;
				}
				if (is_d(tree->left->data));
				{
					tree_add_elem(tree->right, data);
					return;
				}
				// o_O
			}

			if (tree->left == NULL) {
				tree->left = tree_create(data);
				return;
			}
		}

		
	}

	if (tree->right == NULL)
	{
		tree->right = tree_create(data);
	}
}

void tree_print(Tree *tree, int lvl)
{
	if (tree == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	for (int i = 0; i < lvl; i++)
		printf("  ");

	if (tree->data->is_char)
		printf("%c\n", tree->data->symbol);
	else
		printf("%d\n", tree->data->symbol);

	if (tree->left != NULL)
		tree_print(tree->left, lvl + 1);

	if (tree->right != NULL)
		tree_print(tree->right, lvl + 1);
}

Tree *tree_build(Tree *tree, Stack *out)
{
	while (!stack_is_empty(out))
	{
		if (tree == NULL)
			tree = tree_create(stack_top(out));
		else
			tree_add_elem(tree, stack_top(out));
		
		stack_pop(out);
	}

	return tree;
}