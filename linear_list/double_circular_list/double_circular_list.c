/*
* File Name: double_circular_list.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.22 20:58:18
*/

node* _malloc_node(elem_type val)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	s->data = val;
	s->next = s->prior = NULL;
	return s;
}
status init_list(dou_cir_list *list)
{
	node *s = (node*)malloc(sizeof(node));
	assert(s != NULL);
	list->head = list->tail = s;
	list->head->prior = list->tail;
	list->tail->next = list->head;
	list->size = 0;
	return OK;
}

status push_back(dou_cir_list *list, elem_type val)
{
	node *s = _malloc_node(val);
	s->next = list->tail->next;
	s->next->prior = s;
	s->prior = list->tail;
	list->tail->next = s;
	list->tail = s;
	list->size++;
	return OK;
}

status show_list(dou_cir_list *list)
{
	node *p = list->head->next;
	while(p != list->head)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Null.\n");
	return OK;
}

status push_front(dou_cir_list *list, elem_type val)
{
	node *s = _malloc_node(val);
	s->next = list->head->next;
	s->next->prior = s;
	s->prior = list->head;
	list->head->next = s;

	if(list->head == list->tail)
		list->tail = s;
	list->size++;
	return OK;
}

status pop_back(dou_cir_list *list)
{
	if(list->size == 0)
		return ERROR;

	node *p = list->head;
	while(p->next != list->tail)
		p = p->next;

	p->next = list->head;
	list->head->prior = p;
	list->size--;
	return OK;
}


















