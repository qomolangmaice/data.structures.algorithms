/*
 *  File Name: thread_binary_tree.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.16 19:21:38
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef char elem_type;

typedef enum{LINK, THREAD}TAG_TYPE;

typedef struct bin_tree_node {
	elem_type data;
	struct bin_tree_node *left_child;
	struct bin_tree_node *right_child;
	TAG_TYPE ltag;
	TAG_TYPE rtag;
} bin_tree_node;

typedef struct bin_tree {
	bin_tree_node *root;
	elem_type refvalue; 	/* stop flag */
} bin_tree;

void init_bin_tree(bin_tree *bt, elem_type ref);
void create_bin_tree(bin_tree *bt, char *str);
void create_bin_tree_(bin_tree *bt, bin_tree_node **t, char **str);

void create_in_thread(bin_tree *bt);
void create_in_thread_(bin_tree_node **t, bin_tree_node **pre);
