/*
 *  File Name: graph_linklist.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.21 20:38:23
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

#define default_vertex_size 20

typedef int boolean;
typedef char g_elem_type;

typedef struct edge{
	int dest;
	struct edge *link;
}egde;

typedef struct vertex{
	g_elem_type data;
	egde *adj; 	 	/* adjacency list */
} vertex;

typedef struct graph_link{
	int max_vertices;
	int num_vertices;
	int num_edges;

	vertex *node_table;
} graph_link;

void init_graph(graph_link *gl);
int get_vertex_pos(graph_link *gl, g_elem_type v);
void insert_vertex(graph_link *gl, g_elem_type v);
void show_graph(graph_link *gl);
void insert_edge(graph_link *gl, g_elem_type vertex1, g_elem_type vertex2);
void delete_edge(graph_link *gl, g_elem_type vertex1, g_elem_type vertex2);
void delete_vertex(graph_link *gl, g_elem_type vertex);
void destroy_graph(graph_link *gl);
int get_first_neighbor(graph_link *gl, g_elem_type vertex);
int get_next_neighbor(graph_link *gl, g_elem_type vertex1, g_elem_type vertex2);
g_elem_type get_vertex_value(graph_link *gl, int vertex_pos);

void depth_first_search(graph_link *gl, g_elem_type vertex);
void depth_first_search_(graph_link *gl, int vertex_pos, boolean visited_flag[]);

void breadth_first_search(graph_link *gl, g_elem_type vertex);

void components(graph_link *gl);
