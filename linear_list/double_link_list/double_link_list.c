/*
* File Name: double_link_list.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.20 17:09:23
*/

node* _malloc_node(elem_type val)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	s->data = val;
	s->next = s->prior = NULL;
	return s;
}
status init_list(d_link_list *list)
{
 	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	list->head = list->tail = s;
	list->tail->next = NULL;
	list->head->prior = NULL;
	list->size = 0;
	return OK;
}

status push_back(d_link_list *list, elem_type val)
{
	node *s = _malloc_node(val);
	s->prior = list->tail;
	list->tail->next = s;
	list->tail = s;
	list->size++;
	return OK;
}

status show_list(d_link_list *list)
{
	node *p = list->head->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Null.\n");
}

status push_front(d_link_list *list, elem_type val)
{
	node *s = _malloc_node(val);

	if(list->head == list->tail)
	{
		list->tail = s;
	}
	else
	{
 	 	s->next = list->head->next;
		s->next->prior = s;
	}
	s->prior = list->head;
	list->head->next = s;
	list->size++;
	return OK;
}

status pop_back(d_link_list *list)
{
	if(list->size == 0)
		return ERROR;
	node *p = list->head;
	while(p->next != list->tail)
		p = p->next;

	free(list->tail);
	list->tail = p;
	list->tail->next = NULL;
	list->size--;
	return OK;
}

status pop_front(d_link_list *list)
{
 	if(list->size == 0)
		return ERROR;

	node *p = list->head->next;

	if(p == list->tail)
	{
		list->tail = list->head;
		list->tail->next = NULL;
	}
	else
	{
		p->next->prior = list->head;
		list->head->next = p->next;
	}

	free(p);
	list->size--;
	return OK;
}

status insert_val(d_link_list *list, elem_type val)
{
	if(list->size == 0)
		return ERROR;

	node *s = _malloc_node(val);
	node *p = list->head;

	while(p->next != list->tail && p->next->data < s->data)
		p = p->next;

	if(p->next == list->tail && p->next->data < s->data)
		push_back(list, val);
	else
	{
		s->next = p->next;
		s->next->prior = s;
		s->prior = p;
		p->next = s;
	}
	list->size++;
	return OK;
}

node* find(d_link_list *list, elem_type key)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head;
	while(p != NULL && p->data != key)
		p = p->next;
	return p;
}

int get_length(d_link_list *list)
{
	return list->size;
}













