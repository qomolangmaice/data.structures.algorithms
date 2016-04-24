/*
 *  File Name: mini_span_tree-PRIM.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.20 19:14:09
 */

void init_graph(graph_mtx *gm)
{
	gm->max_vertices = default_vertex_size;
	gm->num_vertices = gm->num_edges = 0;

	gm->vertices_list = (vertex_type*)malloc(sizeof(vertex_type) * (gm->max_vertices));
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
			/* 顶点自身到自身的权值为0 */
			if(i == j)
				gm->edge[i][j] = 0;
			/* 顶点到其他顶点的权值默认为无穷大 */
			else
			 	gm->edge[i][j] = MAX_COST;
		}
	}
}

void insert_vertex(graph_mtx *gm, vertex_type vertex)
{
	if(gm->num_vertices >= gm->max_vertices)
		return;
	gm->vertices_list[gm->num_vertices++] = vertex;
}

void show_graph(graph_mtx *gm)
{
	printf("   ");
	for(int i=0; i<gm->num_vertices; ++i)
	{
		printf("%2c  ", gm->vertices_list[i]);
	}
	printf("\n");
	for(int i=0; i<gm->num_vertices; ++i)
	{
		printf("%2c ", gm->vertices_list[i]);
		for(int j=0; j<gm->num_vertices; ++j)
		{
			if(gm->edge[i][j] == MAX_COST)
				printf("%2c  ", '@');
			else
			 	printf("%2d  ", gm->edge[i][j]);
		}
		printf("\n");
	}
}

/* 获取图中的顶点 */
int get_vertex_pos(graph_mtx *gm, vertex_type vertex)
{
	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->vertices_list[i] == vertex)
			return i;
	}
	return -1;
}

/* 向图中插入边 */
void insert_edge(graph_mtx *gm, vertex_type vertex1, vertex_type vertex2, weight_type cost)
{
	int vertex_pos1 = get_vertex_pos(gm, vertex1);
	int vertex_pos2 = get_vertex_pos(gm, vertex2);

	if(vertex_pos1 == -1 || vertex_pos2 == -1)
		return;

	/*有向图插入边的时候，给相应方向顶点到顶点的边赋权值 */
	gm->edge[vertex_pos1][vertex_pos2] = cost;

	/*无向图插入边的时候，给相应的顶点的边分别赋权值 */
	//gm->edge[vertex_pos1][vertex_pos2] = gm->edge[vertex_pos2][vertex_pos1] = cost;
	gm->num_edges++;
}

/* 删除图中的顶点  */
void delete_vertex(graph_mtx *gm, vertex_type vertex)
{
 	int vertex_pos = get_vertex_pos(gm, vertex);
	int numedges = 0;

	if(vertex_pos == -1)
		return;
	for(int i=vertex_pos; i<gm->num_vertices-1; ++i)
	{
		gm->vertices_list[i] = gm->vertices_list[i + 1];
	}

	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->edge[vertex_pos][i] != 0)
		{
			numedges++;
		}
	}

	for(int i=vertex_pos; i<gm->num_vertices-1; ++i)
	{
		for(int j=0; j<gm->num_vertices; ++j)
		{
			gm->edge[i][j] = gm->edge[i + 1][j];
		}
	}
 	for(int i=vertex_pos; i<gm->num_vertices; ++i)
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
void delete_edge(graph_mtx *gm, vertex_type vertex1, vertex_type vertex2)
{
 	int vertex_pos1 = get_vertex_pos(gm, vertex1);
	int vertex_pos2 = get_vertex_pos(gm, vertex2);

	if(vertex_pos1 == -1 || vertex_pos2 == -1)
		return;

	gm->edge[vertex_pos1][vertex_pos2] = gm->edge[vertex_pos2][vertex_pos1] = 0;
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
int get_first_neighbor(graph_mtx *gm, vertex_type vertex)
{
	int vertex_pos = get_vertex_pos(gm, vertex);
	if(vertex_pos == -1)
		return -1;
	for(int i=0; i<gm->num_vertices; ++i)
	{
		if(gm->edge[vertex_pos][i] == 1)
			return i;
	}
	return -1;
}

/* 取下一个相邻的点 */
int get_next_neighbor(graph_mtx *gm, vertex_type vertex, vertex_type next_vertex)
{
	int vertex_pos = get_vertex_pos(gm, vertex);
	int next_vertex_pos = get_vertex_pos(gm, next_vertex);

	if(vertex_pos == -1 || next_vertex_pos == -1)
		return -1;

	for(int i=next_vertex_pos; i<gm->num_vertices; ++i)
	{
		if(gm->edge[vertex_pos][i] == 1)
			return i;
	}
	return -1;
}

/* 取顶点到顶点之间的权值 get weight from point to point */
weight_type get_P2P_weight(graph_mtx *gm, int vertex_pos1, int vertex_pos2)
{
	if(vertex_pos1 == -1 || vertex_pos2 == -1)
		return MAX_COST;
	else
		return gm->edge[vertex_pos1][vertex_pos2];
}

/* 最短路径－Dijkstra算法 */
void shortest_path_Dijkstra(graph_mtx *gm, vertex_type vertex, weight_type distance[], int path[])
{
	int n_vertices = gm->num_vertices;
	bool *shortest_path_set = (bool*)malloc(sizeof(bool) * n_vertices);
	assert(shortest_path_set != NULL);

	int vertex_pos = get_vertex_pos(gm, vertex);

	for(int i=0; i<n_vertices; ++i)
	{
		distance[i] = get_P2P_weight(gm, vertex_pos, i);
		shortest_path_set[i] = FALSE;
		if(i != vertex_pos && distance[i] < MAX_COST)
		{
			path[i] = vertex_pos;
		}
		else
		{
			path[i] = -1;
		}
	}

	shortest_path_set[vertex_pos] = TRUE;
	weight_type min_weight;
 	weight_type w_weight;
	int start, end;
	for(int i=0; i<n_vertices-1; ++i)
	{
 	 	min_weight = MAX_COST;
		int min_weight_index = vertex_pos;
		for(int j = 0; j<n_vertices; ++j)
		{
			if(!shortest_path_set[j] && distance[j] < min_weight)
			{
				min_weight_index = j;
				min_weight = distance[j];
			}
		}
		
		shortest_path_set[min_weight_index] = TRUE;
		for(int k=0; k<n_vertices; ++k)
		{
			w_weight = get_P2P_weight(gm, min_weight_index, k);
			if(!shortest_path_set[k] && w_weight < MAX_COST && distance[min_weight_index]+w_weight < distance[k])
			{
				distance[k] = distance[min_weight_index] + w_weight;
				path[k] = min_weight_index;
			}
		}
	}
}



