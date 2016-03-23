/*
* File Name: double_link_list.h
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.20 17:09:31
*/

#ifndef __DOUBLE_LINK_LIST__
#define __DOUBLE_LINK_LIST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;

typedef struct node {
	elem_type data;
	struct node *prior;
	struct node *next;
} node, *p_node;

typedef struct d_link_list {
	p_node head;
	p_node tail;
	size_t size;
} d_link_list;

node* _malloc_node(elem_type val);
status init_list(d_link_list *list);
status push_back(d_link_list *list, elem_type val);
status show_list(d_link_list *list);
status push_front(d_link_list *list, elem_type val);
status pop_back(d_link_list *list);
status pop_front(d_link_list *list);
status insert_val(d_link_list *liste, elem_type val);
node* find(d_link_list *list, elem_type key);
int get_length(d_link_list *list);
status delete_val(d_link_list *list, elem_type key);
status sort(d_link_list *list);
status resver(d_link_list *list);
status clear(d_link_list *list);
status destroy(d_link_list *list);

node* prior_node(d_link_list *list, elem_type val);
node* next_node(d_link_list *list, elem_type val);

#endif
