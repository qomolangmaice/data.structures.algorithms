/*
 *  File Name: tree.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.19 20:41:16
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef char elem_type;

typedef struct tree_node{
	elem_type data;
	struct tree_node *first_child;
	struct tree_node *next_sibling;
} tree_node;

typedef struct tree{
	tree_node *root;
	elem_type refvalue;
} tree;

void init_tree(tree *tree, elem_type ref);
void create_tree(tree *tree, char *str);
void create_tree_(tree *tree, tree_node **t, char **str);

tree_node* root(tree *tree);

tree_node* first_child(tree *tree);
tree_node* first_child_(tree_node *t);

tree_node* next_sibling(tree *tree);
tree_node* next_sibling_(tree_node *t);

tree_node* find(tree *tree, elem_type key);
tree_node* find_(tree_node *t, elem_type key);

tree_node* parent(tree *tree, tree_node *p);
tree_node* parent_(tree_node *t, tree_node *p);






