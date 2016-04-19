/*
 *  File Name: tree.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.19 20:41:11
 */

void init_tree(tree *tree, elem_type ref)
{
	tree->root = NULL;
	tree->refvalue = ref;
}

void create_tree(tree *tree, char *str)
{
 	create_tree_(tree, &(tree->root), &str);
}

void create_tree_(tree *tree, tree_node **t, char **str)
{
	if(**str == tree->refvalue)
		*t = NULL;
	else
	{
		*t = (tree_node*)malloc(sizeof(tree_node));
		assert(*t != NULL);
		(*t)->data = **str;
		create_tree_(tree, &((*t)->first_child), &(++*str));
		create_tree_(tree, &((*t)->next_sibling), &(++*str));
	}
}

tree_node* root(tree *tree)
{
	return tree->root;
}

tree_node* first_child(tree *tree)
{
	return first_child_(tree->root);
}

tree_node* first_child_(tree_node *t)
{
	if(t == NULL)
		return NULL;
	return t->first_child;
}

tree_node* next_sibling(tree *tree)
{
	return next_sibling_(tree->root);
}

tree_node* next_sibling_(tree_node *t)
{
	if(t == NULL)
		return NULL;
	return t->next_sibling;
}

tree_node* find(tree *tree, elem_type key)
{
	return find_(tree->root, key);
}

tree_node* find_(tree_node *t, elem_type key)
{
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;

	tree_node *p = find_(t->first_child, key);
	if( p != NULL)
		return p;
	return find_(t->next_sibling, key);
}

tree_node* parent(tree *tree, tree_node *p)
{
	return parent_(tree->root, p);
}

tree_node* parent_(tree_node *t, tree_node *p)
{
	if(t == NULL || p == NULL || p == t)
		return NULL;

	tree_node *q = t->first_child;
	tree_node *parent;
	while(q != NULL && q != p)
	{
 	 	parent = parent_(q, p);
		if(parent != NULL)
			return parent;
		q = q->next_sibling;
	}
	if(q != NULL && q == p)
		return t;
	return NULL;
}













