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
	//heap_string s;
	//init_string(&s);
	//str_assign(&s, "abcd");
	//heap_string t;
	//init_string(&t);
	//str_copy(&t, &s);
	//print_string(&s);
	//print_string(&t);
	

	//heap_string s;
	//init_string(&s);
	//str_assign(&s, "xyz");
	//heap_string t;
	//init_string(&t);
	//str_assign(&t, "xyz");
 	//int res = str_compare(&s, &t);
	
	
	//heap_string s1; 
	//init_string(&s1);
	//str_assign(&s1, "abc");
	//heap_string s2;
	//init_string(&s2);
	//str_assign(&s2, "xyz");
	//heap_string s; 
	//init_string(&s);
	//str_concat(&s, &s1, &s2);
	//print_string(&s);
	

   	//heap_string s;	
	//init_string(&s);
	//str_assign(&s, "abcdefg");
	//heap_string sub;
	//init_string(&sub);
	//sub_string(&s, &sub, 2, 3);
	//print_string(&sub);
   		
	//heap_string s;
	//init_string(&s);
	//str_assign(&s, "abcdef");
	//heap_string t;
	//init_string(&t);
	//str_assign(&t, "xyz");
	//str_insert(&s, 2, &t);
	//print_string(&s);
	

	heap_string s;
	init_string(&s);
	str_assign(&s, "abcdef");
	str_delete(&s, 2, 3);
	print_string(&s);
}







