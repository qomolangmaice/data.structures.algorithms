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

/* 冒泡排序 */
void bubble_sort(seq_list *list, int n)
{
	for(int i=0; i<n-1; ++i)
	{
		for(int j=0; j<n-i-1; ++j)
		{
			if((*list)[j] > (*list)[j+1])
				swap(&((*list)[j]), &((*list)[j+1]));
		}
	}
}


/*********************** 快速排序 *********************/
int partition(seq_list *list, int low, int high) 	/* 求枢轴关键字,来区分排序低区和高区 */
{
	elem_type pivot_key = (*list)[low];
	while(low < high)
	{
		while(low < high && (*list)[high] >= pivot_key)
			high--;
		(*list)[low] = (*list)[high];

		while(low < high && (*list)[low] < pivot_key)
			low++;
		(*list)[high] = (*list)[low];
	}
	(*list)[low] = pivot_key;
	return low;
}

void quick_sort(seq_list *list, int low, int high)
{
	if(low < high)
	{
		/* 取枢轴位置 -- 即排序低区和高区的划分点*/
		int pivot_location = partition(list, low, high);
		quick_sort(list, low, pivot_location - 1);
		quick_sort(list, pivot_location + 1, high);
	}
}
/*********************** 快速排序 *********************/


/********************* 简单选择排序 *******************/
int select_min_key(seq_list *list, int k, int n)
{
	elem_type min_value = (*list)[k];
	int pos = k;

	for(int i=k+1; i<n; ++i)
	{
		if((*list)[i] < min_value)
		{
			min_value = (*list)[i];
			pos = i;
		}
	}
	return pos;
}
void simple_select_sort(seq_list *list, int n)
{
	for(int i=0; i<n-1; ++i)
	{
		int j = select_min_key(list, i, n);
		if(j != i)
		{
			swap(&((*list)[j]), &((*list)[i]));
		}
	}
}
/********************* 简单选择排序 *******************/

/********************* 树形选择排序 *******************/
elem_type get_value(elem_type value[], int size, int current_pos)
{
	if(current_pos >= size)
		return MAXVALUE;
	elem_type val;
	if(current_pos < size / 2)
	{
		val = value[value[current_pos]];
	}
	else
	{
		val = value[current_pos];
	}
	return val;
}
void left_play_right(elem_type value[], int size, int current_pos)
{
	int left, right;
	int left_value, right_value;
	while(current_pos >= 0 )
	{
		left = 2 * current_pos + 1;
		right = 2 * current_pos + 2;
		left_value = get_value(value, size, left);
		right_value = get_value(value, size, right);
		if(left_value <= right_value)
		{
			if(left < size / 2)
				value[current_pos] = value[left];
			else
				value[current_pos] = left;
		}
		else
		{
			if(right < size / 2)
				value[current_pos] = value[right];
			else
				value[current_pos] = right;
		}
		--current_pos;
	}
}
void select(elem_type value[], int size, int current_pos)
{
	int i = current_pos; 	/* parent */
	int j = 2 * current_pos + 1; 	/* leftchild */
	elem_type left_value, right_value;
	int flag = -1;
	while(flag && i >= 0)
	{
		left_value = get_value(value, size, j);
		right_value = get_value(value, size, j+1);
		if(left_value <= right_value)
		{
			if(j < size / 2)
				value[i] = value[j];
			else
				value[i] = j;
		}
		else
		{
			if(j + 1 < size / 2)
				value[i] = value[j + 1];
			else
				value[i] = j + 1;
		}
		if(i == 0)
			flag++;
		i = (i - 1) / 2;
		j = 2 * i + 1;
	}
}
void tree_select_sort(seq_list *list, int n)
{
 	int size = 2 * n - 1;
	/* 开辟一个value数组空间 */
	elem_type *value = (elem_type*)malloc(sizeof(elem_type) * size);
	assert(value != NULL);

	int start_index = size / 2;
	int i=0;
	for(i=0; i<n; ++i)
	{
		value[start_index++] = (*list)[i];
	}
	int current_pos = size / 2 - 1;
	left_play_right(value, size, current_pos);
	i = 0;
	(*list)[i] = value[value[0]];

	value[value[0]] = MAXVALUE;
	for(int i=1; i<n; ++i)
	{
		current_pos = (value[0] - 1) / 2;
		select(value, size, current_pos);
		(*list)[i] = value[value[0]];
		value[value[0]] = MAXVALUE;
	}
	free(value);
	value = NULL;
}
/********************* 树形选择排序 *******************/

/*********************** 堆排序 ***********************/
void sift_down(elem_type heap[], int n, int current_pos)
{
	int i = current_pos;
	int j = 2 * i + 1;
	while(j < n)
	{
		if(j < n - 1 && heap[j] > heap[j + 1])
			j++;
		if(heap[i] <= heap[j])
			break;
		else
		{
			swap(&(heap[i]), &(heap[j]));
			i = j;
			j = 2 * i + 1;
		}
	}
}

elem_type remove_min_key(elem_type heap[], int n)
{
	elem_type key = heap[0];
	heap[0] = heap[n];
	sift_down(heap, n, 0);
	return key;
}
void heap_sort(seq_list *list, int n)
{
	elem_type *heap = (elem_type *)malloc(sizeof(elem_type) * n);
	assert(heap != NULL);
	for(int i=0; i<n; ++i)
	{
		heap[i] = (*list)[i];
	}

	int current_pos = n / 2 - 1;
	while(current_pos >= 0)
	{
		sift_down(heap, n, current_pos);
		current_pos--;
	}
	for(int i=0; i<n; ++i)
	{
		(*list)[i] = remove_min_key(heap, n-i-1);
	}
	free(heap);
	heap = NULL;
}
/*********************** 堆排序 ***********************/

/********************** 归并排序 **********************/
void merge(seq_list *list, seq_list *tmp_list, int left, int mid, int right) 
{
	for(int i=left; i<=right; ++i)
	{
		(*tmp_list)[i] = (*list)[i];
	}
	int s1 = left; 
	int s2 = mid + 1;
	int k = left;
	while(s1 <= mid && s2 <= right)
	{
		if((*tmp_list)[s1] <= (*tmp_list)[s2])
			(*list)[k++] = (*tmp_list)[s1++];
		else
			(*list)[k++] = (*tmp_list)[s2++];
	}
	while(s1 <= mid)
	{
		(*list)[k++] = (*tmp_list)[s1++];
	}
	while(s2 <= right)
	{
		(*list)[k++] = (*tmp_list)[s2++];
	}
}
void merge_sort(seq_list *list, seq_list *tmp_list, int left, int right)
{
	if(left >= right)
		return;
	int mid = (left + right) / 2;
	merge_sort(list, tmp_list, left, mid);
	merge_sort(list, tmp_list, mid + 1, right);
	merge(list, tmp_list, left, mid, right);
}
/********************** 归并排序 **********************/














