/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.16 19:21:47
 */

#include "thread_binary_tree.h"
#include "thread_binary_tree.c"


int main()
{
	char *str = "ABC##DE##F##G#H##";
	bin_tree mytree;

	init_bin_tree(&mytree, '#');
	create_bin_tree(&mytree, str);

	create_in_thread(&mytree);
}
