#include "tree.h"

void print_help()
{
	printf("--------------------------------------\n");
	printf("'e' - exit\n");
	printf("'a' - add one element\n");
	printf("'A' - add few elements\n");
	printf("'d' - delete element\n");
	printf("'p' - print tree\n");
	printf("'l' - in area?\n");
	printf("'c' - change bords\n");
	printf("'b' - print current bords\n");
	printf("'h' - help\n");
	printf("'f' - tree free\n");
	printf("--------------------------------------\n");
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

	return NULL; // we shouldn't be here
}

int main(void)
{
	Tree *tree = NULL;
	
	int left_bord = 0;
	int right_bord = 0;

	printf("Default values of bords - l = 0, r = 0\n");

	print_help();

	while(1) {
		char s;

		if((scanf("%c", &s)) != 1)
			s = 'e';

		int element = 0;

		if (s == '\n') {
			printf("--------------------------------------\n");
			continue;
		}

		if (s == 'e') {
			if (tree != NULL) {
				tree_destroy(&tree);
			}
			return 0;
		}

		if (s == 'a') {
			printf("Insert element:\n");
			scanf("%d", &element);

			if (tree == NULL) {
				tree = tree_create(element);
				continue;
			}
			if (tree->root == NULL)
				tree->root = node_create(element);
			else
				tree_elem_add(tree->root, element);
			continue;
		}

		if (s == 'A') {
			printf("Insert num of elements to add:\n");

			int qty = 0;

			scanf("%d", &qty);
			printf("Insert elements:\n");

			for (int i = qty; i > 0 ; --i) {
				printf("%d - ", i);
				scanf("%d", &element);

				if (tree == NULL) {
					tree = tree_create(element);
					continue;
				}
				if (tree->root == NULL)
					tree->root = node_create(element);
				else 
					tree_elem_add(tree->root, element);
			}
			continue;
		}

		if (s == 'd') {

			if (tree == NULL) {
				printf("Tree is empty\n");
				continue;
			}

			printf("Insert deleted element:\n");
			scanf("%d", &element);

			Node *del = tree_find_elem(tree->root, element);
			if (del == NULL) {
				printf("No such element\n");
				continue;
			}
			tree_elem_delete(tree, del);

			continue;
		}

		if (s == 'p') {
			if (tree == NULL)
				printf("Tree is empty\n");
			else 
				tree_print(tree->root, 0);
			continue;
		}

		if (s == 'l') {
			if (tree == NULL) {
				printf("Tree is empty\n");
				continue;
			}
			if (detour(tree->root, left_bord, right_bord)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			continue;
		}

		if (s == 'c') {

			printf("LEFT: "); 
			scanf("%d", &left_bord);

			printf("RIGHT: ");
			scanf("%d", &right_bord);

			if (left_bord > right_bord) {
				printf("Wrong input, try again\n");
				printf("Press 'c'\n");
			}

			continue;
		}

		if (s == 'b') {
			printf("LEFT: %d\n", left_bord);
			printf("RIGHT: %d\n", right_bord);
			continue;
		}

		if (s == 'h') {
			print_help();
			continue;
		}

		if (s == 'f') {
			if (tree == NULL)
				printf("Tree is empty(under root)\n");
			else 
				tree_destroy(&tree);

			continue;
		}

		printf("Wrong input\n");
	}

	return 0;
}