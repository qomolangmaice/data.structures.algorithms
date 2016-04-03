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
	for(int i=0; i<matrix->tu; ++i)
	{
		printf("(%d, %d, %d)\n", matrix->data[i].i, matrix->data[i].j, matrix->data[i].e);
	}
	return OK;
}





















