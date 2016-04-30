/*
 *  File Name: hash_table.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.30 22:58:24
 */
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int elem_type;
#define prime 13 	/* prime 是一个素数，保证被取模数所产生的下标的概率是相等的 */
typedef int boolean;

#define TRUE 1
#define FALSE 0

typedef struct hash_node{
	elem_type data;
	struct hash_node *link;
} hash_node;

typedef hash_node* hash_table[prime];

void init_hash_table(hash_table ht);
int hash(elem_type key);
void insert_hash_table(hash_table ht, elem_type value);
void show_hash_table(hash_table ht);
hash_node* search_hash_table(hash_table ht, elem_type key);
boolean delete_hash_table(hash_table ht, elem_type key);
