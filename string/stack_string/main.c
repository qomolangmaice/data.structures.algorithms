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
	//stack_string s, sub;
	//init_string(s);

	//str_assign(s, "abcdefg");
	//init_string(sub);
	//str_assign(s, "abcdef");
	//sub_string(s, sub, 2, 4);
	//print_string(sub);
	
	//str_assign(s, "abc");
	//stack_string t;
	//init_string(t);
	//str_assign(t, "xyz");

	//str_insert(s, 1, t);
	//print_string(s);
	
	//str_assign(s, "abcdefg");
	//str_delete(s, 2, 3);
	//print_string(s);
	//str_clear(s);
	//print_string(s);

	//stack_string s;
	//init_string(s);
	//str_assign(s, "ababcababcab");

	//stack_string t;
	//init_string(t);
	//str_assign(t, "abc");
	//int index = str_index(s, t, 0);
	//printf("查找到字符串匹配起始位置为:%d\n", index);
	
	stack_string s;
	init_string(s);
	str_assign(s, "ababcababcab");
	stack_string t;
	init_string(t);
	str_assign(t, "abc");
	stack_string v;
	str_assign(v, "xy");
	str_replace(s, t, v);
	print_string(s);
}








