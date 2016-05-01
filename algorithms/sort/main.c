/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:57
 */
#include "sort.h"
#include "sort.c"

void main()
{
	/* array是一种数组指针类型，seq_list是一个数组指针变量 */
 	array seq_list = {49, 38, 65, 97, 76, 13, 27, 49};	

	straight_insert_sort(&seq_list, 8);

	for(int i=0; i<8; ++i)
	{
		printf("%d ", seq_list[i]);
	}
	printf("\n");
}
