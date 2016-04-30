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
	//elem_type array[] = {13, 24, 20, 37, 90, 53}; 	/* ---> 不需要旋转的平衡二叉树测试 */
	//elem_type array[] = {30, 20, 10}; 	/* ---> 平衡二叉树单旋转中右旋转测试-- rotate_right() */
	//elem_type array[] = {30, 20, 40, 10, 25, 5}; 	/* ---> 平衡二叉树单旋转中左旋转测试-- rotate_left()*/
	//elem_type array[] = {10, 20, 30}; 	/* ---> 平衡二叉树单旋转中左旋转测试 */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30, 20}; 	/* ---> 平衡二叉树双旋转中先左旋转后右旋转测试-- rotate_left_right() */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30, 20}; 	/* ---> 平衡二叉树双旋转中先左旋转后右旋转测试-- rotate_left_right() */
	elem_type array[] = {30, 20, 50, 10, 40, 70, 60, 80, 65}; 	/* ---> 平衡二叉树双旋转中先左旋转后右旋转测试-- rotate_left_right() */
	int n_array = sizeof(array) / sizeof(elem_type);

	AVL_tree avl;

	init_AVL_tree(&avl);

	for(int i=0; i<n_array; ++i)
	{
		insert_AVL_tree(&avl, array[i]);
	}
}
