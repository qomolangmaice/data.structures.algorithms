/*
* File Name: circular_list.h
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.18 19:41:55
*/

#ifndef __CIRCULAR_LIST__
#define __CIRCULAR_LIST__
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;

typedef struct node {
	elem_type data;
	struct node *next;
} node, *p_node;

typedef struct circular_list{
	p_node head;
	p_node tail;
	size_t size;
} circular_list;

node* _malloc_node(elem_type val);
status init_list(circular_list *list);
status push_back(circular_list *list, elem_type item);
status show_list(circular_list *list);
status push_front(circular_list *list, elem_type item);
status pop_back(circular_list *list);
status pop_front(circular_list *list);
status insert_val(circular_list *liste, elem_type val);
node* find(circular_list *list, elem_type key);
int get_length(circular_list *list);
status delete_val(circular_list *list, elem_type key);
status sort(circular_list *list);
status resver(circular_list *list);
status clear(circular_list *list);
status destroy(circular_list *list);

node* prior_node(circular_list *list, elem_type val);
node* next_node(circular_list *list, elem_type val);

#endif
