/*
* File Name: circular_list.c
* Description: circular link list 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.18 19:42:33
*/

node* _malloc_node(elem_type val)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
	return s;
}

status init_list(circular_list *list)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	list->head = list->tail = s;
	list->tail->next = list->head;
	list->size = 0;
	return OK;
}

status push_back(circular_list *list, elem_type item)
{
	node *s = _malloc_node(item);
	list->tail->next = s;
	list->tail= s;
	list->tail->next = list->head;
	list->size++;
	return OK;
}

status show_list(circular_list *list)
{
	node *p = list->head->next;
	while(p != list->head)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Null.\n");
}

status push_front(circular_list *list, elem_type item)
{
	node *s = _malloc_node(item);
	s->next = list->head->next;
	list->head->next = s;
	if(list->head == list->tail)
		list->tail = s;
	list->size++;
	return OK;
}

status pop_back(circular_list *list)
{
	if(list->size == 0)
		return ERROR;
	node *p = list->head;
	while(p->next != list->tail)
		p = p->next;

	free(list->tail);
	list->tail = p;
	list->tail->next = list->head;
	list->size--;
	return ERROR;
}

status pop_front(circular_list *list)
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

status insert_val(circular_list *list, elem_type val)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head;
	while(p->next != list->tail && p->next->data < val)
		p = p->next;
 	
	if(p->next == list->tail && p->next->data < val)
	{
	  	push_back(list, val);
	}
	else
	{
		node *s = _malloc_node(val);
		s->next = p->next;
		p->next = s;
		list->size++;
	}
	return OK;
}

node* find(circular_list *list, elem_type key)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head->next;
	while(p != NULL && p->data != key)
		p = p->next;
	
	if(p == list->head)
		return NULL;
	return p;
}

int get_length(circular_list *list)
{
	return list->size;
}

status delete_val(circular_list *list, elem_type val)
{
	if(list->size == 0)
		return ERROR;

	node *p = find(list, val);
	if(p == NULL)
	{
		printf("循环链表中不存在要删除的数据.\n");
		return ERROR;
	}

	if(p == list->tail)
		pop_back(list);
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

status sort(circular_list *list)
{
 	if(list->size == 0 | list->size == 1)
		return ERROR;

	node *s = list->head->next;
	node *q = s->next;

	/* Break the circular link list */
	list->tail->next = NULL;
	list->tail = s;
	list->tail->next = list->head;

	while(q != NULL)
	{
		s = q;
		q = q->next;

		node *p = list->head;
		while(p->next != list->tail && p->next->data < s->data)
			p = p->next;

		if(p->next == list->tail && p->next->data < s->data)
		{
			s->next = list->tail->next;
			list->tail->next = s;
			list->tail = s;
		}
		else
		{
			s->next = p->next;
			p->next = s;
		}
	}
	return OK;
}

status resver(circular_list *list)
{
	if(list->size == 0 || list->size == 1)
		return ERROR;

	node *p = list->head->next;
	node *q = p->next;

	list->tail->next = NULL;
	list->tail = p;
	list->tail->next = list->head;

	while(q != NULL)
	{
		p = q;
		q = q->next;

		p->next = list->head->next;
		list->head->next = p;
	}
	return OK;
}

status clear(circular_list *list)
{
	node *p = list->head->next;
	while(p != list->head)
	{
		list->head->next = p->next;
		free(p);
		p = list->head->next;
	}

	list->tail = list->head;
	list->tail->next = list->head;
	list->size = 0;
	return OK;
}

status destroy(circular_list *list)
{
	clear(list);
	free(list->head);
	list->head = list->tail = NULL;
	return OK;
}















