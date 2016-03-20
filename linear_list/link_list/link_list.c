/*
* File Name: link_list.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:42:35
*/

node* _malloc_node(elem_type val)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}

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
	node *s = _malloc_node(item);

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
 	node *s = _malloc_node(item);
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
	node *s = _malloc_node(val);

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
		p = p->next;
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
	{
		printf("要删除的数据不存在.\n");
		return ERROR;
	}

	if(p == list->tail)
	{
		pop_back(list);
	}
	else
	{
		node *q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
	 	list->size--;
	}
	return OK;
}

status sort(link_list *list)
{
	/*
	 * 排序的中心思想：将链表断成两部分，再将后面的链表数据进行插值插入到前面的链表中。
	 */
	if(list->size == 0 || list->size == 1)
		return ERROR;

	node *s = list->head->next;
	node *q = s->next;

	list->tail = s;
	list->tail->next = NULL;

	while(q != NULL)
	{
		s = q;
		q = q->next;

		node *p = list->head;
		while(p->next != NULL && p->next->data < s->data)
			p = p->next;

		if(p->next == NULL)
			list->tail = s;

		s->next = p->next;
		p->next = s;
	}
	return OK;
}

status resver(link_list *list)
{
	if(list->size == 0 || list->size == 1)
		return ERROR;

	node *p = list->head->next;
	node *q = p->next;

	list->tail = p;
	list->tail->next = NULL;

	while(q != NULL)
	{
		p = q;
		q = p->next;

		p->next = list->head->next;
		list->head->next = p;
	}
	return OK;
}

status clear(link_list *list)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head->next;
	while(p != NULL)
	{
		list->head->next = p->next;
		free(p);
		p = list->head->next;
	}
	list->tail = list->head;
	list->size = 0;
	return OK;
}

status destroy(link_list *list)
{
	clear(list);
	free(list->head);
	list->head = list->tail = NULL;
	list->size = 0;
	return OK;
}

node* prior_node(link_list *list, elem_type val)
{
	if(list->size == 0 || list->size == 1)
	{
		printf("要查找的数据在单链表中不存在前驱.\n");
	 	return ERROR;
	}

	node *p = list->head;	
 	while(p != NULL && p->next->data != val)
		p = p->next;

	return p;
}

node* next_node(link_list *list, elem_type val)
{
	if(list->size == 0)
	{
		printf("要查找的数据在单链表中不存在后继.\n");
	 	return ERROR;
	}

	node *p = list->head;
	while(p->next != NULL && p->data != val)
		p = p->next;
	return p->next;
}









