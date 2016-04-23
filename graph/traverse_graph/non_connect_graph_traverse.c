/*
 *  File Name: non_connect_graph_traverse.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.23 21:31:48
 */
#include "traverse_graph.c"

int main()
{
	graph_link gl;

	init_graph(&gl);

	insert_vertex(&gl, 'A');
	insert_vertex(&gl, 'B');
	insert_vertex(&gl, 'C');
	insert_vertex(&gl, 'D');
	insert_vertex(&gl, 'E');
	insert_vertex(&gl, 'F');
	insert_vertex(&gl, 'G');
	insert_vertex(&gl, 'H');
	insert_vertex(&gl, 'I');
	insert_vertex(&gl, 'J');
	insert_vertex(&gl, 'K');
	insert_vertex(&gl, 'L');
	insert_vertex(&gl, 'M');

	insert_edge(&gl, 'A', 'B');
	insert_edge(&gl, 'A', 'C');
	insert_edge(&gl, 'A', 'F');
	insert_edge(&gl, 'A', 'L');
	insert_edge(&gl, 'B', 'M');
	insert_edge(&gl, 'L', 'J');
	insert_edge(&gl, 'L', 'M');
	insert_edge(&gl, 'J', 'M');

	insert_edge(&gl, 'D', 'E');

	insert_edge(&gl, 'G', 'H');
	insert_edge(&gl, 'G', 'I');
	insert_edge(&gl, 'G', 'K');
	insert_edge(&gl, 'H', 'K');

	printf("\n");
	show_graph(&gl);

	printf("Depth First Search(DFS) all nodes of the graph: \n");
	depth_first_search(&gl, 'D');
	printf("Nul\n");

	printf("Breadth First Search(BFS) all nodes of the graph: \n");
	breadth_first_search(&gl, 'A');
	printf("Nul\n");

	printf("Non connect graph DFS: \n");
	components(&gl);
	printf("Nul\n");

	//int v = get_first_neighbor(&gl, 'A');
	//printf("The first neighbor node of 'A' is: %d\n", v);

	//int v1 = get_next_neighbor(&gl, 'B', 'E');
	//printf("The next neighbor node of 'B' and 'E' is: %d\n", v1);
	//printf("\n");

	//delete_edge(&gl, 'B', 'C');
	//show_graph(&gl);

	//delete_vertex(&gl, 'C');
	destroy_graph(&gl);
}
