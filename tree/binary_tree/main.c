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

	/* ABC#DE##F##G#H## */
	//create_bin_tree_A(&mytree);
	//create_bin_tree_B(&mytree);
	//create_bin_tree_C(&mytree);
	
	const char *str = "ABC##DE##F##G#H##";
	create_bin_tree_D(&mytree, str);

	printf("Previous order visit binary tree: ");
	pre_order_visit(&mytree);
	printf("\n");

	printf("In order visit binary tree:" );
	in_order_visit(&mytree);
	printf("\n");

	printf("Post order visit binary tree: ");
	post_order_visit(&mytree);
	printf("\n");
}
