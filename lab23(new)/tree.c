#include "list.h"

typedef struct {
	Node *par;
	Node *del;
} Del_par;

Tree *tree_create()
{
	Tree *tree = (Tree*) malloc(sizeof(tree));

	tree->root = NULL;

	return tree;
}

Node *node_create()
{
	Node *node = (node*) malloc(sizeof(node));

	node->left = NULL;
	node->right = NULL;
	node->data = NULL;

	return node;
}

void tree_add_elem(Node *node, Data *val)
{
	if (node == NULL) {
		return;
	}

	if (node->data == NULL) {
		node->data = val;
		node->left = node_create();
		node_right = node_create();
		return;
	}

	if (*val >= node->data)
		node_add(data, node->right);
	else
		node_add(data, node->left);
}

Del_par *find_elem_and_parent(Del_par *d_p, Data *val)
{
	if (*val == d_p->)
}

void tree_delete_elem(Tree *tree, Data *val)
{
	Del_par *del_par = {
		NULL, tree->root
	};
`
	del_par = find_elem_and_parent(del_par, val);

	if (del == NULL)
		return NULL;

	if (parent == NULL) {
		tree->root == NULL;
		return;
	}

	if (del->left == NULL && del->right == NULL) {
		if (del == parent->left)
			parent->left == NULL;
		if (del == parent->right)
			parent->right == NULL;

		free(del);
		return;
	}


}