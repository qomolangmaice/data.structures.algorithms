/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:21
 */
#include "mini_span_tree-PRIM.h"
#include "mini_span_tree-PRIM.c"

int main()
{
	graph_mtx gm;
	init_graph(&gm);
	insert_vertex(&gm, 'A');
	insert_vertex(&gm, 'B');
	insert_vertex(&gm, 'C');
	insert_vertex(&gm, 'D');
	insert_vertex(&gm, 'E');
	insert_vertex(&gm, 'F');

	insert_edge(&gm, 'A', 'B', 6);
	insert_edge(&gm, 'A', 'C', 1);
	insert_edge(&gm, 'A', 'D', 5);
	insert_edge(&gm, 'B', 'C', 5);
	insert_edge(&gm, 'B', 'E', 3);
	insert_edge(&gm, 'C', 'D', 5);
	insert_edge(&gm, 'C', 'E', 6);
	insert_edge(&gm, 'C', 'F', 4);
	insert_edge(&gm, 'D', 'F', 2);
	insert_edge(&gm, 'E', 'F', 6);
	show_graph(&gm);
	printf("\n");

	printf("Minimum cost spanning tree in Prim algorithm: \n");
	mini_span_tree_PRIM(&gm, 'A');
	destroy_graph(&gm);
}
