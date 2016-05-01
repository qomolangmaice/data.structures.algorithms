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

/* 直接插入排序 */
/* array是一种数组指针类型 */
void straight_insert_sort(array *a, int n)
{
 	for(int i=1; i<n; ++i)
	{
		if((*a)[i] < (*a)[i-1])
		{	
			swap(&((*a)[i]), &((*a)[i-1]));
			for(int j=i-1; j>0 && (*a)[j] < (*a)[j-1]; --j)
			{
			 	swap(&((*a)[j]), &((*a)[j-1]));
			}
		}
	}
}
