/*
* File Name: static_list.h
* Description: static link list
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.17 19:48:35
*/

#ifndef __STATIC_LIST__
#define __STATIC_LIST__

#include <stdio.h>

#define OK 1
#define ERROR 0

#define MAX_SIZE 20

typedef char elem_type;
typedef int status;

typedef struct static_node {
	elem_type data;
	int cur;
} static_node;

typedef static_node static_list[MAX_SIZE];

int malloc_static_list(static_list &space);
status init_list(static_list &space); 	/* space 表示引用 */
status insert(static_list &space, elem_type val);
status delete_node(static_list &space);
status show_list(static_list &space);

#endif

