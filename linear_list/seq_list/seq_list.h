/*
 * File Name: seq_list.c
 * Description: sequential linear list 
 * Author: iczelion
 * Email: qomolangmaice@163.com 
 * Created: 2016.03.05 22:33:06
 */
#ifndef _SEQ_LIST_H
#define _SEQ_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define TRUE  1
#define FALSE 0
#define OK 	  1
#define ERROR 0

#define SEQLIST_INIT_SIZE 10
#define INC_SIZE 3
typedef int status;
typedef int boolean;
typedef int elem_type;

typedef struct{
	elem_type *base;
	int capacity; 	 	
	int size; 	 	 	
} seq_list;

boolean inc(seq_list *list);
status init_seq_list(seq_list *list);
status push_back(seq_list *list, elem_type item);
status push_front(seq_list *list, elem_type item);
status show_list(seq_list *list);
status pop_back(seq_list *list);
status pop_front(seq_list *list);
status insert_pos(seq_list *list, int pos, elem_type item);
status find(seq_list *list, elem_type item);
int get_length(seq_list *list);
status delete_pos(seq_list *list, int pos);
status delelte_val(seq_list *list, elem_type val);
status sort(seq_list *list);
status resver(seq_list *list);
status clear(seq_list *list);
status destroy(seq_list *list);
status merge_list(seq_list *lc, seq_list *la, seq_list *lb);

#endif //_SEQ_LIST_H
