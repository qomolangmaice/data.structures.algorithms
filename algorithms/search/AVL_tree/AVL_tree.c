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

	/* 调整平衡因子bf */
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
			else  	/* 双旋转 */
			{
				if(flag == 1)
					rotate_right_left(&parent); 	 	/* 双旋转，先右旋转后左旋转 */
				else
					rotate_left_right(&parent); 	 	/* 双旋转, 先左旋转后右旋转 */
			}
			break; 	/* 进行旋转化的平衡调整后，平衡因子已经调整好了，不需要再根据stack栈空不空再重新调整平衡因子 */
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

void rotate_left_right(AVL_node **ptr) 	/* 双旋转，先左旋转后右旋转 */
{
	AVL_node *sub_right = *ptr;
	AVL_node *sub_left = sub_right->left_child;
	*ptr = sub_left->right_child;

	/* 左旋转 */
	sub_left->right_child = (*ptr)->left_child;
	(*ptr)->left_child = sub_left;
	if((*ptr)->bf <= 0)
		sub_left->bf = 0;
	else
		sub_left->bf = -1;

	/* 右旋转 */
	sub_right->left_child = (*ptr)->right_child;
	(*ptr)->right_child = sub_right;
	if((*ptr)->bf == -1)
		sub_right->bf = 1;
	else
		sub_right->bf = 0;
	(*ptr)->bf = 0;
}

void rotate_right_left(AVL_node **ptr) 	/* 双旋转，先右旋转左旋转 */

{
	AVL_node *sub_left = *ptr;
	AVL_node *sub_right = (*ptr)->right_child;
	(*ptr) = sub_right->left_child;

	/* 右旋转 */
	sub_right->left_child = (*ptr)->right_child;
	(*ptr)->right_child = sub_right;
	if((*ptr)->bf >= 0)
		sub_right->bf = 0;
	else
		sub_right->bf = 1;

	/* 左旋转 */
	sub_left->right_child = (*ptr)->left_child;
	(*ptr)->left_child = sub_left;
	if((*ptr)->bf == 1)
		sub_left->bf = -1;
	else
		sub_left->bf = 0;
	(*ptr)->bf = 0;
}

boolean delete_AVL_tree(AVL_tree *avl, elem_type key)
{
	return delete_AVL_tree_(&(avl->root), key);
}

boolean delete_AVL_tree_(AVL_node **t, elem_type key)
{
	AVL_node *grand_parent_ptr = NULL; /* 父节点的父节点 */
	AVL_node *parent = NULL;
	AVL_node *p = *t;
	link_stack stack;
	init_stack(&stack);

	/* 找到要删除的节点 */
	while(p != NULL)
	{
		if(p->data == key)
			break;
		parent = p;
		push(&stack, parent);
		if(key < p->data)
			p = p->left_child;
		else
			p = p->right_child;
	}

	if(p == NULL)
		return FALSE;

	AVL_node *q;
	int child_flag = 0; 	/* left_child = NULL 或者 right_child = NULL */
	if(p->left_child != NULL && p->right_child != NULL)
	{
		parent = p;
		push(&stack, parent);
		q = p->left_child;
		while(q->right_child != NULL)
		{
			parent = p;
			push(&stack, parent);
			q = q->right_child;
		}
		p->data = q->data;
		p = q;
	}

	if(p->left_child != NULL)
		q = p->left_child;
	else
		q = p->right_child;

	if(parent == NULL)
		*t = parent;
	else
	{
		if(parent->left_child == p)
		{
			parent->left_child = q;
			child_flag = 0; 	/* left_child = NULL */
		}
		else
		{
			parent->right_child = q;
			child_flag = 1; 	/* right_child = NULL */
		}

		int link_flag = 0; /* -1: left_child */
		 	 	 	 	   /*  1: right_child */
		 	 	 	 	   /*  0: no link */
		/* 修改平衡因子bf */
		while(!stack_is_empty(&stack))
		{
			parent = get_stack_top(&stack);
			pop(&stack);
			if(parent->right_child == q && child_flag == 1)
				parent->bf--;
			else
				parent->bf++;

			if(!stack_is_empty(&stack))
			{
				grand_parent_ptr = get_stack_top(&stack);
				link_flag = (grand_parent_ptr->left_child == parent) ? -1 : 1;
			}
			else
			{
				link_flag = 0;
			}

			if(parent->bf == -1 || parent->bf == 1)
				break;

			if(parent->bf == 0)
				q = parent;
			else 	/* 删除节点后，若parent平衡因子bf绝对值>2，所以需要进行平衡二叉树旋转 */
			{
				int flag = 0;
				if(parent->bf < 0)
				{
					flag = -1;
					q = parent->left_child;
				}
				else
				{
					flag = 1;
					q = parent->right_child;
				}
				if(q->bf == 0) 	/* 单旋转 */
				{
					if(flag == -1) 	/* 左子树深度比右子树高,平衡二叉树进行右单旋转  */
					{
						rotate_right(&parent);
						parent->bf = 1;
						parent->left_child->bf = -1;
					}
					else 	 	 	/* 右子树深度比左子树高,平衡二叉树进行左单旋转  */
					{
						rotate_left(&parent);
						parent->bf = -1;
						parent->right_child->bf = 1;
					}
					break;
				}

				if(q->bf == flag)
				{
					if(flag == -1) /* 单旋转 */
						rotate_right(&parent);
					else
						rotate_left(&parent);
				}
				else
				{
					if(flag == -1) /* 双旋转 */
						rotate_left_right(&parent);
					else
						rotate_right_left(&parent);
				}

				if(link_flag == 1)
					grand_parent_ptr->right_child = parent;
				else if(link_flag == -1)
					grand_parent_ptr->left_child = parent;
			} /* else */
		} /* while */

		if(stack_is_empty(&stack))
			*t = parent;
	} /* else */ 

	free(p);
	return TRUE;
}


