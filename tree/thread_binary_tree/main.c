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

	//bin_tree_node *p_first_node = first_node(&mytree);
	//if(p_first_node != NULL)
	//	printf("Found the first node in in order thread binary tree.\n");

	//bin_tree_node *p_last_node = last_node(&mytree);
	//if(p_last_node != NULL)
	//	printf("Found the last node in in order thread binary tree.\n");

	//bin_tree_node *p_next_node = next_node(&mytree, );
	//if(p_next_node != NULL)
	//	printf("Found the next node in in order thread binary tree.\n");
	//in_order_visit(&mytree);
}
