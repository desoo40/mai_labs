#include "trees.h"

Year_tree *year_tree_create()
{
	Year_tree *tree = (Year_tree*) malloc(sizeof(Year_tree));

	tree->root = year_node_create();

	return tree;
}

Year_node *year_node_create(Date )
{
	Year_node *node = (Year_node*) malloc(sizeof(Year_node));

	node->left = NULL;
	node->right = NULL;
	node->l_tree = NULL;

	return node;
}

void year_tree_add_grad(Year_node *node, Graduate *graduate)
{
	if (node == NULL)
		return;

	if (val >= node->data) {
		if (node->right == NULL) {
			node->right = node_create(val);
			return;
		} else
			tree_elem_add(node->right, val);

	} else {
		if (node->left == NULL) {
			node->left = node_create(val);
			return;
		} else
			tree_elem_add(node->left, val);
	}
}