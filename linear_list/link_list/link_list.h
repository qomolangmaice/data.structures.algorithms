/*
* File Name: link_list.h
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:37:46
*/

#ifndef __LINK_LIST__
#define __LINK_LIST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;
typedef int boolean;

typedef struct node {
	elem_type data;
	struct node *next;
} node, *p_node;

typedef struct link_list{
	p_node head;
	p_node tail;
	size_t size;
} link_list; 

status init_list(link_list *list);
status push_back(link_list *list, elem_type item);
status show_list(link_list *list);
status push_front(link_list *list, elem_type item);
status pop_back(link_list *list);
status pop_front(link_list *list);
status insert_val(link_list *liste, elem_type val);
node* find(link_list *list, elem_type key);
int get_length(link_list *list);
status delete_val(link_list *list, elem_type key);

#endif 
