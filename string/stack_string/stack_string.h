/*
 *  File Name: stack_string.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.03.29 20:10:50
 */

#ifndef __STACK_STRING__
#define __STACK_STRING__

#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 20
#define u_char unsigned char
#define OK 1
#define ERROR 0

typedef int status;

typedef u_char stack_string[MAXSTRLEN + 1];

status init_string(stack_string s);
status print_string(stack_string s);
status str_assign(stack_string s, char *string);
status str_copy(stack_string s, stack_string t);
status str_empty(stack_string s);
unsigned int str_compare(stack_string s, stack_string t);
int str_length(stack_string s);
status str_concat(stack_string t, stack_string s1, stack_string s2);
status sub_string(stack_string s, stack_string sub, int pos, int len);
status str_insert(stack_string s, int pos, stack_string t);
status str_delete(stack_string s, int pos, int len);
status str_clear(stack_string s);

//status str_index(stack_string s, stack_string t, int pos);
//status str_replace(stack_string s, stack_string t, stack_string v);

#endif
