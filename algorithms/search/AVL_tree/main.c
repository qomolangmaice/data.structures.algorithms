/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.26 20:48:30
 */
#include "AVL_tree.c"

void main()
{
	//elem_type array[] = {13, 24, 20, 37, 90, 53};
	elem_type array[] = {30, 20, 10};
	int n_array = sizeof(array) / sizeof(elem_type);

	AVL_tree avl;

	init_AVL_tree(&avl);

	for(int i=0; i<n_array; ++i)
	{
		insert_AVL_tree(&avl, array[i]);
	}
}
