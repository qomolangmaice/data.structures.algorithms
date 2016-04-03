/*
 *  File Name: sparse_matrix.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.03 16:36:44
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int elem_type;
typedef int status;

#define MAXSIZE 100

typedef struct triple {
	int i; 	/* row */
	int j; 	/* column */
	elem_type e;
} triple;

typedef struct sparse_matrix{
	triple data[MAXSIZE];
	int mu;  	/* matrix row */
	int nu; 	/* matrix column  */
	int tu; 	/* none zero element count */
} sparse_matrix;

status create_matrix(sparse_matrix *matrix);
status print_matrix(sparse_matrix *matrix);
status copy_matrix(sparse_matrix *m_matrix, sparse_matrix *t_matrix);
status add_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix);
status sub_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix);
status mul_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix);
status transpose_matrix(sparse_matrix *m_matrix, sparse_matrix *t_matrix);








