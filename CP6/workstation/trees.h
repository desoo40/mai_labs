#ifndef _TREES_H_
#define _TREES_H_

#include "class.h"

typedef struct _letter_node Letter_node;
typedef struct _year_node Year_node;

struct _letter_node {
	Letter_node *left;
	Letter_node *right;
	Class *class;
	char letter;
};

typedef struct {
	Letter_node *root;
} Letter_tree;

struct _year_node {
	Year_node *left;
	Year_node *right;
	Letter_tree *l_tree;
	Date date;
};

typedef struct {
	Year_node *root;
} Year_tree;

Year_tree *year_tree_create(Graduate *graduate);
Letter_tree *letter_tree_create(Graduate *graduate);
Year_node *year_node_create(Graduate *graduate);
Letter_node *letter_node_create(Graduate *graduate);
void year_tree_add_grad(Year_node *node, Graduate *graduate);
void letter_tree_add_grad(Letter_node *node, Graduate *graduate);

#endif