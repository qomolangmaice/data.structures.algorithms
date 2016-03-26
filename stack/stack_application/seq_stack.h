/*
 *     File Name: seq_stack.h
 *     Description: sequence stack
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 13:51:24
 */

#ifndef __SEQ_STACK__
#define __SEQ_STACK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int elem_type;
typedef int status;

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 8
#define STACKINCREMENT 4

typedef struct seq_stack{
	elem_type *base;
	elem_type *top;
	int stacksize;
} seq_stack;

status init_stack(seq_stack *stack);
status is_empty(seq_stack *stack);
status is_full(seq_stack *stack);
status push(seq_stack *stack, elem_type val);
status pop(seq_stack *stack, elem_type *p_val);
status get_top(seq_stack *stack, elem_type *p_val);
int get_length(seq_stack *stack);
status show_stack(seq_stack *stack);
status destroy_stack(seq_stack *stack);

#endif
