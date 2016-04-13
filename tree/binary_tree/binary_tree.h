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
bin_tree_node* create_bin_tree_C_(bin_tree *bt); 	/* Reload */

status create_bin_tree_D(bin_tree *bt, const char *str);
status create_bin_tree_d(bin_tree *bt, bin_tree_node *&t, const char *&str);

/**************************************************************************************/
status pre_order_visit(bin_tree *bt);
status pre_order_visit_(bin_tree_node *t);

status in_order_visit(bin_tree *bt);
status in_order_visit_(bin_tree_node *t);

status post_order_visit(bin_tree *bt);
status post_order_visit_(bin_tree_node *t);

status level_order_visit(bin_tree *bt);
status level_order_visit_(bin_tree_node *t);

status paint_tree(bin_tree *bt);
status paint_tree_(bin_tree_node *t, int nlayer);

/**************************************************************************************/
int bin_tree_count(bin_tree *bt);
int bin_tree_count_(bin_tree_node *t);

int bin_tree_height(bin_tree *bt);
int bin_tree_height_(bin_tree_node *t);

bin_tree_node* search_node(bin_tree *bt, elem_type key);
bin_tree_node* search_node_(bin_tree_node *t, elem_type key);

bin_tree_node* search_parent(bin_tree *bt, bin_tree_node *p);
bin_tree_node* search_parent_(bin_tree_node *t, bin_tree_node *p);

bin_tree_node* search_left_child(bin_tree_node *p);
bin_tree_node* search_right_child(bin_tree_node *p);
status bin_tree_empty(bin_tree *bt);

status copy_bin_tree(bin_tree *bt1, bin_tree *bt2);
status copy_bin_tree_(bin_tree_node **t1, bin_tree_node **t2);

status bin_tree_clear(bin_tree *bt);
status bin_tree_clear_(bin_tree_node **t);

/**************************************************************************************/
/* None recursion visit binary tree */
status nr_pre_order_visit(bin_tree *bt);
status nr_pre_order_visit_(bin_tree_node *t);

status nr_in_order_visit(bin_tree *bt);
status nr_in_order_visit_(bin_tree_node *t);

status nr_post_order_visit(bin_tree *bt);
status nr_post_order_visit_(bin_tree_node *t);

