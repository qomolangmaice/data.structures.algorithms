/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.25 19:33:06
 */
#include "binary_sort_tree.h"
#include "binary_sort_tree.c"

void main()
{
	elem_type arrary[] = {45, 12, 53, 3, 37, 100, 24, 61, 90, 78};
	int n_arrary = sizeof(arrary) / sizeof(int);
	bin_sort_tree bst;

	init_bin_sort_tree(&bst);

	for(int i=0; i<n_arrary; ++i)
	{
		insert_bin_sort_tree(&bst, arrary[i]);
	}

	bst_node *search_node = search_bin_sort_tree(&bst, 61);
	printf("Found %d in array[].\n", search_node->data);

	elem_type min = get_min_value(&bst);
	printf("Get the min value in array[]: %d\n", min);

	elem_type max = get_max_value(&bst);
	printf("Get the max value in array[]: %d\n", max);

	//if(delete_bin_sort_tree(&bst, 3))
	//if(delete_bin_sort_tree(&bst, 37))
	if(delete_bin_sort_tree(&bst, 12))
		printf("Delete node in array[].\n");
	else
		printf("Delete node in array[] is failed.\n");

	sort(&bst);
	printf("\n");
}
