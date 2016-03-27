/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 13:01:04
 */

#include "link_queue.h"
#include "link_queue.c"

void main()
{
	link_queue myqueue;
	elem_type val;

	init_queue(&myqueue);
	is_empty(&myqueue);

	for(int i=1; i<=10; ++i)
	{
		en_queue(&myqueue, i);
		printf("入队(从队列尾插入数据-尾插)数据元素:%d\n", i);
	}

	de_queue(&myqueue, &val);
	printf("出队(从队列头删除数据-头删)数据元素:%d\n", val);
	get_head(&myqueue, &val);
	printf("取得队列对头数据元素为:%d\n", val);
	printf("队列的长度为:%d\n", get_length(&myqueue));
	show_queue(&myqueue);
	clear_queue(&myqueue);
	printf("队列清空完毕.\n");
	destroy_queue(&myqueue);
	printf("队列销毁完毕.\n");
}
