/*
 *  File Name: sort.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:51
 */
#include "sort.h"

void swap(elem_type *a, elem_type *b)
{
	elem_type tmp = *a;
	*a = *b;
	*b = tmp;
}

/* 直接插入排序 -- 当待排序数组中数据元素数量n很小时,宜采用直接插入排序方法进行排序 */
/* seq_list是一种数组指针类型 */
void straight_insert_sort(seq_list *list, int n)
{
 	for(int i=1; i<n; ++i)
	{
		if((*list)[i] < (*list)[i-1])
		{	
			swap(&((*list)[i]), &((*list)[i-1]));
			for(int j=i-1; j>0 && (*list)[j] < (*list)[j-1]; --j)
			{
			 	swap(&((*list)[j]), &((*list)[j-1]));
			}
		}
	}
}

/* 折半插入排序 -- 当插入排序在一个有序表中进行查找和插入时，宜采用折半插入排序进行排序 */
void binary_insert_sort(seq_list *list, int n)
{
 	for(int i=2; i<n; ++i)
	{
		/* (*list)[0] 仅作为临时变量, 将(*list)[i]暂存到(*list)[0] */
		(*list)[0] = (*list)[i];
		int low = 1;
		int high = i - 1;
		while(low <= high) 	/* 在low ~ high下标之间折半查找有序插入的位置 */
		{
			int mid = (low + high) / 2; 	 	/* 折半 */
			if((*list)[0] >= (*list)[mid]) 	 		
				low = mid + 1; 	 	 	 	 	/* 插入区在低半区 */
			else
				high = mid - 1; 	 	 	 	/* 插入区在高半区 */
		}

		for(int j = i; j > high + 1; --j)
		{
			(*list)[j] = (*list)[j - 1]; 	 	/* 将插入点后的数据元素依次向后移动一个位置 */
		}
		(*list)[high + 1] = (*list)[0]; 	 	/* 插入 */
	}
}

void two_way_insert_sort(seq_list *list, int n)
{
	seq_list temp_list; 
	temp_list[0] = (*list)[0];
	int head, tail;
	head = tail = 0;

	for(int i=1; i<n; ++i)
	{
		if((*list)[i] < temp_list[head])
		{
			head = (head - 1 + n) % n;
			temp_list[head] = (*list)[i];
		}
		else if((*list)[i] > temp_list[tail])
		{
			tail++;
			temp_list[tail] = (*list)[i];
		}
		else
		{
			tail++;
			temp_list[tail] = temp_list[tail - 1];
			int j;
			for(j=tail-1; (*list)[i] < temp_list[(j-1+n)%n]; j=(j-1+n)%n)
			{
				temp_list[j] = temp_list[(j-1+n)%n];
			}
			temp_list[j] = (*list)[i];
		}
	}

	for(int i=0; i<n; ++i)
	{
		(*list)[i] = temp_list[head];
		head = (head + 1) % n;
	}
}

/* 表插入排序 */
/* 首先将静态链表中数组下标为"1"的分量(节点)按记录关键字和表头结点构成一个循环链表，
 * 然后依次将下标为"2"至"n"的分量(结点)按记录关键字非递减有序插入到循环链表中
 */
void table_insert_sort(table *tb, int n)
{
	(*tb)[0].link = 1;
	int p, p_prior;
	for(int i=2; i<n; ++i)
	{
		p = (*tb)[0].link;
		p_prior = 0;
		while(p != 0 && (*tb)[p].data <= (*tb)[i].data)
		{
			p_prior = p;
			p = (*tb)[p].link;
		}
		(*tb)[i].link = (*tb)[p_prior].link;
		(*tb)[p_prior].link = i;
	}
}

/* 希尔排序 */
/* 先将整个待排记录序列分割成为若干子序列分别进行直接插入排序，
 * 待整个序列中的记录“基本有序"时，再对全体记录进行一次直接插入排序
 */
void shell_sort_(seq_list *list, int n, int dk) /* 希尔排序中的一趟排序，dk为当前增量 */	
{
	int i=0;
	int j=0;
	for(i=dk+1; i<n; ++i)
	{
		if((*list)[i] < (*list)[i-dk]) 	/* 分别向每组的有序区插入 */
		{
			(*list)[0] = (*list)[i]; 	/* (*list)[0]只是暂存单元，不是哨兵 */
			for(j=i-dk; j>0 && (*list)[0] < (*list)[j]; j-=dk) 	/* 比较与记录后移同时进行 */
				(*list)[j+dk] = (*list)[j];
			(*list)[j+dk] = (*list)[0]; 	/* 插入数据 */
		}
	}
}
void shell_sort(seq_list *list, int n, int dlta[], int t) 	/* t为排序趟数 */
{
	for(int k=0; k<t; ++k)
	{
		shell_sort_(list, n, dlta[k]);
	}
}










