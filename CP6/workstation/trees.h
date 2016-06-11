#ifndef _TREES_H_
#define _TREES_H_

typedef struct {
	Letter_node *root;
} Letter_tree;

typedef struct {
	Letter_node *left;
	Letter_node *right;
	Class *cl;
} Letter_node;

typedef struct {
	Year_node *root;
} Year_tree;

typedef struct {
	Year_node *left;
	Year_node *right;
	Letter_tree *l_tree;
} Year_node;

Year_tree *year_tree_create();
void year_tree_add_grad(Year_node *node, Graduate *graduate);

#endif