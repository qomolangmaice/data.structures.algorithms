/*
 *  File Name: graph_matrix.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:09
 */


void init_graph(graph_mtx *gm)
{
	gm->max_vertices = default_vertex_size;
	gm->num_vertices = gm->num_edges = 0;

	gm->vertices_list = (elem_type*)malloc(sizeof(elem_type) * (gm->max_vertices));
	assert(gm->vertices_list != NULL);

	gm->edge = (int**)malloc(sizeof(int*) * (gm->max_vertices));
	assert(gm->edge != NULL);

	for(int i=0; i<gm->max_vertices; ++i)
	{
		gm->edge[i] = (int*)malloc(sizeof(int) * gm->max_vertices);
	}
	for(int i=0; i<gm->max_vertices; ++i)
	{
		for(int j=0; j<gm->max_vertices; ++j)
		{
			gm->edge[i][j] = 0;
		}
	}
}

void insert_vertex(graph_mtx *gm, elem_type v)
{
	if(gm->num_vertices >= gm->max_vertices)
		return;
	gm->vertices_list[gm->num_vertices++] = v;
}

void show_graph(graph_mtx *gm)
{
	printf("  ");
	for(int i=0; i<gm->num_vertices; ++i)
	{
		printf("%c  ", gm->vertices_list[i]);
	}
	printf("\n");
	for(int i=0; i<gm->num_vertices; ++i)
	{
		printf("%c ", gm->vertices_list[i]);
		for(int j=0; j<gm->num_vertices; ++j)
		{
			printf("%d  ", gm->edge[i][j]);
		}
		printf("\n");
	}
}

/* 获取图中的顶点 */
int get_vertex_pos(graph_mtx *gm, elem_type v)
{
	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->vertices_list[i] == v)
			return i;
	}
	return -1;
}

/* 向图中插入边 */
void insert_edge(graph_mtx *gm, elem_type v1, elem_type v2)
{
	int p1 = get_vertex_pos(gm, v1);
	int p2 = get_vertex_pos(gm, v2);

	if(p1 == -1 || p2 == -1)
		return;

	gm->edge[p1][p2] = gm->edge[p2][p1] = 1;
	gm->num_edges++;
}

/* 删除图中的顶点  */
void delete_vertex(graph_mtx *gm, elem_type v)
{
 	int p = get_vertex_pos(gm, v);
	int numedges = 0;

	if(p == -1)
		return;
	for(int i=p; i<gm->num_vertices-1; ++i)
	{
		gm->vertices_list[i] = gm->vertices_list[i + 1];
	}

	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->edge[p][i] != 0)
		{
			numedges++;
		}
	}

	for(int i=p; i<gm->num_vertices-1; ++i)
	{
		for(int j=0; j<gm->num_vertices; ++j)
		{
			gm->edge[i][j] = gm->edge[i + 1][j];
		}
	}
 	for(int i=p; i<gm->num_vertices; ++i)
	{
		for(int j=0; j<gm->num_vertices; ++j)
		{
			gm->edge[j][i] = gm->edge[j][i+1];
		}
	}
	gm->num_vertices--;
	gm->num_edges = numedges;
}

/* 删除图中的边 */
void delete_edge(graph_mtx *gm, elem_type v1, elem_type v2)
{
 	int p1 = get_vertex_pos(gm, v1);
	int p2 = get_vertex_pos(gm, v2);

	if(p1 == -1 || p2 == -1)
		return;

	gm->edge[p1][p2] = gm->edge[p2][p1] = 0;
	gm->num_edges--;
}

void destroy_graph(graph_mtx *gm)
{
	free(gm->vertices_list);
	gm->vertices_list = NULL;
	for(int i=0; i<gm->num_vertices; ++i)
		free(gm->edge[i]);
	free(gm->edge);
	gm->edge = NULL;
	gm->max_vertices = gm->num_edges = gm->num_vertices = 0;
}

/* 取第一个相邻的点 */
int get_first_neighbor(graph_mtx *gm, elem_type v)
{
	int p = get_vertex_pos(gm, v);
	if(p == -1)
		return -1;
	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->edge[p][i] == 1)
			return i;
	}
	return -1;
}

/* 取下一个相邻的点 */
int get_next_neighbor(graph_mtx *gm, elem_type v, elem_type w)
{
	int pv = get_vertex_pos(gm, v);
	int pw = get_vertex_pos(gm, w);

	if(pv == -1 || pw == -1)
		return -1;

	for(int i=pw; i<gm->num_vertices; ++i)
	{
		if(gm->edge[pv][i] == 1)
			return i;
	}
	return -1;
}













