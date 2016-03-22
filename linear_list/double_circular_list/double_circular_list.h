/*
* File Name: double_circular_list.h
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.22 20:58:24
*/

#ifndef __DOUBLE_CIRCULAR_LIST__
#define __DOUBLE_CIRCULAR_LIST__

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

typedef struct dou_cir_list{
	p_node head;
	p_node tail;
	size_t size;
} dou_cir_list;

node* _malloc_node(elem_type val);
status init_list(dou_cir_list *list);
status push_back(dou_cir_list *list, elem_type val);
status show_list(dou_cir_list *list);
status push_front(dou_cir_list *list, elem_type val);
status pop_back(dou_cir_list *list);
status pop_front(dou_cir_list *list);
status insert_val(dou_cir_list *liste, elem_type val);
node* find(dou_cir_list *list, elem_type key);
int get_length(dou_cir_list *list);
status delete_val(dou_cir_list *list, elem_type key);
status sort(dou_cir_list *list);
status resver(dou_cir_list *list);
status clear(dou_cir_list *list);
status destroy(dou_cir_list *list);

node* prior_node(dou_cir_list *list, elem_type val);
node* next_node(dou_cir_list *list, elem_type val);

#endif

