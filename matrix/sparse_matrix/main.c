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
	sparse_matrix sm, sm1, sm2, sm3;
	memset(&sm, 0, sizeof(sm));
	memset(&sm1, 0, sizeof(sm1));
	memset(&sm2, 0, sizeof(sm2));
	memset(&sm3, 0, sizeof(sm3));
	create_matrix(&sm);
	printf("创建矩阵sm:\n");
	print_matrix(&sm);

	copy_matrix(&sm, &sm1);
	copy_matrix(&sm, &sm2);
	printf("复制矩阵sm1:\n");
	print_matrix(&sm1);

	//printf("复制矩阵sm2:\n");
	//print_matrix(&sm2);

	//add_matrix(&sm1, &sm2, &sm);
	//printf("sm1和sm2矩阵相加后的新矩阵为:\n");
	//print_matrix(&sm);

	//sub_matrix(&sm1, &sm2, &sm);
	//printf("sm1和sm2矩阵相减后的新矩阵为:\n");
	//print_matrix(&sm);

	transpose_matrix(&sm1, &sm3);
	print_matrix(&sm3);
}
