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
	init_queue(&myqueue);

	for(int i=1; i<=10; ++i)
	{
		en_queue(&myqueue, i);
		printf("入队数据元素:%d\n", i);
	}

	show_queue(&myqueue);
}
