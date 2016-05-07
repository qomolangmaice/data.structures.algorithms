/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:57
 */
#include "sort.c"

void visit_list_A(seq_list *list, int n)
{  	/* 无哨兵位 */
	for(int i=0; i<n; ++i)
	{
		printf("%d ", (*list)[i]);
	}
	printf("\n");
}

void visit_list_B(seq_list *list, int n)
{ 	/* list[0]作为哨兵位，是一个辅助位，不打印 */
	for(int i=1; i<n; ++i)
	{
		printf("%d ", (*list)[i]);
	}
	printf("\n");
}


void main()
//int main()
{
	/* seq_list是一种数组指针类型，list是一个数组指针变量 */

 	//seq_list list = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  折半插入排序测试 */

 	seq_list list_a = {49, 38, 65, 97, 76, 13, 27, 49};	/*  直接插入排序测试 */
	printf("直接插入排序:\n");
	straight_insert_sort(&list_a, 8);
	visit_list_A(&list_a, 8);
	
 	seq_list list_b = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  折半插入排序测试 */
	printf("折半插入排序:\n");
 	binary_insert_sort(&list_b, 9);
	visit_list_A(&list_a, 9);
	
 	seq_list list_c = {49, 38, 65, 97, 76, 13, 27, 49};	/*  直接插入排序测试 */
	printf("２路插入排序:\n");
	two_way_insert_sort(&list_c, 8);
	visit_list_A(&list_c, 8);

 	seq_list list_d = {0, 49, 38, 65, 97, 76, 13, 27, 49};	/*  表插入排序测试 */
	table tb;
	tb[0].data = MAXVALUE;
	tb[0].link = 0;
	for(int i=1; i<9; ++i)
	{
		tb[i].data = list_d[i];
		tb[i].link = 0;
	}
	printf("表插入排序:\n");
	table_insert_sort(&tb, 9);
	for(int i=0; i<9; ++i)
	{
		printf("%d ", tb[i].data);
	}
	printf("\n");
	for(int i=0; i<9; ++i)
	{
		printf("%2d ", tb[i].link);
	}
	printf("\n");
	
	/* 希尔排序 */
 	seq_list list_e = {0, 49, 38, 65, 97, 76, 13, 27, 49};	
 	int dlta[] = {5, 3, 2, 1};	 /* 增量序列 */
	int n_dlta = sizeof(dlta) / sizeof(int);
	printf("希尔排序:\n");
	shell_sort(&list_e, 9, dlta, n_dlta);
	visit_list_B(&list_e, 9);
	
	/* 冒泡排序 */
 	seq_list list_f = {0, 49, 38, 65, 97, 76, 13, 27, 49};	
	printf("冒泡排序:\n");
	bubble_sort(&list_f, 9);
	visit_list_B(&list_f, 9);
	
	/* 快速排序 */
 	seq_list list_g = {49, 38, 65, 97, 76, 13, 27, 49};	
	int low = 0;
	int high = 8;
	printf("快速排序:\n");
	quick_sort(&list_g, low, high);
	visit_list_B(&list_g, 9);
	
	/* 简单选择排序 */
 	seq_list list_h = {0, 49, 38, 65, 97, 76, 13, 27, 49};	
	printf("简单选择排序:\n");
	simple_select_sort(&list_h, 9);
	visit_list_B(&list_h, 9);

	/* 树形选择排序 */
 	seq_list list_i = {0, 49, 38, 65, 97, 76, 13, 27, 49};	
	printf("树形选择排序:\n");
	tree_select_sort(&list_i, 9);
	visit_list_B(&list_i, 9);
	
	/* 堆排序 */
 	seq_list list_j = {49, 38, 65, 97, 76, 13, 27, 49};	
	printf("堆排序:\n");
	heap_sort(&list_j, 8);
	visit_list_A(&list_j, 8);
	
	/* 归并排序 */
 	seq_list list_k = {49, 38, 65, 97, 76, 13, 27, 49};	
	printf("归并排序:\n");
	seq_list temp_list;
	merge_sort(&list_k, &temp_list, 0, 8);
	visit_list_B(&list_k, 9);
	
	/* 基数排序 */
	//seq_list list_a = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
	//radix_sort(&list_a, 10);

	//for(int i=0; i<8; ++i)
    //{
    //	printf("%d ", list_a[i]);
    //}
    //printf("\n");
}



