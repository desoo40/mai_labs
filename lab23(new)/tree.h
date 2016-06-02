#ifndef __TREE_H__
#define __TREE_H__

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint32_t Data;

typedef struct _node {
	struct Node *left;
	struct Node *right;
	Data *value;
} Node;

tyypedef struct _tree {
	Node *root;

} Tree;

Tree *tree_create();
Node *tree_node_create();
void tree_add_elem(Tree *tree, Data *value);
void tree_elem_delete(Tree *tree, Data *value);
bool is_lists_in_area(Tree *tree);
void tree_print(Tree *tree);

#endif