/*
 *     File Name: cir_seq_queue.h
 *     Description: circular sequence queue
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 21:20:30
 */
#ifndef __CIRCULAR_QUEUE__
#define __CIRCULAR_QUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1 
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 8
#define QUEUEINCREMENT 4

typedef int elem_type;
typedef int status;

typedef struct cir_seq_queue{
	elem_type *base;
	int front;
	int rear;
}cir_seq_queue;

status init_queue(cir_seq_queue *queue);
status is_empty(cir_seq_queue *queue);
status is_full(cir_seq_queue *queue);
status en_queue(cir_seq_queue *queue, elem_type val);
status de_queue(cir_seq_queue *queue);
status show_queue(cir_seq_queue *queue);


#endif
