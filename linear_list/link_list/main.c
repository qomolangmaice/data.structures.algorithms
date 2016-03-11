/*
* File Name: main.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:42:40
*/

#include "link_list.h"
#include "link_list.c"

void main()
{
	link_list mylist;

	init_list(&mylist);
	create_list(&mylist);
	show_list(mylist);
}
