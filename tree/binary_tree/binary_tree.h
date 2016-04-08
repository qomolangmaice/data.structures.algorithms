/*
 *  File Name: binary_tree.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:15
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0

typedef char elem_type;
typedef int status; 

typedef struct bin_tree_node{
	elem_type data;
	struct bin_tree_node *left_child;
	struct bin_tree_node *right_child;
} bin_tree_node;

typedef struct bin_tree{
 	bin_tree_node *root;
	elem_type refvalue; 	/* stop flag */
} bin_tree;

status init_bin_tree(bin_tree *bt, elem_type ref);
status create_bin_tree_A(bin_tree *bt);
status create_bin_tree_a(bin_tree *bt, bin_tree_node **t);

status create_bin_tree_B(bin_tree *bt);
status create_bin_tree_b(bin_tree *bt, bin_tree_node *&t);

status create_bin_tree_C(bin_tree *bt);
bin_tree_node* create_bin_tree_C_(bin_tree *bt);
