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
	/* 平衡二叉树插入 */
	//elem_type array[] = {13, 24, 20, 37, 90, 53}; 	/* ---> 不需要旋转的平衡二叉树测试 */
	//elem_type array[] = {30, 20, 10}; 	/* ---> 平衡二叉树单旋转中右旋转测试-- rotate_right() */
	//elem_type array[] = {30, 20, 40, 10, 25, 5}; 	/* ---> 平衡二叉树单旋转中左旋转测试-- rotate_left()*/
	//elem_type array[] = {10, 20, 30}; 	/* ---> 平衡二叉树单旋转中左旋转测试 */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30, 20}; 	/* ---> 平衡二叉树双旋转中先左旋转后右旋转测试-- rotate_left_right() */
	//elem_type array[] = {30, 20, 50, 10, 40, 70, 60, 80, 65}; /* ---> 平衡二叉树双旋转中先右旋转后左旋转测试-- rotate_right_right() */
	
	/* 平衡二叉树删除 */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30, 48}; 	/* ---> 平衡二叉树删除节点后不需要旋转操作测试 */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30, 43, 48}; 	/* ---> 平衡二叉树删除节点后需要进行单旋转操作(左旋转，右旋转)测试 */
	//elem_type array[] = {30, 20, 60, 10, 50, 70, 40, 65, 80}; /* ---> 平衡二叉树删除节点后需要进行单旋转操作(左旋转，右旋转)测试 */
	//elem_type array[] = {50, 40, 60, 10, 45, 70, 5, 30}; 	/* ---> 平衡二叉树删除节点后需要进行单旋转操作(左旋转)测试 */
	elem_type array[] = {50, 30, 60, 20, 40, 55, 70, 10, 25, 35, 45, 58, 65, 80, 5, 33, 38, 48, 75, 32}; 	/* ---> 平衡二叉树删除节点后需要进行双旋转操作测试 */

	int n_array = sizeof(array) / sizeof(elem_type);

	AVL_tree avl;

	init_AVL_tree(&avl);

	for(int i=0; i<n_array; ++i)
	{
		insert_AVL_tree(&avl, array[i]);
	}

 	//elem_type key = 48; 	/* 平衡二叉树删除后不需要进行旋转操作的测试 */
 	//elem_type key = 70; 	/* 平衡二叉树删除后需要进行单旋转(右旋转)操作的测试 */
 	//elem_type key = 10; 	/* 平衡二叉树删除后需要进行单旋转(左旋转)操作的测试 */
 	//elem_type key = 60;  /* ---> 平衡二叉树删除节点后需要进行双旋转操作(先左旋转，后右旋转)测试 */	
 	elem_type key = 60;  /* ---> 平衡二叉树删除节点后需要进行双旋转操作测试 */	
	delete_AVL_tree(&avl, key);

}
