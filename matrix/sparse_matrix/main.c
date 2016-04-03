/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.03 16:37:26
 */

#include "sparse_matrix.h"
#include "sparse_matrix.c"

void main()
{
	sparse_matrix sm;
	memset(&sm, 0, sizeof(sm));
	create_matrix(&sm);
	print_matrix(&sm);
}
