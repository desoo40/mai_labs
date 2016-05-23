#include "tree.h"

bool lie_in_area(int value, int l, int r)
{
	return value >= l && value <= r;
}

bool detour(Node *node, int l, int r)
{
	if (node->left == NULL && node->right == NULL)
		return lie_in_area(node->data->value, l, r);
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
	printf("Left bord: "); // realise by function
	scanf("%d", l);
	printf("Right bord: ");
	scanf("%d", r);

	if (*l > *r) {
		printf("Wrong input, try again\n");
		bords_insert(l, r);
	}
}

void annotation()
{
	printf("0 - enough\n");
	printf("1 - add node\n");
	printf("2 - print tree\n");
	printf("3 - lie in area?\n");
	printf("4 - change bords\n");
	printf("5 - delete element\n");
	printf("9 - tips\n");
}

void interface(Tree *tree, int *l, int *r)
{
	int s = 0;
	printf("What do with tree?\n");

	annotation();

	while(1) {
		printf("Num of action: ");
		scanf("%d", &s);
		Key key = 0;
		Value value = 0;

		if (s == 0)
			return;

		if (s == 1) {
			printf("Key and value:\n");
			scanf("%d%d", &key, &value);

			Data *node_data = data_create(key, value);

			node_add(node_data, tree->root);
			continue;
		}

		if (s == 2) {
			tree_print_2(tree->root, 0);
			continue;
		}

		if (s == 3) {
			if (detour(tree->root, *l, *r))
				printf("Yes\n");
			else
				printf("No\n");

			continue;
		}

		if (s == 4) {
			bords_insert(l, r);
			continue;
		}

		if (s == 5) {
			printf("Insert key of deleted element:\n");
			scanf("%d", &key);

			Node *find = tree_find_elem(tree->root, key);

			if (find == NULL) {
				printf("NOOOOO\n");
				continue;
			}

			printf("%d\n", find->data->key);
			continue;
		}

		if (s == 9) {
			annotation();
			continue;
		}

		printf("Wrong input try again\n");
	}


}

int main()
{
	Tree *tree = tree_create();
	int left_bord = 0;
	int right_bord = 0;

	bords_insert(&left_bord, &right_bord);

	interface(tree, &left_bord, &right_bord);

	return 0;

}