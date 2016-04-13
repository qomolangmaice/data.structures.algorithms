/*
 *     File Name: link_queue.h
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 13:00:55
 */
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

struct bin_tree_node;
//#define q_elem_type bin_tree_node*
//typedef int elem_type;
typedef bin_tree_node* q_elem_type;
typedef int status;

typedef struct queue_node {
 	q_elem_type data;
	struct queue_node *next;
} queue_node; 

typedef struct link_queue{
	queue_node *head;
	queue_node *tail;
}link_queue;

status init_queue(link_queue *queue);
status queue_is_empty(link_queue *queue);
status en_queue(link_queue *queue, q_elem_type val);
//status de_queue(link_queue *queue, q_elem_type *p_val);
status de_queue(link_queue *queue);
status get_head(link_queue *queue, q_elem_type *p_val);
int get_length(link_queue *queue);
status show_queue(link_queue *queue);
status clear_queue(link_queue *queue);
status destroy_queue(link_queue *queue);
