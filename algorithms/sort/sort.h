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

typedef elem_type array[MAXSIZE];

/* 直接插入排序 */
void straight_insert_sort(array *a, int n);
