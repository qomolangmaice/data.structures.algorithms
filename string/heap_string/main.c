/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.03.31 21:07:12
 */

#include "heap_string.h"
#include "heap_string.c"

void main()
{
	heap_string s;
	init_string(&s);

	str_assign(&s, "abcd");
	print_string(&s);
}

