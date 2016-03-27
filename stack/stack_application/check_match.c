/*
 *     File Name: check_match.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 22:24:33
 */
#include "seq_stack.h"
#include "seq_stack.c"

boolean check_match(char *str)
{
	seq_stack stack;
	char val;

	init_stack(&stack);

	while(*str != '\0')
	{
		if(*str == '[' || *str == '(')
			push(&stack, *str);
		else if(*str == ']')
		{
			get_top(&stack, &val);
			if(val != '[')
				return FALSE;
			pop(&stack, &val);
		}
		else if(*str == ')')
		{
			get_top(&stack, &val);
			if(val != '(')
				return FALSE;
			pop(&stack, &val);
		}
		++str;
	}
	return is_empty(&stack);
}

void main()
{
	char *str = "[([][])]";
	boolean flag = check_match(str);
	if(flag)
		printf("Check for match is OK!\n");
	else
		printf("Error: None is for match!\n");
}
