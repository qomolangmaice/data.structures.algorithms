/*
 *  File Name: graph_linklist.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.21 20:38:27
 */
#include "graph_linklist.h"

void init_graph(graph_link *gl)
{
	gl->max_vertices = default_vertex_size;
	gl->num_edges = gl->num_vertices = 0;
	gl->node_table = (vertex*)malloc(sizeof(vertex) * (gl->max_vertices));
	assert(gl->node_table != NULL);

	for(int i=0; i<gl->max_vertices; ++i)
	{
		gl->node_table[i].adj = NULL;
	}
}

int get_vertex_pos(graph_link *gl, elem_type v)
{
	for(int i=0; i<gl->num_vertices; ++i)
	{
		if(gl->node_table[i].data == v)
			return i;
	}
	return -1;
}

void insert_vertex(graph_link *gl, elem_type v)
{
	if(gl->num_vertices >= gl->max_vertices)
		return;
	gl->node_table[gl->num_vertices++].data = v;
}

void show_graph(graph_link *gl)
{
	edge *p;
	for(int i=0; i<gl->num_vertices; ++i)
	{
		printf("%d %c:>", i, gl->node_table[i].data);
		p = gl->node_table[i].adj;
		while(p != NULL)
		{
			printf("%d-->", p->dest);
			p = p->link;
		}
		printf("Nul\n");
	}
}

void insert_edge(graph_link *gl, elem_type vertex1, elem_type vertex2)
{
 	int v1 = get_vertex_pos(gl, vertex1);
	int v2 = get_vertex_pos(gl, vertex2);

	if(v1 == -1 || v2 == -1)
		return;

	edge *s;
	s = (edge*)malloc(sizeof(edge));
	assert(s != NULL);
	s->dest = v2;
	s->link = gl->node_table[v1].adj;
	gl->node_table[v1].adj = s;

	s = (edge*)malloc(sizeof(edge));
	assert(s != NULL);
	s->dest = v1;
	s->link = gl->node_table[v2].adj;
	gl->node_table[v2].adj = s;

	gl->num_edges++;
}











