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





