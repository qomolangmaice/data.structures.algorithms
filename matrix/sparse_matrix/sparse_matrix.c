/*
 *  File Name: sparse_matrix.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.03 16:37:21
 */

status create_matrix(sparse_matrix *matrix)
{
	FILE *fp = fopen("matrix.txt", "r");
	if(fp == NULL)
		exit(1);

	fscanf(fp, "%d %d", &matrix->mu, &matrix->nu);

	int value;
	int k = 0;
	for(int i=0; i<matrix->mu; ++i)
	{
		for(int j=0; j<matrix->nu; ++j)
		{
			fscanf(fp, "%d", &value);
			if(value != 0)
		 	{	
				matrix->data[k].e = value;
				matrix->data[k].i = i;
				matrix->data[k].j = j;
				k++;
			}
		}
	}
	matrix->tu = k;
	fclose(fp);
	return OK;
}

status print_matrix(sparse_matrix *matrix)
{
	printf("row=%d, col=%d\n", matrix->mu, matrix->nu);
	int row, col;
	int k = 0;
	for(row=0; row<matrix->mu; row++)
	{
		for(col=0; col<matrix->nu; col++)
		{
			if(row == matrix->data[k].i && col == matrix->data[k].j)
			{
				printf("%4d", matrix->data[k].e);
			 	k++;
			}
			else
				printf("   0");
		}
		printf("\n");
	}
	printf("矩阵的三元组表示为：\n");
	for(int i=0; i<matrix->tu; ++i)
	{
		printf("(%d,%d,%d), ", matrix->data[i].i, matrix->data[i].j, matrix->data[i].e);
		if(i == matrix->tu - 1)
		 	printf("(%d,%d,%d)", matrix->data[i].i, matrix->data[i].j, matrix->data[i].e);
	}
	printf("\n\n");
	return OK;
}

status copy_matrix(sparse_matrix *m_matrix, sparse_matrix *t_matrix)
{
	t_matrix->mu = m_matrix->mu;
	t_matrix->nu = m_matrix->nu;
	t_matrix->tu = m_matrix->tu;
	for(int i=0; i<m_matrix->tu; i++)
	{
		t_matrix->data[i].i = m_matrix->data[i].i;
		t_matrix->data[i].j = m_matrix->data[i].j;
		t_matrix->data[i].e = m_matrix->data[i].e;
	}
	return OK;
}

status add_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix)
{
	if(m_matrix->mu != n_matrix->mu && m_matrix->nu != n_matrix->nu)
		return ERROR;

	t_matrix->mu = m_matrix->mu;
	t_matrix->nu = m_matrix->nu;
	t_matrix->tu = m_matrix->tu;
	for(int i=0; i<t_matrix->tu; ++i)
	{
		t_matrix->data[i].i = m_matrix->data[i].i;
		t_matrix->data[i].j = m_matrix->data[i].j;
		t_matrix->data[i].e = m_matrix->data[i].e + n_matrix->data[i].e;
	}
	return OK;
}

status sub_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix)
{
	if(m_matrix->mu != n_matrix->mu && m_matrix->nu != n_matrix->nu)
		return ERROR;

	t_matrix->mu = m_matrix->mu;
	t_matrix->nu = m_matrix->nu;
	t_matrix->tu = m_matrix->tu;

	for(int i=0; i<t_matrix->tu; ++i)
	{
		t_matrix->data[i].i = m_matrix->data[i].i;
		t_matrix->data[i].j = m_matrix->data[i].j;
		t_matrix->data[i].e = m_matrix->data[i].e - n_matrix->data[i].e;
	}
	return OK;
}

status mul_matrix(sparse_matrix *m_matrix, sparse_matrix *n_matrix, sparse_matrix *t_matrix)
{
	if(m_matrix->nu != n_matrix->mu)
		return ERROR;
	t_matrix->mu = m_matrix->mu;
	t_matrix->nu = n_matrix->nu;
	/* Unfinish */
}

status transpose_matrix(sparse_matrix *m_matrix, sparse_matrix *t_matrix)
{
	t_matrix->mu = m_matrix->nu;
	t_matrix->nu = m_matrix->mu;
	t_matrix->tu = m_matrix->tu;

	int k = 0;
	if(m_matrix->tu != 0)
	{
		for(int col=0; col<m_matrix->nu; ++col)
		{
			for(int i=0; i<m_matrix->tu; ++i)
			{
				if(m_matrix->data[i].j == col)
				{
					t_matrix->data[k].i = m_matrix->data[i].j;
					t_matrix->data[k].j = m_matrix->data[i].i;
					t_matrix->data[k].e = m_matrix->data[i].e;
					k++;
				}
			}
		}
	}
}

status fast_transpose_matrix(sparse_matrix *m_matrix, sparse_matrix *t_matrix)
{
 	t_matrix->mu = m_matrix->nu;
	t_matrix->nu = m_matrix->mu;
	t_matrix->tu = m_matrix->tu;

	int *num = (int*)malloc(sizeof(int) * m_matrix->tu);
	assert(num != NULL);
	int *cpot = (int*)malloc(sizeof(int) * m_matrix->nu); 	/* cpot: column position */
	assert(cpot != NULL);

	int col;
	if(t_matrix->tu != 0)
	{
		for(col=0; col<m_matrix->nu; ++col)
		{
			num[col] = 0;
		}
		for(int t=0; t<m_matrix->tu; ++t)
		{
			num[m_matrix->data[t].j]++; 
		}
		cpot[0] = 0;
		for(col=1; col<m_matrix->nu; ++col)
		{
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		int q = 0;
		for(int p=0; p<m_matrix->tu; ++p)
		{
			col = m_matrix->data[p].j;
			q = cpot[col];
			t_matrix->data[q].i = m_matrix->data[p].j;
			t_matrix->data[q].j = m_matrix->data[p].i;
			t_matrix->data[q].e = m_matrix->data[p].e;
			cpot[col]++;
		}
	}
	free(num);
	free(cpot);
}

