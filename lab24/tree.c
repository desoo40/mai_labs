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

bool is_d(Data *data)
{
	return (!data->is_char || data->symbol == 'x');
}

bool is_t(Data *data)
{
	return data->is_char && data->symbol != 'x';
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

void tree_BFS_print(Tree *tree)
{
	if (tree == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	Queue *que = queue_create(tree);

	while (!queue_is_empty(que))
	{
		Tree *tmp = queue_top(que)->tree;
		queue_pop(que);

		if (tree->data->is_char)
			printf(" %c\n", tree->data->symbol);
		else
			printf(" %d\n", tree->data->symbol);

		if (tmp->left)
			queue_push(que, tmp->left);
		if (tmp->right)
			queue_push(que, tmp->right);
	}

	queue_destroy(&que);
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
