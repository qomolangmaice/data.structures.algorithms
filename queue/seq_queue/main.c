/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 17:25:47
 */

#include "seq_queue.h"
#include "seq_queue.c"

void main()
{
 	seq_queue myqueue;	
	elem_type val;

	init_queue(&myqueue);

	for(int i=1; i<=5; ++i)
	{
		en_queue(&myqueue, i);
		printf("入队(从队尾插入-尾插)数据元素:%d\n", i);
	}

	get_head(&myqueue, &val);
	printf("取得对头数据元素:%d\n", val);
	de_queue(&myqueue, &val);
	printf("出队(从对头删除-头删)数据元素:%d\n", val);

	printf("队列的长度为:%d\n", get_length(&myqueue));

	printf("队列中数据元素分别为:");
	show_queue(&myqueue);
	clear_queue(&myqueue);
	printf("队列清空完毕.\n");
	destroy_queue(&myqueue);
	printf("队列销毁完毕.\n");
}
