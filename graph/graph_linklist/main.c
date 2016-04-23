/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.21 20:38:32
 */
#include "graph_linklist.c"

int main()
{
	graph_link gl;

	init_graph(&gl);

	insert_vertex(&gl, 'A');
	insert_vertex(&gl, 'B');
	insert_vertex(&gl, 'C');
	insert_vertex(&gl, 'D');
	insert_vertex(&gl, 'E');

	printf("Create a graph like: \n");
	printf(" A---B\n");
	printf(" |  /|\n");
	printf(" | C |\n");
	printf(" |/ \\|\n");
	printf(" D   E\n");

	insert_edge(&gl, 'A', 'B');
	insert_edge(&gl, 'A', 'D');
	insert_edge(&gl, 'B', 'C');
	insert_edge(&gl, 'B', 'E');
	insert_edge(&gl, 'C', 'D');
	insert_edge(&gl, 'C', 'E');
	printf("\n");
	show_graph(&gl);

	int v = get_first_neighbor(&gl, 'A');

	printf("The first neighbor node of 'A' is: %d\n", v);

	int v1 = get_next_neighbor(&gl, 'B', 'E');
	printf("The next neighbor node of 'B' and 'E' is: %d\n", v1);
	printf("\n");

	//delete_edge(&gl, 'B', 'C');
	//show_graph(&gl);

	delete_vertex(&gl, 'C');
	show_graph(&gl);
	destroy_graph(&gl);
}
