/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 16:30:58
 */

#include "link_stack.h"
#include "link_stack.c"

void main()
{
	link_stack my_linkstack;
	elem_type val;

	init_stack(&my_linkstack);

	for(int i=1; i<=5; ++i)
	{
		push(&my_linkstack, i);
		printf("入链栈数据元素:%d\n", i);
	}

	pop(&my_linkstack, &val);
	printf("出栈链栈栈顶数据元素:%d\n", val);
	show_stack(&my_linkstack);
}
