/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 21:21:38
 */

#include "cir_seq_queue.h"
#include "cir_seq_queue.c"

void main()
{
	cir_seq_queue myqueue;
	elem_type val;

	init_queue(&myqueue);

	for(int i=1; i<=8; ++i)
	{
		en_queue(&myqueue, i);
		printf("入队(从队尾插入-尾插)数据元素:%d\n", i);
	}

	show_queue(&myqueue);
	de_queue(&myqueue);
	en_queue(&myqueue, 10);

	/* Test for queue->front */
	for(int i=1; i<=7; ++i)
	 	de_queue(&myqueue);

	en_queue(&myqueue, 20);
	show_queue(&myqueue);
}
