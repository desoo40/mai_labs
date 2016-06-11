#include "trees.h"
#include "graduate.h"
#include "class.h"


Year_tree *year_tree_create(Graduate *graduate)
{
	Year_tree *tree = (Year_tree*) malloc(sizeof(Year_tree));

	tree->root = year_node_create(graduate);

	return tree;
}

Year_node *year_node_create(Graduate *graduate)
{
	Year_node *node = (Year_node*) malloc(sizeof(Year_node));

	node->left = NULL;
	node->right = NULL;
	node->l_tree = letter_tree_create(graduate);
	node->date = graduate->issue;

	return node;
}

Letter_tree *letter_tree_create(Graduate *graduate)
{
	Letter_tree *tree = (Letter_tree*) malloc(sizeof(Letter_tree));

	tree->root = letter_node_create(graduate);

	return tree;
} 

Letter_node *letter_node_create(Graduate *graduate)
{
	Letter_node *node = (Letter_node*) malloc(sizeof(Letter_node));

	node->left = NULL;
	node->right = NULL;
	node->class = class_create();

	if (graduate->gender == 'M')
		++node->class->male_qty;
	if (graduate->gender == 'F')
		++node->class->female_qty;

	node->letter = graduate->class_letter;

	return node;
}

void letter_tree_add_grad(Letter_node *node, Graduate *graduate)
{
	if (node == NULL)
		return;

	if (graduate->class_letter == node->letter) {

		if (graduate->gender == 'M')
			++node->class->male_qty;

		if (graduate->gender == 'F')
			++node->class->female_qty;

		return;
	}

	if (graduate->class_letter > node->letter) {
		if (node->right == NULL) {
			node->right = letter_node_create(graduate);
			return;
		}
		else
			letter_tree_add_grad(node->right, graduate);
	}

	if (graduate->class_letter < node->letter) {
		if (node->left == NULL) {
			node->left = letter_node_create(graduate);
			return;
		}
		else
			letter_tree_add_grad(node->left, graduate);
	}
}

void year_tree_add_grad(Year_node *node, Graduate *graduate)
{
	if (node == NULL)
		return;

	if (graduate->issue == node->date)
		letter_tree_add_grad(node->l_tree->root, graduate);

	if (graduate->issue > node->date) {
		if (node->right == NULL) {
			node->right = year_node_create(graduate);
			return;
		} else
			year_tree_add_grad(node->right, graduate);
	} 

	if (graduate->issue < node->date) {
		if (node->left == NULL) {
			node->left = year_node_create(graduate);
			return;
		} else
			year_tree_add_grad(node->left, graduate);
	}
}