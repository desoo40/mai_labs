#include "tree.h"
#include "queue.h"

Tree *tree_create(Data *data)
{
	Tree *tree = (Tree*)malloc(sizeof(Tree));

	tree->left = NULL;
	tree->right = NULL;
	tree->data = data;

	return tree;
}

void tree_print(Tree *tree, int lvl)
{
	if (tree == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	for (int i = 0; i < lvl; i++)
		printf("  ");

	if (tree->data->is_char)
		printf("%c\n", tree->data->symbol);
	else
		printf("%d\n", tree->data->symbol);

	if (tree->left != NULL)
		tree_print(tree->left, lvl + 1);

	if (tree->right != NULL)
		tree_print(tree->right, lvl + 1);
}

int find_tree_depht(Tree* tree, int d)
{
	if (tree == NULL)
		return d;

	return max(find_tree_depht(tree->left, d + 1),
			   find_tree_depht(tree->right, d + 1));
}

int two_power(int lvl)
{
	return lvl == 0 ? 1 : 2 * two_power(lvl - 1);
}

void do_spaces(int spaces)
{
	for (int i = 0; i < spaces; ++i)
	{
		printf(" ");
	}
}

void tree_BFS_print(Tree *tree)
{
	if (tree == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	Queue *que = queue_create(tree);

	Tree *for_print = (Tree*)malloc(sizeof(Tree));
	for_print->left = NULL;
	for_print->right = NULL;
	for_print->data = (Data*)malloc(sizeof(Data));
	for_print->data->symbol = '#';
	for_print->data->is_char = true;

	int tree_depht = find_tree_depht(tree, -1);
	int lvl = 0;
	int print_times = two_power(lvl);
	int spaces = two_power(tree_depht) - 1;
	do_spaces(spaces);
	int hash = 0;

	while (!queue_is_empty(que))
	{
		Tree *tmp = queue_top(que)->tree;
		queue_pop(que);

		if (print_times == 0)
		{
			if (hash == two_power(lvl + 1))
			{
				printf("\n");
				queue_destroy(&que);
				return;
			}

			hash = 0;
			spaces -= two_power(lvl);
			printf("\n");
			do_spaces(spaces);

			print_times = two_power(++lvl);
		}

		if (tmp->data->is_char)
			printf("%c ", tmp->data->symbol);
		else
			printf("%d ", tmp->data->symbol);

		--print_times;

		if (tmp->left)
			queue_push(que, tmp->left);
		else {
			queue_push(que, for_print);
			++hash;
		}

		if (tmp->right)
			queue_push(que, tmp->right);
		else {
			queue_push(que, for_print);
			++hash;
		}
	}
}

Tree *tree_build(Stack *out)
{
	if (stack_is_empty(out))
		return NULL;

	Tree *tree = tree_create(stack_top(out));
	stack_pop(out);

	if (is_t(tree->data))
	{
		tree->right = tree_build(out);
		tree->left = tree_build(out);
	}

	return tree;
}
