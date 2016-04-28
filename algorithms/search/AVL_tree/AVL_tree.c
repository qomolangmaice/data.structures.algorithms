/*
 *  File Name: AVL_tree.c
 *  Description: Balanced Binary Tree 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.26 20:48:23
 */
#include "AVL_tree.h"
#include "link_stack/link_stack.h"
#include "link_stack/link_stack.c"

void init_AVL_tree(AVL_tree *avl)
{
	avl->root = NULL;
}

AVL_node* _malloc_node(elem_type value)
{
	AVL_node *p = (AVL_node*)malloc(sizeof(AVL_node));
	assert(p != NULL);
	p->data = value;
	p->left_child = p->right_child = NULL;
	p->bf = 0;
	return p;
}

boolean insert_AVL_tree(AVL_tree *avl, elem_type value)
{
	return insert_AVL_tree_(&(avl->root), value);
}

boolean insert_AVL_tree_(AVL_node **t, elem_type value)
{
	AVL_node *p = *t;
	AVL_node *parent = NULL;

	link_stack stack;
	init_stack(&stack);

	while(p != NULL)
	{
		if(value == p->data)
			return FALSE;
		parent = p;
		push(&stack, parent);

		if(value < p->data)
			p = p->left_child;
		else
			p = p->right_child;
	}
	p = _malloc_node(value);

	if(parent == NULL)
	{
		*t = p;
		return TRUE;
	}

	if(value < parent->data)
		parent ->left_child = p;
	else
		parent->right_child = p;

	/* 调整bf */
	while(!stack_is_empty(&stack))
	{
		parent = get_stack_top(&stack);
		pop(&stack);
		if(parent->left_child == p)
			parent->bf--;
		else
			parent->bf++;
		if(parent->bf == 0)
			break;
		if(parent->bf == 1 || parent->bf == -1)
			p = parent;
		else
		{
			/* 旋转化的平衡调整 */
			int flag = (parent->bf < 0) ? -1 : 1;
			if(p->bf == flag) 	/* 单旋转 */
			{
				if(flag == -1) 	/* 左高右低,左旋转 */
					rotate_right(&parent);
				else 	 	 	/* 左低右高,右旋转 */
					rotate_left(&parent);
			}
			//else  	/* 双旋转 */
			//{
			//	if(flag == 1)
			//		rotate_right_left(&parent); 	 	/* 双旋转，先右旋转后左旋转 */
			//	else
			//		rotate_left_right(&parent); 	 	/* 双旋转, 先左旋转后右旋转 */
			//}
		} /* else */
	} /* while */

	if(stack_is_empty(&stack))
		*t = parent;
	else
	{
		AVL_node *q = get_stack_top(&stack);
		if(q->data > parent->data)
			q->left_child = parent;
		else
			q->right_child = parent;
	}

	return TRUE;
}

void rotate_right(AVL_node **ptr)
{
	AVL_node *sub_right = *ptr;
	*ptr = sub_right->left_child;
	sub_right->left_child = (*ptr)->right_child;
	(*ptr)->right_child = sub_right;
	(*ptr)->bf = sub_right->bf = 0;
}
void rotate_left(AVL_node **ptr)
{
	AVL_node *sub_left = *ptr;
	*ptr = sub_left->right_child;
	sub_left->right_child = (*ptr)->left_child;
	(*ptr)->left_child = sub_left;
	(*ptr)->bf = sub_left->bf = 0;
}
//void rotate_left_right(AVL_node **ptr)
//void rotate_right_left(AVL_node **ptr)












