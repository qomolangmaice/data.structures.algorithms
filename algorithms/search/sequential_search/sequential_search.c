/*
 *  File Name: sequential_search.c
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
			printf("Found key: %d\n", key);
			return;
		}
	}
 	printf("Opps:(, The key has not found yet.\n");
}

