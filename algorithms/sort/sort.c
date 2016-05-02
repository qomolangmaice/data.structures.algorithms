/*
 *  File Name: sort.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:51
 */

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













