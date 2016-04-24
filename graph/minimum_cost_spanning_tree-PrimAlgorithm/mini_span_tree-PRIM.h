/*
 *  File Name: mini_span_tree-PRIM.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:16
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define default_vertex_size 10
#define MAX_COST 0x7FFFFFFF

typedef char vertex_type;
typedef int weight_type; 	/* 权值类型(权值即图中顶点到顶点之间所花费的代价) */

typedef struct graph_mtx{
	int max_vertices; /* 图的顶点数最大值 */
	int num_vertices; /* 图的顶点数 */
	int num_edges; 	  /* 图的边数 */

	vertex_type *vertices_list; 	/* 图的顶点列表 */
	int **edge; 	 /* 图的边,保存顶点的权值 */
} graph_mtx;

void init_graph(graph_mtx *gm);

/*　向图中插入顶点 */
void insert_vertex(graph_mtx *gm, vertex_type vertex);

/* 获取图的顶点 */
int get_vertex_pos(graph_mtx *gm, vertex_type vertex);

void show_graph(graph_mtx *gm);

/* 向图中插入边和权值 */
void insert_edge(graph_mtx *gm, vertex_type vertex1, vertex_type vertex2, weight_type cost);

/* 删除图中的顶点  */
void delete_vertex(graph_mtx *gm, vertex_type vertex);

/* 删除图中的边 */
void delete_edge(graph_mtx *gm, vertex_type vertex1, vertex_type vertex2);

void destroy_graph(graph_mtx *gm);

/* 取第一个相邻的点 */
int get_first_neighbor(graph_mtx *gm, vertex_type vertex);

/* 取下一个相邻的点 */
int get_next_neighbor(graph_mtx *gm, vertex_type vertex, vertex_type next_vertex);

/* 最小生成树的普里姆(Prim)算法 */
void mini_span_tree_PRIM(graph_mtx *gm, vertex_type vertex);

/* 取顶点到顶点之间的权值 */
weight_type get_P2P_weight(graph_mtx *gm, int vertex_pos1, int vertex_pos2);



