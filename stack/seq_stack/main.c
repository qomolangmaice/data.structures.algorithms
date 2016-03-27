/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 13:55:12
 */

#include "seq_stack.h"
#include "seq_stack.c"

void main()
{
	seq_stack mystack;
	elem_type val;

	init_stack(&mystack);
	printf("栈初始化完毕.\n");

	for(int i=0; i<10; i++)
	{
		push(&mystack, i);
		printf("入栈数据元素:%d\n", i);
	}

	pop(&mystack, &val);
	printf("出栈栈顶数据元素:%d\n", val);

	get_top(&mystack, &val);
	printf("取得最新栈顶数据元素:%d\n", val);

	printf("栈的长度为:%d\n", get_length(&mystack));

	show_stack(&mystack);
	clear_stack(&mystack);
	printf("栈清空完毕.\n");
	destroy_stack(&mystack);
	printf("栈销毁完毕.\n");
}
