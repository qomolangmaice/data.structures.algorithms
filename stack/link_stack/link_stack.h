/*
 *     File Name: link_stack.h
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 16:24:23
 */

#ifndef __LINK_STACK__
#define __LINK_STACK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;

typedef struct stack_node{
	elem_type data;
	struct stack_node *next;
} stack_node;

typedef stack_node *link_stack;

status init_stack(link_stack *stack);
status push(link_stack *stack, elem_type val);
status pop(link_stack *stack, elem_type *p_val);
status show_stack(link_stack *stack);

#endif
