/*
 *     File Name: seq_queue.h
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 17:25:10
 */

#ifndef __SEQ_LINK__
#define __SEQ_LINK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define QUEUE_INIT_SIZE 8
#define QUEUEINCREMENT 4

typedef int elem_type;
typedef int status;

typedef struct seq_queue{
	elem_type *base;
	int front;
	int rear;
} seq_queue;

status init_queue(seq_queue *queue);
status is_empty(seq_queue *queue);
status is_full(seq_queue *queue);
status en_queue(seq_queue *queue, elem_type val);
status de_queue(seq_queue *queue, elem_type *p_val);
status get_head(seq_queue *queue, elem_type *p_val);
int get_length(seq_queue *queue);
status show_queue(seq_queue *queue);
status clear_queue(seq_queue *queue);
status destroy_queue(seq_queue *queue);

#endif
