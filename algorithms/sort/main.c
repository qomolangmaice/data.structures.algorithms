/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:57
 */
#include "sort.c"

#define USE_ZERO_SPACE

void main()
{
	/* seq_list是一种数组指针类型，list是一个数组指针变量 */
 	//seq_list list = {49, 38, 65, 97, 76, 13, 27, 49};	 	/* 直接插入排序测试 */
#ifdef USE_ZERO_SPACE 
 	seq_list list = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  折半插入排序测试 */
#else
 	seq_list list = {49, 38, 65, 97, 76, 13, 27, 49};	/*  折半插入排序测试 */
#endif

	//printf("直接插入排序:\n");
	//straight_insert_sort(&list, 8);
	
	//printf("折半插入排序:\n");
 	//binary_insert_sort(&list, 9);
	
	//printf("２路插入排序:\n");
	//two_way_insert_sort(&list, 8);

	
 	//seq_list list_a = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  表插入排序测试 */
	//table tb;
	//tb[0].data = MAXVALUE;
	//tb[0].link = 0;
	//for(int i=1; i<9; ++i)
	//{
	//	tb[i].data = list_a[i];
	//	tb[i].link = 0;
	//}

	//printf("表插入排序:\n");
	//table_insert_sort(&tb, 9);

	//for(int i=0; i<9; ++i)
	//{
	//	printf("%d ", tb[i].data);
	//}
	//printf("\n");
	//for(int i=0; i<9; ++i)
	//{
	//	printf("%2d ", tb[i].link);
	//}
	//printf("\n");
	

 	int dlta[] = {5, 3, 2, 1};	 /* 增量序列 */
	int n_dlta = sizeof(dlta) / sizeof(int);
	printf("希尔排序:\n");
	shell_sort(&list, 9, dlta, n_dlta);
	
#ifdef USE_ZERO_SPACE
	for(int i=1; i<9; ++i)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
#else
	for(int i=0; i<8; ++i)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
#endif

}











