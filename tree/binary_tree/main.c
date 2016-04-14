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

	printf("Previous order visit(recursion method) binary tree: ");
	pre_order_visit(&mytree);
	printf("\n");
 	printf("Previous order visit(non recursion method) binary tree: ");
	nr_pre_order_visit(&mytree);
	printf("\n");

	printf("In order visit(recursion method) binary tree:" );
	in_order_visit(&mytree);
	printf("\n");
 	printf("In order visit(non recursion method) binary tree:" );
	nr_in_order_visit(&mytree);
	printf("\n");

	printf("Post order visit(recursion method)binary tree: ");
	post_order_visit(&mytree);
	printf("\n");
 	//printf("Post order visit(none recursion method)binary tree: ");
	//nr_post_order_visit(&mytree);
	//printf("\n");

	printf("Level order visit binary tree: ");
	level_order_visit(&mytree);
	printf("\n");

 	printf("The counts of the binary tree is: %d\n", bin_tree_count(&mytree));
 	printf("The height of the binary tree is: %d\n", bin_tree_height(&mytree));

 	bin_tree_node *p = search_node(&mytree, 'D');
	if(p == NULL)
		printf("The node 'D' is not found\n");
	else
		printf("The node 'D' is found\n");
	bin_tree_node *parent = search_parent(&mytree, p);
	printf("The parent node of 'D' is found: %c\n", parent->data);
	bin_tree_node *left_child = search_left_child(p);
	printf("The left child of 'D' is: %c\n", left_child->data);
	bin_tree_node *right_child = search_right_child(p);
	printf("The right child of 'D' is: %c\n", right_child->data);

 	bin_tree copytree;
	init_bin_tree(&copytree, '#');
	copy_bin_tree(&copytree, &mytree);
	printf("Previous order visit the copy binary tree: ");
	pre_order_visit(&copytree);
	printf("\n");

	bin_tree_clear(&copytree);
 	if(bin_tree_clear(&copytree))
	 	printf("The copy binary tree is not empty.\n");
	else
	 	printf("The copy binary tree is empty.\n");
}
