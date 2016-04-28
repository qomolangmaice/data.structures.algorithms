/*
 *  File Name: AVL_tree.h
 *  Description: Balanced Binary Tree 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.26 20:48:16
 */
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef int elem_type;
typedef int boolean;

typedef struct AVL_node{
 	elem_type data;
	int bf; 	/* balanced fator */
	struct AVL_node *left_child;
	struct AVL_node *right_child;
} AVL_node;

typedef struct AVL_tree{
	AVL_node *root;
} AVL_tree;

void init_AVL_tree(AVL_tree *avl);
AVL_node* _malloc_node(elem_type value);

boolean insert_AVL_tree(AVL_tree *avl, elem_type value);
boolean insert_AVL_tree_(AVL_node **t, elem_type value);

void rotate_right(AVL_node **ptr);
void rotate_left(AVL_node **ptr);
void rotate_left_right(AVL_node **ptr);
void rotate_right_left(AVL_node **ptr);

