#include "interface.h"

void interface(Tree *tree)
{
	int left_bord = 0;
	int right_bord = 0;

	printf("Default values of bords - l = 0, r = 0\n");

	while(1) {
		annotation();
		char s;
		int element = 0;
		scanf("%s", &s);

		if (s == 'e')
			return;

		if (s == 'a') {
			printf("Insert element:\n");
			scanf("%d", &element);

			if (tree == NULL)
				tree = tree_create(element);
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

				if (tree == NULL)
					tree = tree_create(element);
				else 
					tree_elem_add(tree->root, element);
			}
			continue;
		}

		if (s == 'd') {
			printf("Insert deleted element:\n");
			scanf("%d", &element);

			tree_elem_delete(tree, element);
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
			annotation();
			continue;
		}

		if (s == 'f') {
			if (tree == NULL)
				printf("Tree is empty\n");
			else {
				tree_free(tree->root);
				free(tree);
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