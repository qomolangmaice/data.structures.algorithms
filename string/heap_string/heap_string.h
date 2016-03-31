/*
 *  File Name: heap_string.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.03.31 21:07:06
 */

#ifndef __HEAP_STRING_
#define __HEAP_STRING_

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define OK 1
#define ERROR 0
typedef int status;

typedef struct heap_string{
	char *ch;
	int length;
} heap_string;

status init_string(heap_string *s);
status print_string(heap_string *s);

status str_assign(heap_string *s, char *str);
status str_copy(heap_string *s, heap_string *t);
status str_empty(heap_string *s);
status str_compare(heap_string *s, heap_string *t);
status str_length(heap_string *s);
status str_concat(heap_string *t, heap_string *s1, heap_string *s2);
status sub_string(heap_string *s, heap_string *sub, int pos, int len);
status str_insert(heap_string *s, int pos, heap_string *t);
status str_delete(heap_string *s, int pos, int len);

//status str_index(heap_string *s, heap_string *t, int pos);
//status str_replace(heap_string *s, heap_string *t, heap_string *v);

#endif


