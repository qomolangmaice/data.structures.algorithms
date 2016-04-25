/*
 *  File Name: binary_sort_tree.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.25 19:32:49
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef int elem_type; 
typedef int boolean;

typedef struct bst_node{
	elem_type data;
	struct bst_node *left_child;
	struct bst_node *right_child;
} bst_node;

typedef struct bin_sort_tree{
	bst_node *root;
} bin_sort_tree;

void init_bin_sort_tree(bin_sort_tree *bst);

boolean insert_bin_sort_tree(bin_sort_tree *bst, elem_type value);
boolean insert_bin_sort_tree_(bst_node **t, elem_type value);

elem_type get_min_value(bin_sort_tree *bst);
elem_type get_min_value_(bst_node *t);

elem_type get_max_value(bin_sort_tree *bst);
elem_type get_max_value_(bst_node *t);

void sort(bin_sort_tree *bst);
void sort_(bst_node *t);

bst_node* search_bin_sort_tree(bin_sort_tree *bst, elem_type key);
bst_node* search_bin_sort_tree_(bst_node *t, elem_type key);

void make_empty_bin_sort_tree(bin_sort_tree *bst);
void make_empty_bin_sort_tree_(bst_node **t);

boolean delete_bin_sort_tree(bin_sort_tree *bst, elem_type key);
boolean delete_bin_sort_tree_(bst_node **t, elem_type key);

