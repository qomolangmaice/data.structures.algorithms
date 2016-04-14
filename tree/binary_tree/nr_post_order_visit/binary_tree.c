/*
 *  File Name: binary_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:11
 */
#include "seq_stack/seq_stack.h"
#include "seq_stack/seq_stack.c"

status init_bin_tree(bin_tree *bt, elem_type ref)
{
	bt->root = NULL;
	bt->refvalue = ref;
	return OK;
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

status nr_post_order_visit(bin_tree *bt)
{
	nr_post_order_visit_(bt->root);
	return OK;
}

status nr_post_order_visit_(bin_tree_node *t)
{
	if(t != NULL)
	{
		seq_stack st;
		init_stack(&st);
		stack_node sn;
		bin_tree_node *p;
		do{
			while(t != NULL)
			{
				sn.ptr = t;
				sn.tag = L;
				push(&st, sn);
				t = t->left_child;
			}

			int flag = TRUE;
			while(flag && !stack_is_empty(&st))
			{
				get_top(&st, &sn);
				pop(&st);
				p = sn.ptr;
				switch(sn.tag)
				{
					case L:
						sn.tag = R;
						push(&st, sn);
						flag = FALSE;
						t = p->right_child;
						break;
					case R:
						printf("%c ", p->data);
						break;
				}
			}
		}while(!stack_is_empty(&st));
	}
}


