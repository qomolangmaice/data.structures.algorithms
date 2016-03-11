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

typedef struct list_node{
	elem_type data;
	struct list_node *next;
} list_node;

typedef list_node *link_list;

status init_list(link_list *head);
status create_list(link_list *head);


#endif 
