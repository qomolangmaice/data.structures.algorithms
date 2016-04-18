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
	bin_tree_node *pre = NULL;
	create_in_thread_(&(bt->root), &pre);
}

/* 创建中序线索化二叉树 */
void create_in_thread_(bin_tree_node **t, bin_tree_node **pre)
{
	if((*t) == NULL)
		return;
	create_in_thread_(&((*t)->left_child), pre);
	if((*t)->left_child == NULL)
	{
		/* 找到中序线索化起始节点,即左子树为空，于是将该节点的左标记修改为线索 */
		(*t)->ltag = THREAD;

		/* 找到中序线索化起始节点后将该节点的左子树前驱赋空 */
		(*t)->left_child = *pre;
	}
	if((*pre) != NULL && (*pre)->left_child == NULL)
	{
		(*pre)->rtag = THREAD;
		(*pre)->right_child = *t;
	}
	*pre = *t;
	create_in_thread_(&(*t)->right_child, pre);
}

bin_tree_node* first_node(bin_tree *bt)
{
	return first_node_(bt->root);
}

bin_tree_node* first_node_(bin_tree_node *t)
{
	if(t == NULL)
		return NULL;
	bin_tree_node *p = t;
 	while(p->ltag == LINK)
		p = p->left_child;
	return p;
}

/*
bin_tree_node* last_node(bin_tree *bt)
{
	return last_node_(bt->root);
}

bin_tree_node* last_node_(bin_tree_node *t)
{
	if(t == NULL)
		return NULL;
	bin_tree_node *p = t;
	while(p->rtag == LINK)
		p = p->right_child;
	return p;
}

bin_tree_node* next_node(bin_tree *bt, bin_tree_node *cur)
{
	return next_node_(bt->root, cur);
}

bin_tree_node* next_node_(bin_tree_node *t, bin_tree_node *cur)
{
	if(t == NULL || cur == NULL)
 	 	return NULL;
	if(t->rtag == THREAD)
		return cur->right_child; 
	return first_node_(cur->right_child);
}

bin_tree_node* prio_node(bin_tree *bt, bin_tree_node *cur)
{
	return prio_node_(bt->root, cur);
}

bin_tree_node* prio_node_(bin_tree_node *t, bin_tree_node *cur)
{
	if(t == NULL || cur == NULL)
		return NULL;
	if(cur->ltag == THREAD)
		return cur->left_child;
	return last_node(cur->left_child);
}

void in_order_visit(bin_tree *bt)
{
	in_order_visit_(bt->root);
}

void in_order_visit_(bin_tree_node *t)
{
	bin_tree_node *p;
	for(p = first_node(t); p!=NULL; p=next_node(t, p))
	{
		printf("%c ", p->data);
	}
	printf("\n");
}

*/







