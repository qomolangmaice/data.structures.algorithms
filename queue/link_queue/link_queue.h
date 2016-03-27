/*
 *     File Name: link_queue.h
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 13:00:55
 */


#ifndef __LINK_QUEUE__
#define __LINK_QUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;

typedef struct queue_node {
 	elem_type data;
	struct queue_node *next;
} queue_node; 

typedef struct link_queue{
	queue_node *front;
	queue_node *tail;
}link_queue;

queue_node* _malloc_node(elem_type val);
status init_queue(link_queue *queue);
status en_queue(link_queue *queue, elem_type val);
status show_queue(link_queue *queue);

#endif
