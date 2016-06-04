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

Node *tree_find_elem(Node *node, int val)
{
	if (node == NULL)
		return NULL;

	if (node->data == val)
		return node;

	if (val > node->data)
		return tree_find_elem(node->right, val);

	if (val <= node->data)
		return tree_find_elem(node->left, val);
}

Node *tree_find_parent(Node *node, Node *del)
{
	if (node == NULL)
		return NULL;

	if (node == del)
		return NULL;

	if (node->left != NULL)
		if (node->left == del)
			return node;
	if (node->right != NULL)
		if (node->right == del)
			return node;

	/*if (del->data == node->data)
		return node;*/

	if (del->data > node->data)
		return tree_find_parent(node->right, del);

	if (del->data < node->data)
		return tree_find_parent(node->left, del);
}

Node* find_min(Node* node)
{
	if (node == NULL)
		return NULL;

	return node->left ? find_min(node->left) : node;
}

void tree_elem_delete(Tree *tree, Node *del)
{
	Node *par = tree_find_parent(tree->root, del);

	if (del == NULL) {
		printf("No such element\n");
		return;
	}

	if (del->left == NULL && del->right == NULL) {
		if (par != NULL) {
			if (par->left == del)
				par->left = NULL;

			if (par->right == del)
				par->right = NULL;

			free(del);
			del = NULL;
		}
		else {
			free(tree->root);
			tree->root = NULL;
		}
		return;
	}

	if (del->left != NULL && del->right == NULL) {
		if (par != NULL) {
			if (par->left == del)
				par->left = del->left;
			if (par->right == del)
				par->right = del->left;
		} 
		else
			tree->root = del->left;

		free(del);
		del = NULL;
		return;
	}

	if (del->left == NULL && del->right != NULL) {
		if (par != NULL) {
			if (par->left == del)
				par->left = del->right;
			if (par->right == del)
				par->right = del->right;
		}
		else
			tree->root = del->right;

		free(del);
		del = NULL;
		return;
	}

	if (del->left != NULL && del->right != NULL) {
		if (del->right->left == NULL) {
			if (par != NULL) {
				if (par->left == del) {
					par->left = del->right;
					par->left->left = del->left;
				}

				if (par->right == del) {
					par->right = del->right;
					par->right->left = del->left;
				}

			}
			else {
				Node *tmp = tree->root->left;
				tree->root = del->right;
				tree->root->left = tmp;
			}

			free(del);
			del = NULL;
			return;
		}

		if (del->right->left != NULL) {

			Node *min = find_min(del->right);

			int tmp = min->data;
			tree_elem_delete(tree, min);

			del->data = tmp;
			return;
		}
	}
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
	printf("Current bords:\n");
	printf("LEFT: %d   RIGHT: %d\n", *l, *r);

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