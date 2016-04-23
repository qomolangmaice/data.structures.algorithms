/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.21 20:38:32
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

	printf("       A\n");
	printf("     /   \\\n");
	printf("    B     C\n");
	printf("   / \\   / \\\n");
	printf("  D   E F---G\n");
	printf("    \\ |\n");
	printf("      H\n");

	insert_edge(&gl, 'A', 'B');
	insert_edge(&gl, 'A', 'C');
	insert_edge(&gl, 'B', 'D');
	insert_edge(&gl, 'B', 'E');
	insert_edge(&gl, 'D', 'H');
	insert_edge(&gl, 'E', 'H');
	insert_edge(&gl, 'C', 'F');
	insert_edge(&gl, 'C', 'G');
	insert_edge(&gl, 'F', 'G');
	printf("\n");
	show_graph(&gl);

	printf("Depth First Search(DFS) all nodes of the graph: \n");
	depth_first_search(&gl, 'A');
	printf("Nul\n");

	printf("Breadth First Search(BFS) all nodes of the graph: \n");
	breadth_first_search(&gl, 'A');
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
