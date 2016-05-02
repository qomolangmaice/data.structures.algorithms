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
	/* seq_list是一种数组指针类型，list是一个数组指针变量 */
 	//seq_list list = {49, 38, 65, 97, 76, 13, 27, 49};	 	/* 直接插入排序测试 */
 	seq_list list = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  折半插入排序测试 */

	//straight_insert_sort(&list, 8);
	//for(int i=0; i<8; ++i)
	//{
	//	printf("%d ", list[i]);
	//}

 	binary_insert_sort(&list, 9);
	for(int i=1; i<9; ++i)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}
