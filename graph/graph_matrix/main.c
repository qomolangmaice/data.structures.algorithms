/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:21
 */
#include "graph_matrix.h"
#include "graph_matrix.c"

int main()
{
	graph_mtx gm;
	init_graph(&gm);
	insert_vertex(&gm, 'A');
	insert_vertex(&gm, 'B');
	insert_vertex(&gm, 'C');
	insert_vertex(&gm, 'D');
	insert_vertex(&gm, 'E');

	insert_edge(&gm, 'A', 'B');
	insert_edge(&gm, 'A', 'D');
	insert_edge(&gm, 'B', 'C');
	insert_edge(&gm, 'B', 'E');
	insert_edge(&gm, 'C', 'E');
	insert_edge(&gm, 'C', 'D');
	show_graph(&gm);
	printf("\n");

	int p = get_first_neighbor(&gm, 'A');
	printf("get_first_neighbor is true or false: %d\n", p);

	int q = get_next_neighbor(&gm, 'C', 'D');
	printf("get_next_neighbor is true or false: %d\n", q);

	delete_edge(&gm, 'B', 'C');
	show_graph(&gm);
	printf("\n");

	delete_vertex(&gm, 'C');
	show_graph(&gm);
	printf("\n");

	destroy_graph(&gm);
}
