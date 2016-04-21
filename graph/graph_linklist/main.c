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

	insert_edge(&gl, 'A', 'B');
	insert_edge(&gl, 'A', 'D');
	insert_edge(&gl, 'B', 'C');
	insert_edge(&gl, 'B', 'E');
	insert_edge(&gl, 'C', 'D');
	insert_edge(&gl, 'C', 'E');

	show_graph(&gl);
}
