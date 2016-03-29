/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.29 20:00:54
 */

#include "stack_string.h"
#include "stack_string.c"

void main()
{
	stack_string s;
	stack_string t;
	init_string(s);
	init_string(t);

	/*
	char *str = "Hello World.";
	str_assign(s, str);
	print_string(s);
	str_copy(s, t);
	print_string(t);
	*/

	str_assign(s, "abcdefghijk");
	str_assign(t, "ABCDEFGHIJK");

	unsigned int res = str_compare(s, t);
	printf("%d", res);
}
