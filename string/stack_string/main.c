/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.29 20:00:54
 */

#include "stack_string.h"
#include "stack_string.c"

//void main()
//{
//	stack_string s;
//	stack_string t;
//	init_string(s);
//	init_string(t);
//
//	/*
//	char *str = "Hello World.";
//	str_assign(s, str);
//	print_string(s);
//	str_copy(s, t);
//	print_string(t);
//	*/
//
//	str_assign(s, "abc");
//	str_assign(t, "xyz");
//	/*
//	unsigned int res = str_compare(s, t);
//	*/
//	stack_string y;
//	str_concat(y, s, t);
//	print_string(y);
//}
//

void main()
{
	stack_string s, sub;
	init_string(s);
	str_assign(s, "abcdef");

	//init_string(sub);
	//str_assign(s, "abcdef");
	//sub_string(s, sub, 2, 4);
	//print_string(sub);
	stack_string t;
	init_string(t);
	str_assign(t, "xyz");

	str_insert(s, 1, t);
	print_string(s);
}










