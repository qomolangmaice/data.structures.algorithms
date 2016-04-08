/*
 *  File Name: binary_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.08 21:37:11
 */

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
















