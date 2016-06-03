#include "tree.h"

Tree *tree_create(int val)
{
	Tree *tree = (Tree*) malloc(sizeof(Tree));

	if (tree == NULL)
		return NULL;

	tree->root = node_create(val);

	return tree;
}

void tree_elem_add(Node *node, int val)
{
	if (node == NULL) {
		return;
	}

	if (val > node->data) {
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

Node *node_create(int val)
{
	Node *node = (Node*) malloc(sizeof(Node));

	if (node == NULL)
		return NULL;

	node->left = NULL;
	node->right = NULL;
	node->data = val;

	return node;
}

void tree_print(Node *node, int lvl)
{
	if (node == NULL) {
		printf("Tree is empty\n");

		return;
	}

	for (int i = 0; i < lvl; i++)
		printf("  ");

	printf("%d\n", node->data);

		if (node->left != NULL)
			tree_print(node->left, lvl + 1);

		if (node->right != NULL)
			tree_print(node->right, lvl + 1);
}

void tree_elem_delete(Tree *tree, int val)
{
	printf("Hello\n");
}

void tree_free(Node *node) 
{
	if (node == NULL) 
		return;
	tree_free(node->left);
	tree_free(node->right);

	node->left = NULL;
	node->right = NULL;	

	free(node);	
}

bool lie_in_area(int value, int l, int r)
{
	return value >= l && value <= r;
}

bool detour(Node *node, int l, int r)
{
	if (node == NULL) {
		printf("Tree is empty\n");
		return NULL;
	}

	if (l == 0 && r == 0) {
		printf("You may be forgot insert bords...\n");
		printf("Press [y] to insert bords, or some else button to continue\n");

		char s;

		scanf("%s", &s);

		if (s == 'y')
			bords_insert(&l, &r);
	}


	if (node->left == NULL && node->right == NULL)
		return lie_in_area(node->data, l, r);

	if (node->left == NULL && node->right)
		return detour(node->right, l, r);

	if (node->right == NULL && node->left)
		return detour(node->left, l, r);

	if (node->left && node->right) {
		if (detour(node->left, l, r) && detour(node->right, l, r))
			return true;
		else
			return false;
	}
}

void bords_insert(int *l, int *r)
{
	printf("Insert bords:\n");
	printf("Left bord: "); 
	scanf("%d", l);
	printf("Right bord: ");
	scanf("%d", r);

	if (*l > *r) {
		printf("Wrong input, try again\n");
		bords_insert(l, r);
	}
}