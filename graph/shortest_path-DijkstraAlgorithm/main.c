/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:21
 */
#include "shortest_path-DijkstraAlgorithm.h"
#include "shortest_path-DijkstraAlgorithm.c"

int main()
{
	graph_mtx gm;
	init_graph(&gm);
	insert_vertex(&gm, 'A');
	insert_vertex(&gm, 'B');
	insert_vertex(&gm, 'C');
	insert_vertex(&gm, 'D');
	insert_vertex(&gm, 'E');

	insert_edge(&gm, 'A', 'B', 10);
	insert_edge(&gm, 'A', 'D', 30);
	insert_edge(&gm, 'A', 'E', 100);
	insert_edge(&gm, 'B', 'C', 50);
	insert_edge(&gm, 'C', 'E', 10);
	insert_edge(&gm, 'D', 'C', 20);
	insert_edge(&gm, 'D', 'E', 60);
	show_graph(&gm);
	printf("\n");

	int n_vertices = gm.num_vertices;
	weight_type distance[5];
	int path[5];
	//weight_type *distance= (weight_type*)malloc(sizeof(weight_type) * n_vertices);
	//int *path = (int*)malloc(sizeof(int) * n_vertices);
	//assert(distance!= NULL && path != NULL);

	shortest_path_Dijkstra(&gm, 'A', distance, path);

	for(int i=0; i<5; ++i)
		printf("distance[%d] = %d\n", i, distance[i]);
	printf("\n");

	for(int i=0; i<5; ++i)
		printf("path[%d] = %d\n", i, path[i]);
	printf("\n");

	destroy_graph(&gm);
}










