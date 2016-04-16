/*
 *  File Name: recovery_bin_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.16 12:00:51
 */
#include "binary_tree.h"
#include "binary_tree.c"

int main()
{
 	char *VLR = "ABCDEFGH";
	char *LVR = "CBEDFAGH";
	char *LRV = "CEFDBHGA";
	
	int n = strlen(VLR);

	bin_tree mytree;
	init_bin_tree(&mytree, '#');

	create_bin_tree_E(&mytree, VLR, LVR, n);
	printf("Previous order visit the binary tree(mytree): ");
	pre_order_visit(&mytree);
	printf("\n");
	printf("In order visit the binary tree(mytree): ");
	in_order_visit(&mytree);
	printf("\n");
	paint_tree(&mytree);
 	
	bin_tree another_tree;
	init_bin_tree(&another_tree, '#');
	create_bin_tree_F(&another_tree, LVR, LRV, n);
	printf("Post order visit the binary tree(another_tree): ");
	post_order_visit(&another_tree);
	printf("\n");
	printf("In order visit the binary tree(another_tree): ");
	in_order_visit(&another_tree);
	printf("\n");
	paint_tree(&another_tree);
}
