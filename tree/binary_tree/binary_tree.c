/*
 *  File Name: binary_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:11
 */
#include "link_queue/link_queue.h"
#include "link_queue/link_queue.c"
#include "seq_stack/seq_stack.h"
#include "seq_stack/seq_stack.c"

status init_bin_tree(bin_tree *bt, elem_type ref)
{
	bt->root = NULL;
	bt->refvalue = ref;
	return OK;
}

status create_bin_tree_A(bin_tree *bt)
{
	create_bin_tree_a(bt, &(bt->root));
	return OK;
}

status create_bin_tree_a(bin_tree *bt, bin_tree_node **t)
{
	elem_type item;
	scanf("%c", &item);

	if(item == bt->refvalue)
		(*t) = NULL;
	else
	{
		(*t) = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = item;
		create_bin_tree_a(bt, &((*t)->left_child));
		create_bin_tree_a(bt, &((*t)->right_child));
	}
	return OK;
}

status create_bin_tree_B(bin_tree *bt)
{
 	create_bin_tree_b(bt, &(bt->root));
	return OK;
}

status create_bin_tree_b(bin_tree *bt, bin_tree_node **t)
{
	elem_type item;
	scanf("%c", &item);
	if(item == bt->refvalue)
		*t = NULL;
	else
	{
		*t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = item;
		create_bin_tree_b(bt, &((*t)->left_child));
		create_bin_tree_b(bt, &((*t)->right_child));
	}
	return OK;
}

status create_bin_tree_C(bin_tree *bt)
{
	bt->root = create_bin_tree_C_(bt);
	return OK;
}

bin_tree_node* create_bin_tree_C_(bin_tree *bt)
{
	elem_type item;
	scanf("%c", &item);
	if(item == bt->refvalue)
		return NULL;
	else
	{
		bin_tree_node *t = (bin_tree_node *)malloc(sizeof(bin_tree_node));
		assert(t != NULL);
		t->data = item;
		t->left_child = create_bin_tree_C_(bt);
		t->right_child = create_bin_tree_C_(bt);
		return t;
	}
}

status create_bin_tree_D(bin_tree *bt, char *str)
{
	create_bin_tree_d(bt, &(bt->root), &str);
	return OK;
}

status create_bin_tree_d(bin_tree *bt, bin_tree_node **t, char **str)
{
	if(**str == bt->refvalue)
		t = NULL;
	else
	{
		*t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = **str;
		create_bin_tree_d(bt, &((*t)->left_child), &(++*str)); 
		create_bin_tree_d(bt, &((*t)->right_child), &(++*str));
	}
	return OK;
}

status pre_order_visit(bin_tree *bt)
{
	pre_order_visit_(bt->root);
	return OK;
}

status pre_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		printf("%c ", t->data);
		pre_order_visit_(t->left_child);
		pre_order_visit_(t->right_child);
	}
}

status in_order_visit(bin_tree *bt)
{
	in_order_visit_(bt->root);
	return OK;
}

status in_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		in_order_visit_(t->left_child);
		printf("%c ", t->data);
		in_order_visit_(t->right_child);
	}
	return OK;
}

status post_order_visit(bin_tree *bt)
{
	post_order_visit_(bt->root);
	return OK;
}

status post_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		post_order_visit_(t->left_child);
		post_order_visit_(t->right_child);
		printf("%c ", t->data);
	}
	return OK;
}

status level_order_visit(bin_tree *bt)
{
	level_order_visit_(bt->root);
	return OK;
}

status level_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		bin_tree_node *v;
		link_queue queue;
		init_queue(&queue);
		en_queue(&queue, t);

		while(!queue_is_empty(&queue))
		{
			get_head(&queue, &v);
			de_queue(&queue);
			printf("%c ", v->data);
			if(v->left_child != NULL)
				en_queue(&queue, v->left_child);
			if(v->right_child != NULL)
				en_queue(&queue, v->right_child);
		}
	}
}

status paint_tree(bin_tree *bt)
{
	paint_tree_(bt->root, 0);
	return OK;
}

status paint_tree_(bin_tree_node *t, int nlayer)
{
	if(t != NULL)
	{
		paint_tree_(t->right_child, nlayer + 3);
		for(int i=0; i<nlayer; i++)
			printf("  ");
		printf("%c\n", t->data);
		paint_tree_(t->left_child, nlayer + 3);
	}
}

int bin_tree_count(bin_tree *bt)
{
	return bin_tree_count_(bt->root);
}

int bin_tree_count_(bin_tree_node *t)
{
 	if(t == NULL)
		return 0;
	else
		return bin_tree_count_(t->left_child) + bin_tree_count_(t->right_child) + 1;
}

int bin_tree_height(bin_tree *bt)
{
	return bin_tree_height_(bt->root);
}

int bin_tree_height_(bin_tree_node *t)
{
	if(t == NULL)
		return 0;
	else
	{
		int left_height = bin_tree_height_(t->left_child); 
		int right_height = bin_tree_height_(t->right_child);
		return (left_height > right_height ? left_height : right_height) + 1;
	}
}

bin_tree_node* search_node(bin_tree *bt, elem_type key)
{
 	return search_node_(bt->root, key);
}

bin_tree_node* search_node_(bin_tree_node *t, elem_type key)
{
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;

	/* search the node in the left_child tree */
	bin_tree_node *p = search_node_(t->left_child, key);
	if(p != NULL)
		return p;

	/* 
	 * If it can't find the node in the lef_child tree, 
	 * then search the node in the right_child tree 
	 */
	return search_node_(t->right_child, key);
}

bin_tree_node* search_parent(bin_tree *bt, bin_tree_node *p)
{
	return search_parent_(bt->root, p);
}

bin_tree_node* search_parent_(bin_tree_node *t, bin_tree_node *p)
{
	if(t == NULL || p == NULL)
		return NULL;

	/* the root node is the parent node */
 	if(t->left_child == p || t->right_child == p)
		return t;

	/* search the parent node in the left_child tree */
	bin_tree_node *q = search_parent_(t->left_child, p);
	if(q != NULL)
		return q;
	/* 
	 * If it can't find the parent node in the lef_child tree, 
	 * then search the parent node in the right_child tree 
	 */
	return search_parent_(t->right_child, p);
}

bin_tree_node* search_left_child(bin_tree_node *p)
{
	if(p != NULL)
		return p->left_child;
	return NULL;
}

bin_tree_node* search_right_child(bin_tree_node *p)
{
	if(p != NULL)
		return p->right_child;
	return NULL;
}

status bin_tree_empty(bin_tree *bt)
{
 	return bt->root == NULL;
}

status copy_bin_tree(bin_tree *bt1, bin_tree *bt2)
{
	copy_bin_tree_(&(bt1->root), &(bt2->root));
	return OK;
}

status copy_bin_tree_(bin_tree_node **t1, bin_tree_node **t2)
{
	if((*t2) == NULL)
		*t1 = NULL;
	else
	{
 	 	(*t1) = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t1) != NULL);
		(*t1)->data = (*t2)->data;
		copy_bin_tree_(&((*t1)->left_child), &((*t2)->left_child));
		copy_bin_tree_(&((*t1)->right_child), &((*t2)->right_child));
	}
}

status bin_tree_clear(bin_tree *bt)
{
	bin_tree_clear_(&(bt->root));
}

status bin_tree_clear_(bin_tree_node **t)
{
	if((*t) != NULL)
	{
		bin_tree_clear_(&((*t)->left_child));
		bin_tree_clear_(&((*t)->right_child));
		free((*t));
		(*t) = NULL;
	}
}

/* None recursion visit binary tree */
status nr_pre_order_visit(bin_tree *bt)
{
	nr_pre_order_visit_(bt->root);
	return OK;
}

status nr_pre_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		seq_stack st;
		init_stack(&st);

		bin_tree_node *p;
		push(&st, t);
		while(!stack_is_empty(&st))
		{
			get_top(&st, &p);
			pop(&st);
			printf("%c ", p->data);
			if(p->right_child != NULL)
				push(&st, p->right_child);
			if(p->left_child != NULL)
				push(&st, p->left_child);
		}
	}
}

status nr_in_order_visit(bin_tree *bt)
{
	nr_in_order_visit_(bt->root);
	return OK;
}

status nr_in_order_visit_(bin_tree_node *t)
{
 	if(t != NULL)
	{
		seq_stack st;
		init_stack(&st);

	  	bin_tree_node *p;	
		push(&st, t);
		while(!stack_is_empty(&st))
		{
			while(t != NULL && t->left_child != NULL)
			{
				push(&st, t->left_child);
				t = t->left_child;
			}

			get_top(&st, &p);
			pop(&st);
			printf("%c ", p->data);

			if(p->right_child != NULL)
			{
				t = p->right_child;
				if(t != NULL)
					push(&st, t);
			}
		}
	}
}

/* 根据二叉树的先序遍历字符串数据(VLR)和中序遍历字符串数据(LVR)恢复创建二叉树 */
status create_bin_tree_E(bin_tree *bt, char *VLR, char *LVR, int n)
{
	create_bin_tree_e(&(bt->root), VLR, LVR, n);
}

status create_bin_tree_e(bin_tree_node **t, char *VLR, char *LVR, int n)
{
	if(n == 0)
		*t = NULL;
	else
	{
		int k = 0;
		/* 在中序序列LVR中找到先序序列VLR中的根节点数据 */
		while(VLR[0] != LVR[k])
			k++;

		*t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = LVR[k];

		create_bin_tree_e(&((*t)->left_child), VLR+1, LVR, k);
		create_bin_tree_e(&((*t)->right_child), VLR+k+1, LVR+k+1, n-k-1);
	}
}

/* 根据二叉树的后序遍历字符串数据(VLR)和中序遍历字符串数据(LVR)恢复创建二叉树 */
status create_bin_tree_F(bin_tree *bt, char *LVR, char *LRV, int n)
{
	create_bin_tree_f(&(bt->root), LVR, LRV, n);
}

status create_bin_tree_f(bin_tree_node **t, char *LVR, char *LRV, int n)
{
 	if(n == 0)
		*t = NULL;
	else
	{
		int k = 0;

		/* 在中序序列LVR中找到后序序列LRV中的根节点数据 */
		while(LRV[n-1] != LVR[k])
			k++;

		*t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = LVR[k];

		create_bin_tree_f(&((*t)->right_child), LVR+k+1, LRV+k, n-k-1);
		create_bin_tree_f(&((*t)->left_child), LVR, LRV, k);
	}
}








