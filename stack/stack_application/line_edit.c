/*
 *     File Name: line_edit.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 11:33:14
 */

#include "seq_stack.h"
#include "seq_stack.c"

void line_edit()
{
	seq_stack stack;
	init_stack(&stack);

	char ch = getchar();
	char val;
	while(ch != '$')
	{
		while(ch != '$' && ch != '\n')
		{
			switch(ch)
			{
				case '#':
					pop(&stack, &val);
					break;
				case '@':
					clear_stack(&stack);
					break;
				default:
					push(&stack, ch);
					break;
			}
			ch = getchar();
		}
		show_stack(&stack);
		ch = getchar();
	}
	destroy_stack(&stack);
}

void main()
{
	line_edit();
}
