/*
* File Name: main.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.17 19:49:48
*/

#include "static_list.h"
#include "static_list.c"

void main()
{
	static_list slist;

	init_list(slist); 	 	/* mylist is a refrence */

	for(int i=0; i<5; ++i)
		insert(slist, 'A' + i);

	show_list(slist);
}
