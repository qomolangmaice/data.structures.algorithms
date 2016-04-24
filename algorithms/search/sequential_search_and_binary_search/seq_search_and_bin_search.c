/*
 *  File Name: seq_search_and_bin_search.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.24 19:01:34
 */

void init_seq_table(seq_table *st)
{
	st->base = (elem_type*)malloc(sizeof(elem_type) * SEQTABLE_INIT_SIZE);
	assert(st != NULL);
	st->size = 0;
}

void create_seq_table(seq_table *st)
{		
	if(!st)
		printf("无法创建顺序表.\n");

	for(int i=0; i<5; ++i)
	{
		st->base[i] = i;
		st->size++;
	}
}

void show_seq_table(seq_table *st)
{
	for(int i=0; i<5; ++i)
	{
		printf("%d-->", st->base[i]);
	}
	printf("Nul\n");
}

void sequential_search(seq_table *st, elem_type key)
{
	if(!st)
		printf("无法创建顺序表.\n");

	for(int i=0; i<st->size; ++i)
	{
		if(st->base[i] == key)
		{
			printf("Sequential_search - Found key: %d\n", key);
			return;
		}
	}
 	printf("Opps:(, The key has not found yet.\n");
}

/*
 * 在有序表st中折半查找关键字是否等于key,
 * 若找到，则函数值为该元素在表中的位置，否则为0
 */
int binary_search(seq_table *st, elem_type key)
{
	int low, high, mid;
	low = 1; 	/*置区间初值 */
	high = st->size;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(key == st->base[mid])
		{
			//return mid;
			printf("Binary search - Found key: %d\n", st->base[mid]);
			return mid;
		}
		else if(key < st->base[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

void destroy_seq_table(seq_table *st)
{
 	free(st->base);
	st->size = 0;
}

