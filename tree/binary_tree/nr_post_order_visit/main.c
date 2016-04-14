/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:21
 */

#include "binary_tree.h"
#include "binary_tree.c"

int main()
{
	bin_tree mytree;

	init_bin_tree(&mytree, '#');

	const char *str = "ABC##DE##F##G#H##";
	printf("Input original tree data: %s\n", str);

	create_bin_tree_D(&mytree, str);

	printf("Post order visit(none recursion method)binary tree: ");
	nr_post_order_visit(&mytree);
	printf("\n");
}
