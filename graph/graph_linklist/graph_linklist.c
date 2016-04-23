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
	printf("\n");
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

void delete_edge(graph_link *gl, elem_type vertex1, elem_type vertex2)
{
	int v1 = get_vertex_pos(gl, vertex1);
	int v2 = get_vertex_pos(gl, vertex2);

	if(v1 == -1 || v2 == -1)
		return;

	/* v1 --> v2 */
	edge *q = NULL;
	edge *p;
	p = gl->node_table[v1].adj; 
	while(p != NULL && p->dest!= v2)
	{
		q = p;
		p = p->link;
	}
	if(p == NULL)
		return;
	if(q == NULL)
	{
		gl->node_table[v1].adj = p->link;
	}
	else
	{
		q->link = p->link;
	}
	free(p);

	/* v2 --> v1 */
	q = NULL;
	p = gl->node_table[v2].adj;
	while(p->dest != v1)
	{
		q = p;
		p = p->link;
	}
	if(q == NULL)
	{
		gl->node_table[v2].adj = p->link;
	}
	else
	{
		q->link = p->link;
	}
	free(p);
}

void delete_vertex(graph_link *gl, elem_type vertex)
{
	int v = get_vertex_pos(gl, vertex);
	 
	if(v == -1)
		return;

	edge *p = gl->node_table[v].adj;
	int k;
	edge *pre_s = NULL;
	edge *s;
	while(p != NULL)
	{
 	 	k = p->dest;
		s = gl->node_table[k].adj;
		while(s != NULL && s->dest != v)
		{
			pre_s = s;
			s = s->link;
		}
		if(s != NULL)
		{
			if(pre_s == NULL)
			{
				gl->node_table[k].adj = s->link;
			}
			else
			{
				pre_s->link = s->link;
			}
			free(s);
		}
		gl->node_table[v].adj = p->link;
		free(p);
		p = gl->node_table[v].adj;
	}
 	gl->num_vertices--;
	gl->node_table[v].data = gl->node_table[gl->num_vertices].data;
	gl->node_table[v].adj = gl->node_table[gl->num_vertices].adj;

	s = gl->node_table[v].adj;
	while(s != NULL)
	{
		k = s->dest;
		p = gl->node_table[k].adj;
		while(p != NULL && p->dest == gl->num_vertices)
		{
			if(p->dest == gl->num_vertices)
			{
				p->dest = v;
				break;
			}
			p = p->link;
		}
		s = s->link;
	}
}

void destroy_graph(graph_link *gl)
{
	edge *p;
	for(int i=0; i<gl->num_vertices; ++i)
	{
		p = gl->node_table[i].adj;
		while(p != NULL)
		{
			gl->node_table[i].adj = p->link;
			free(p);
			p = gl->node_table[i].adj;
		}
	}
	free(gl->node_table);
	gl->node_table = NULL;
	gl->max_vertices = gl->num_edges = gl->num_vertices = 0;
}

int get_first_neighbor(graph_link *gl, elem_type vertex)
{
	int v = get_vertex_pos(gl, vertex);
	if(v == -1)
		return -1;

	edge *p = gl->node_table[v].adj;
	if(p != NULL)
		return p->dest;
	return -1;
}

int get_next_neighbor(graph_link *gl, elem_type vertex1, elem_type vertex2)
{
	int v1 = get_vertex_pos(gl, vertex1);
	int v2 = get_vertex_pos(gl, vertex2);

	if(v1 == -1 || v2 == -1)
		return -1;

	edge *p = gl->node_table[v1].adj;
	while(p != NULL && p->dest != v2)
		 p = p->link;
	if(p != NULL && p->link != NULL)
		return p->link->dest;
	return -1;
}













