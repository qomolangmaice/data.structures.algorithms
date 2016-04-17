/*
 *  File Name: thread_binary_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.16 19:21:43
 */

void init_bin_tree(bin_tree *bt, elem_type ref)
{
	bt->root = NULL;
 	bt->refvalue = ref;
}

void create_bin_tree(bin_tree *bt, char *str)
{
	create_bin_tree_(bt, &(bt->root), &str);
}

void create_bin_tree_(bin_tree *bt, bin_tree_node **t, char **str)
{
	if(**str == bt->refvalue)
		*t = NULL;
	else
	{
		*t = (bin_tree_node*)malloc(sizeof(bin_tree_node));
		assert((*t) != NULL);
		(*t)->data = **str;
		(*t)->left_child = (*t)->right_child = NULL;
		(*t)->ltag = (*t)->rtag = LINK;

		create_bin_tree_(bt, &((*t)->left_child), &(++*str));
		create_bin_tree_(bt, &((*t)->right_child), &(++*str));
	}
}


void create_in_thread(bin_tree *bt)
{
	bin_thred_node *pre = NULL;
	create_in_thread_(bt->root, pre);
}

void create_in_thread_(bin_tree_node **t, bin_tree_node **pre)
{
	if(t == NULL)
		return;
	else
	{
	}
}














