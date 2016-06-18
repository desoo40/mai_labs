#include "tree.h"
#include "queue.h"
#include "matem.h"

Tree *tree_create(Data *data)
{
	Tree *tree = (Tree*)malloc(sizeof(Tree));

	tree->left = NULL;
	tree->right = NULL;
	tree->data = (Data*)malloc(sizeof(Data));

	if (is_t(data) || data->symbol == 'x')
		tree->data->is_char = true;
	else if (is_d(data))
		tree->data->is_char = false;
	
	tree->data->symbol = data->symbol;

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

	return _max(find_tree_depht(tree->left, d + 1),
			   find_tree_depht(tree->right, d + 1));
}

void do_spaces(int spaces)
{
	for (int i = 0; i < spaces; ++i)
	{
		printf(" ");
	}
}

void tree_destroy(Tree** tree)
{
	if (*tree == NULL)
		return;

	tree_destroy(&((*tree)->left));
	tree_destroy(&((*tree)->right));
	free((*tree)->data);
	(*tree)->data = NULL;
	free(*tree);
	*tree = NULL;
}

void tree_BFS_print(Tree *tree)
{
	if (tree == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	Queue *que = queue_create(tree);
	Data *tmp_data = data_create('#');
	Tree *for_print = tree_create(tmp_data);

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
				tree_destroy(&for_print);
				free(tmp_data);
				tmp_data = NULL;
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

void tree_DFS_print(Tree *tree)
{
	if (tree == NULL)
		return;

	tree_DFS_print(tree->left);

	if (tree->data->is_char)
		printf("%c ", tree->data->symbol);
	else
		printf("%d ", tree->data->symbol);

	tree_DFS_print(tree->right);
	
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

void *tree_simplifier(Tree *tree)
{
	if (tree == NULL)
		return NULL;

	tree_simplifier(tree->left);
	tree_simplifier(tree->right);

	if (is_t(tree->data))
	{
		if (tree->data->symbol == '+' && tree->right->data->symbol < 0)
		{
			tree->data->symbol = '-';
			tree->right->data->symbol *= -1;
		}

		if (!tree->left->data->is_char && !tree->right->data->is_char)
		{
			tree->data->symbol = operation(tree->data->symbol, tree->left->data->symbol, tree->right->data->symbol);
			tree->data->is_char = false;
			tree_destroy(&(tree->left));
			tree_destroy(&(tree->right));
		}
	}
}
