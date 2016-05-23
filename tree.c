#include "tree.h"

Tree *tree_create()
{
	Tree *tree = (Tree*) malloc(sizeof(Tree));

	if (tree == NULL)
		return NULL;

	tree->root = node_create();

	return tree;
}

Data *data_create(Key key, Value value)
{
	Data *data = (Data*) malloc(sizeof(Data));

	if (data == NULL)
		return NULL;

	data->key = key;
	data->value = value;

	return data;
}

void node_add(Data *data, Node *node)
{
	if (node->data == NULL) {
		node->data = data;
		return;
	}

	if (data->key >= node->data->key) {
		if (node->right == NULL) {
			node->right = node_create();
			node->right->data = data;
			return;
		} else {
			node_add(data, node->right);
		}
	} else {
		if (node->left == NULL) {
			node->left = node_create();
			node->left->data = data;
			return;
		} else {
			node_add(data, node->left);
		}
	}
}

Node *node_create()
{
	Node *node = (Node*) malloc(sizeof(Node));

	if (node == NULL)
		return NULL;

	node->left = NULL;
	node->right = NULL;

	return node;
}

Node *tree_find_elem(Node *node, Key key)
{
	if (node == NULL) {
		printf("No element with key %d\n", key);
		return NULL;
	}

	if (node->data->key == key)
		return node;

	if (node->data->key > key)
		return tree_find_elem(node->right, key);

	if (node->data->key < key)
		return tree_find_elem(node->left, key);
}

void tree_delete_elem(Tree *tree, Node *node)
{
	
}

void tree_print_2(Node *node, int lvl)
{
	for (int i = 0; i < lvl; ++i) {
		printf("-");
	}

	if (node == NULL) {
		printf("*\n");
	} else {
		printf("%d\n", node->data->value);
		tree_print_2(node->left, lvl + 1);
		tree_print_2(node->right, lvl + 1);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int tree_depht(Tree *tree)
{
	int depht = 0;

	return node_depht(tree->root, depht + 1);
}

int node_depht(Node *node, int d)
{
	int left_d = d;
	int right_d = d;

	if (node->left)
		left_d = node_depht(node->left, d + 1);
	if (node->right)
		right_d = node_depht(node->right, d + 1);

	return max(left_d, right_d);
}