#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_ {
    struct Node_ *left;
    struct Node_ *right;
    int data;
} Node;

typedef struct {
	Node *root;
} Tree;

Tree *tree_create(int val);
void tree_elem_add(Node *node, int val);
Node *node_create(int val);
void tree_elem_delete(Tree *tree, int val);
void tree_print(Node *node, int lvl);
bool detour(Node *node, int l, int r);
bool lie_in_area(int value, int l, int r);
void bords_insert(int *left, int *right);
void tree_free(Node *node);

#endif