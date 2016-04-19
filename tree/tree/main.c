/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.19 20:41:22
 */

#include "tree.h"
#include "tree.c"

int main()
{
	char *str = "RAD#E##B#CFG#H#K#####";
	tree mytree;
	init_tree(&mytree, '#');
	create_tree(&mytree, str);

	tree_node *r = root(&mytree);
	printf("root node: %c\n", r->data);

	tree_node *p = find(&mytree, 'D');
	printf("The 'D' node is found: %c\n", p->data);

	tree_node *p_parent = parent(&mytree, p);
	printf("The parent of 'D' node is: %c\n", p_parent->data);
}
