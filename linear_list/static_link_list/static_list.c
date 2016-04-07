/*
* File Name: static_list.c
* Description: static link list
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.17 19:49:32
*/
int malloc_static_list(static_list &space)
{
	int i = space[1].cur;
	if(space[1].cur != 0)
		space[1].cur = space[i].cur;
	return i;
}

status free_static_list(static_list &space, int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
	return OK;
}

status init_list(static_list &space)
{
	for(int i=1; i<MAX_SIZE-1; ++i)
	{
 	 	space[i].cur = i + 1;
	}
	space[MAX_SIZE - 1].cur = 0;
	space[0].cur = -1;
	return OK;
}

status insert(static_list &space, elem_type val)
{
	int i = malloc_static_list(space);
	if(i == 0)
	{
		printf("数据空间申请失败.\n");
		return ERROR;
	}

	space[i].data = val;
	if(space[0].cur == -1)
	{
		space[i].cur = -1;
		//space[0].cur = i;
	}
	else
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
}

status delete_node(static_list &space)
{
	int i = space[0].cur;
	space[0].cur = space[i].cur;

	free_static_list(space, i);
}

status show_list(static_list &space)
{
	int i = space[0].cur;
	while(i != -1)
	{
		printf("%c-->",space[i].data);
		i = space[i].cur; //p = p->next;
	}
	printf("Null.\n");
}
