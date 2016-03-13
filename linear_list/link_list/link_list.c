/*
* File Name: link_list.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:42:35
*/

status init_list(link_list *list)
{
	list->head = list->tail = (node *)malloc(sizeof(node));	
	assert(list->head != NULL);
	list->tail->next = NULL;
	list->size = 0;
	return OK;
}

status push_back(link_list *list, elem_type item)
{
	node *s = (node *)malloc(sizeof(node));
	assert(s != NULL);
	s->data = item;
	s->next = NULL;

	list->tail->next = s;
	list->tail = s;
	list->size++;
	return OK;
}

status show_list(link_list *list)
{
	node *p = list->head->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Null.\n");
	return OK;
}

status push_front(link_list *list, elem_type item)
{
	node *s = (node *)malloc(sizeof(node));
	assert(s != NULL);
	s->data = item;

	s->next = list->head->next;
	list->head->next = s;
	if(list->size == 0)
	{
		list->tail = s;
	}
	list->size++;
	return OK;
}

status pop_back(link_list *list)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head;
	/* 删除尾节点之前，先从头开始一步一步地查找到尾节点的前一节点. */
	while(p->next != list->tail)
		p = p->next;

	free(list->tail);
	list->tail = p;
	list->tail->next = NULL;
	list->size--;
	return OK;
}

status pop_front(link_list *list)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head->next;
	list->head->next = p->next;
	free(p);
	if(list->size == 1)
		list->tail = list->head;
	list->size--;
	return OK;
}

/* insert_val函数的操作前提是单链表中的数据是升序的 */
status insert_val(link_list *list, elem_type val)
{
	node *s = (node *)malloc(sizeof(node));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;

	node *p = list->head;
	while(p->next != NULL && p->next->data < val)
		p = p->next;

	if(p->next == NULL)
		list->tail = s;

	s->next = p->next;
	p->next = s;
	list->size++;
	return OK;
}

node* find(link_list *list, elem_type key)
{
	node *p = list->head->next;
	while(p != NULL && p->data != key)
	{
		p = p->next;
	}
	return p;
}

int get_length(link_list *list)
{
	return list->size;
}

status delete_val(link_list *list, elem_type key)
{
	if(list->size == 0)
		return ERROR;

	node *p = find(list, key);
	if(p == NULL)
		printf("要删除的数据不存在.\n");

	if(p = list->tail)
	{
		pop_back(list);
	}
	else
	{
		node *q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
	}
	list->size--;
	return OK;
}





