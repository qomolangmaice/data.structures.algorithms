/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.30 22:58:42
 */

#include "hash_table.h"
#include "hash_table.c"

int main()
{
	hash_table ht;

	init_hash_table(ht);

	elem_type array[] = {19, 14, 32, 1, 68, 20, 84, 27, 55, 11, 10, 79};
	int n_array = sizeof(array) / sizeof(elem_type);

	for(int i=0; i < n_array; ++i)
	{
		insert_hash_table(ht, array[i]);
	}

	elem_type key = 20;
	hash_node *p = search_hash_table(ht, key);
	if(p != NULL)
 		printf("Found the key, hash[index]: %d <---> p: %d\n", ht[hash(key)], p);

	if(delete_hash_table(ht, key))
		printf("Delete the key: %d\n", key);
	show_hash_table(ht);
}
