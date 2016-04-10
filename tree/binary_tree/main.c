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
	//printf("Please input binary tree original data: \n");
	//create_bin_tree_A(&mytree);

	//printf("Paint binary tree in tree shape: \n");
	//paint_tree(&mytree);
	
	//create_bin_tree_B(&mytree);
	//create_bin_tree_C(&mytree);
	
	const char *str = "ABC##DE##F##G#H##";
	printf("Input original tree data: %s\n", str);

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

	printf("Level order visit binary tree: ");
	level_order_visit(&mytree);
	printf("\n");

 	printf("The binary tree counts is: %d\n", bin_tree_count(&mytree));
}
