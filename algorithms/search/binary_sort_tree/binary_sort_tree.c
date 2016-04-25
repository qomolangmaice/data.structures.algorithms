/*
 *  File Name: binary_sort_tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.25 19:33:01
 */

void init_bin_sort_tree(bin_sort_tree *bst)
{
	bst->root = NULL;
}

boolean insert_bin_sort_tree(bin_sort_tree *bst, elem_type value)
{
	return insert_bin_sort_tree_(&(bst->root), value);
}

boolean insert_bin_sort_tree_(bst_node **t, elem_type value)
{
	if(*t == NULL)
	{
		*t = (bst_node*)malloc(sizeof(bst_node));
		assert(*t != NULL);
		(*t)->data = value;
		(*t)->left_child = NULL;
		(*t)->right_child = NULL;
		return TRUE;
	}
	else if(value < (*t)->data)
	{
		insert_bin_sort_tree_(&((*t)->left_child), value);
	}
	else if(value > (*t)->data)
	{
		insert_bin_sort_tree_(&((*t)->right_child), value);
	}
	return FALSE;
}

elem_type get_min_value(bin_sort_tree *bst)
{
	assert(bst != NULL);
	return get_min_value_(bst->root);
}

elem_type get_min_value_(bst_node *t)
{
	while(t->left_child != NULL)
		t = t->left_child;
	return t->data;
}

elem_type get_max_value(bin_sort_tree *bst)
{
	assert(bst != NULL);
	return get_max_value_(bst->root);
}

elem_type get_max_value_(bst_node *t)
{
	while(t->right_child != NULL)
		t = t->right_child;
	return t->data;
}

void sort(bin_sort_tree *bst)
{
	sort_(bst->root);
}

void sort_(bst_node *t)
{
	if(t != NULL)
	{
		sort_(t->left_child);
		printf("%d ", t->data);
		sort_(t->right_child);
	}
}

bst_node* search_bin_sort_tree(bin_sort_tree *bst, elem_type key)
{
	return search_bin_sort_tree_(bst->root, key);
}

bst_node* search_bin_sort_tree_(bst_node *t, elem_type key)
{
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;
	if(key < t->data)
		return search_bin_sort_tree_(t->left_child, key);
	else
		return search_bin_sort_tree_(t->right_child, key);
}

void make_empty_bin_sort_tree(bin_sort_tree *bst)
{
	make_empty_bin_sort_tree_(&(bst->root));
}

void make_empty_bin_sort_tree_(bst_node **t)
{
	if(*t != NULL)
	{
		make_empty_bin_sort_tree_(&((*t)->left_child));
		make_empty_bin_sort_tree_(&((*t)->right_child));
		free(*t);
		*t = NULL;
	}
}

boolean delete_bin_sort_tree(bin_sort_tree *bst, elem_type key)
{
	return delete_bin_sort_tree_(&(bst->root), key);
}

boolean delete_bin_sort_tree_(bst_node **t, elem_type key)
{
	if(*t == NULL)
		return FALSE;
	if(key < (*t)->data)
		delete_bin_sort_tree_(&((*t)->left_child), key);
	else if(key > (*t)->data)
		delete_bin_sort_tree_(&((*t)->right_child), key);
	else
	{
		bst_node *p = NULL;
		
 	 	if((*t)->left_child != NULL && (*t)->right_child != NULL)
		{
			p = (*t)->right_child;
			while(p->left_child != NULL)
				p = p->left_child;
			(*t)->data = p->data;
			delete_bin_sort_tree_(&((*t)->right_child), p->data);
		}
		else
		{
			p = *t;
			if((*t)->left_child == NULL)
				*t = (*t)->right_child;
			else
				*t = (*t)->left_child;
			free(p);
			p = NULL;
		}
		return TRUE;
	}
}

