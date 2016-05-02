/*
 *  File Name: sort.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.05.01 22:51:45
 */
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int elem_type;
#define MAXSIZE 20

typedef elem_type seq_list[MAXSIZE];

/**************表插入排序数据结构*******************/
#define MAXVALUE 0x7FFFFFFF
typedef struct sl_node{
	elem_type data;
	int link;
}sl_node;

typedef sl_node table[MAXSIZE];
/**************表插入排序数据结构*******************/

/* 直接插入排序 */
void straight_insert_sort(seq_list *list, int n);

/* 折半插入排序 */
void binary_insert_sort(seq_list *list, int n);

/* 2-路插入排序 */
void two_way_insert_sort(seq_list *list, int n);

/* 表插入排序 */
void table_insert_sort(table *tb, int n);

/* 希尔排序 */
void shell_sort(seq_list *list, int n, int dlta[], int t);
