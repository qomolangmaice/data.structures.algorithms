/*
 *  File Name: graph_matrix.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:16
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define default_vertex_size 10

typedef char elem_type;

typedef struct graph_mtx{
	int max_vertices; /* 图的顶点数最大值 */
	int num_vertices; /* 图的顶点数 */
	int num_edges; 	  /* 图的边数 */

	elem_type *vertices_list; 	/* 图的顶点列表 */
	int **edge; 	 /* 图的边 */
} graph_mtx;

void init_graph(graph_mtx *gm);

/*　向图中插入顶点 */
void insert_vertex(graph_mtx *gm, elem_type v);

/* 获取图的顶点 */
int get_vertex_pos(graph_mtx *gm, elem_type v);

void show_graph(graph_mtx *gm);

/* 向图中插入边 */
void insert_edge(graph_mtx *gm, elem_type v1, elem_type v2);

/* 删除图中的顶点  */
void delete_vertex(graph_mtx *gm, elem_type v);

/* 删除图中的边 */
void delete_edge(graph_mtx *gm, elem_type v1, elem_type v2);

void destroy_graph(graph_mtx *gm);

/* 取第一个相邻的点 */
int get_first_neighbor(graph_mtx *gm, elem_type v);

/* 取下一个相邻的点 */
int get_next_neighbor(graph_mtx *gm, elem_type v, elem_type w);



