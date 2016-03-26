/*
 *     File Name: conversion.c
 *     Description: Hexademical conversion 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 18:27:19
 */

#include "seq_stack.h"
#include "seq_stack.c"

void conversion_8(int value)
{
	seq_stack stack;
	elem_type val;

	init_stack(&stack);

   	while(value)	
	{
		push(&stack, value % 8);
		value /= 8;
	}

	while(!is_empty(&stack))
	{
		get_top(&stack, &val);
		pop(&stack, &val);
		printf("%d", val);
	}
	printf("\n");
}

void main()
{
	int value;
  	int select = 1;	

	while(select)
	{
		printf("***********************\n");
		printf("* [1] input a number  *\n");
		printf("* [0] quit            *\n");
		printf("***********************\n");

		printf("请输入操作选项:");
		scanf("%d", &select);

		if(select == 0)
			break;

		switch(select)
		{
			case 1:
				printf("请输入要转换的十进制数(-1结束):");
				while(scanf("%d", &value), value != -1)
				{
					conversion_8(value);
				}
				break;
			default:
				printf("输入有误，请重新输入.\n");
				break;
		}
	}
}







