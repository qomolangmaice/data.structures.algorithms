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

	/* ABC#DE##F##G#H# */
	create_bin_tree_A(&mytree);
	create_bin_tree_B(&mytree);
	create_bin_tree_C(&mytree);
}
