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

#define TRUE 1
#define FALSE 0

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
status create_bin_tree_D(bin_tree *bt, const char *str);
status create_bin_tree_d(bin_tree *bt, bin_tree_node *&t, const char *&str);

status nr_post_order_visit(bin_tree *bt);
status nr_post_order_visit_(bin_tree_node *t);

