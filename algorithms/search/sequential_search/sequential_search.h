/*
 *  File Name: sequential_search.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.24 19:01:29
 */
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define SEQTABLE_INIT_SIZE 10
typedef int elem_type;

typedef struct{
	elem_type *base;
	int size;
} seq_table;

void init_seq_table(seq_table *st);
void create_seq_table(seq_table *st);
void show_seq_table(seq_table *st);
void sequential_search(seq_table *st, elem_type key);
