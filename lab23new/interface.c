#include "interface.h"

void interface(Tree *tree)
{
	int left_bord = 0;
	int right_bord = 0;

	printf("Default values of bords - l = 0, r = 0\n");

	annotation();

	while(1) {
		printf("--------------------------------------\n");
		char s;
		scanf("%s", &s);

		int element = 0;

		if (s == 'e')
			return;

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
			bords_insert(&left_bord, &right_bord);
			continue;
		}

		if (s == 'h') {
			continue;
		}

		if (s == 'f') {
			if (tree == NULL)
				printf("Tree is empty(under root)\n");
			else {
				tree_free(tree->root);
				tree->root = NULL;				
				free(tree);
				tree = NULL;
			}
			continue;
		}	
	}
}

void annotation()
{
	printf("--------------------------------------\n");
	printf("'e' - exit\n");
	printf("'a' - add one element\n");
	printf("'A' - add few elements\n");
	printf("'d' - delete element\n");
	printf("'p' - print tree\n");
	printf("'l' - in area?\n");
	printf("'c' - change bords\n");
	printf("'h' - help\n");
	printf("'f' - tree free\n");
	printf("--------------------------------------\n");
}