/*
 *  File Name: binary_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:11
 */
#include "link_queue/link_queue.h"
#include "link_queue/link_queue.c"

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
 	create_bin_tree_b(bt, bt->root);
	return OK;
}

status create_bin_tree_b(bin_tree *bt, bin_tree_node *&t)
{
	elem_type item;
	scanf("%c", &item);
	if(item == bt->refvalue)
		t = NULL;
	else
	{
		t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert(t != NULL);
		t->data = item;
		create_bin_tree_b(bt, t->left_child);
		create_bin_tree_b(bt, t->right_child);
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

status create_bin_tree_D(bin_tree *bt, const char *str)
{
	create_bin_tree_d(bt, bt->root, str);
	return OK;
}

status create_bin_tree_d(bin_tree *bt, bin_tree_node *&t, const char *&str)
{
	if(*str == bt->refvalue)
		t = NULL;
	else
	{
		t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert(t != NULL);
		t->data = *str;
		create_bin_tree_d(bt, t->left_child, ++str);
		create_bin_tree_d(bt, t->right_child, ++str);
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





