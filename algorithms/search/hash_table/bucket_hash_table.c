/*
 *  File Name: bucket_hash_table.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 17:58:03
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define PRIME 7
#define NULL_DATA -1
#define BUCKET_NODE_SIZE 3

typedef int elem_type;

/* 桶节点 */
typedef struct bucket_node{
	int data[BUCKET_NODE_SIZE];
	struct bucket_node *next;
} bucket_node;

bucket_node hash_table[PRIME];

void init_bucket_hash_table()
{
	for(int i=0; i<PRIME; ++i)
	{
		for(int j=0; j<BUCKET_NODE_SIZE; ++j)
		{
			hash_table[i].data[j] = NULL_DATA;
		}
		hash_table[i].next = NULL;
	}
}

int hash(elem_type key)
{
	return key % PRIME;
}

int insert_new_element(elem_type key)
{
	int index = hash(key);

	for(int i=0; i<BUCKET_NODE_SIZE; ++i)
	{
		if(hash_table[index].data[i] == NULL_DATA)
		{
			hash_table[index].data[i] = key;
			return 0;
		}
	}

	bucket_node *p = &hash_table[index];
	/* 溢出桶节点,指向下一个溢出桶节点 */
	while(p->next != NULL)
	{
		p = p->next;
		for(int i=0; i<BUCKET_NODE_SIZE; ++i)
		{
			if(p->data[i] == NULL_DATA)
			{
				p->data[i] = key;
				return 0;
			}
		}
	}

	bucket_node *s = (bucket_node*)malloc(sizeof(bucket_node));
	assert(s != NULL);
	for(int i=0; i<BUCKET_NODE_SIZE; ++i)
	{
		s->data[i] = NULL_DATA;
	}
	s->next = NULL;

	s->data[0] = key;
	p->next = s;
	return 0;
}

void main()
{
	init_bucket_hash_table();

	//int array[] = {1, 8, 15, 22, 29, 36, 43};
	int array[] = {15, 14, 21, 87, 96, 293, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356};

	for(int i=0; i<sizeof(array) / sizeof(int); ++i)
	{
		insert_new_element(array[i]);
	}
}
