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
	if (node == NULL) {
		return;
	}
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
	node->data = NULL;

	return node;
}

Node *tree_find_elem(Node *node, Key key)
{
	if (node == NULL) {
		printf("No element with key %d\n", key);
		return NULL;
	}

	if (node->data == NULL) {
		printf("No data in node\n");
		return NULL;
	}

	if (node->data->key == key)
		return node;

	if (node->data->key > key)
		return tree_find_elem(node->left, key);

	if (node->data->key < key)
		return tree_find_elem(node->right, key);
}

void tree_delete_elem(Tree *tree, Node *node, Node *parent)
{
	if (node == NULL)
		return;

	if (node->left == NULL && node->right == NULL) {
		if (parent != NULL) {
			if (parent->left == node) 
				parent->left = NULL;
			else 
				parent->right = NULL;
		}
		else 
			tree->root = NULL;
		free(node);
		return;
	}

	if (node->left != NULL && node->right == NULL) {
		if (parent != NULL) {
			if (parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
		}
		else
			tree->root = node->left;
		free(node);
		return;
	}

	if (node->right != NULL && node->left == NULL) {
		if (parent != NULL) {
			if (parent->left == node)
				parent->left = node->right;
			else
				parent->right = node->right;
		}
		else 
			tree->root = node->right;
		free(node);
		return;
	}

	if (node->left != NULL && node->right != NULL) {

		Node *r = node->right;
		Node *l = r->left;
		Node *min_val = NULL;

		if (l == NULL) {
			min_val = r;

			if (parent != NULL)
				parent->right = min_val;
			else
				tree->root = min_val;

			min_val->left = node->left;
			free(node);
			return;
		}

		else {
			Node *l_parent = r; 
			min_val = l;

			while (min_val->left != NULL) {
				l_parent = min_val;
				min_val = min_val->left;
			}

			l_parent->left = NULL;
			
			if (parent != NULL)  {
				if (parent->left == node)
					parent->left = min_val;
				else
					parent->right = min_val;
			}

			else
				tree->root = min_val;

			min_val->left = node->left;
			min_val->right = node->right;
			free(node);
			return;
		}
	}
}

Node *tree_find_parent(Node *parent, Node *child)
{
	if (parent == NULL)
		return NULL;

	if (parent == child)
		return NULL;

	if (parent->left == child || parent->right == child)
		return parent;

	if (parent->data->key > child->data->key)
		return tree_find_parent(parent->left, child);

	if (parent->data->key < child->data->key)
		return tree_find_parent(parent->right, child);
}

void tree_print_2(Node *node, int lvl) // my code
{
	for (int i = 0; i < lvl; ++i) {
		printf("+	");
	}

	if (node == NULL) {
		printf("*\n");
	} else {
		printf("%d\n", node->data->value);
		tree_print_2(node->left, lvl + 1);
		tree_print_2(node->right, lvl + 1);
	}
}

int _print_t(Node *node, int is_left, int offset, int depth, char s[20][255]) //somebody code
{
    char b[20];
    int width = 5;

    if (!node) return 0;

    sprintf(b, "(%03d)", node->data->value);

    int left  = _print_t(node->left,  1, offset,                depth + 1, s);
    int right = _print_t(node->right, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

void print_t(Tree *tree)
{
	if (tree->root == NULL) {
		printf("No tree\n");
		return;
	}
	if (tree->root->data == NULL)
	{
		printf("No data\n");
		return;
	}
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree->root, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

int _max(int a, int b)
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

	return _max(left_d, right_d);
}