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

	//create_bin_tree_B(&mytree);
	//create_bin_tree_C(&mytree);
	
	const char *str = "ABC##DE##F##G#H##";
	printf("Input original tree data: %s\n", str);

	create_bin_tree_D(&mytree, str);

	printf("Paint binary tree in tree shape: \n");
	paint_tree(&mytree);

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

 	printf("The counts of the binary tree is: %d\n", bin_tree_count(&mytree));
 	printf("The height of the binary tree is: %d\n", bin_tree_height(&mytree));
 	bin_tree_node *p = search_node(&mytree, 'B');
	if(p == NULL)
		printf("The node 'B' is not found\n");
	else
	 	printf("search the node 'B' is done\n");
}
