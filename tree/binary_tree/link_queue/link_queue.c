/*
 *     File Name: link_queue.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 13:01:10
 */

status init_queue(link_queue *queue)
{
	queue_node *s = (queue_node*)malloc(sizeof(queue_node));
	assert(s != NULL);
	queue->head = queue->tail = s;
	queue->tail->next = NULL;
	return OK;
}

status queue_is_empty(link_queue *queue)
{
	if(queue->head == queue->tail)
		return TRUE;
	else
		return FALSE;
}

status en_queue(link_queue *queue, q_elem_type val)
{
	queue_node *s = (queue_node*)malloc(sizeof(queue_node)); 
	assert(s != NULL);
	s->data = val;
	s->next = NULL;

	queue->tail->next =s;
	queue->tail = s;
	return OK;
}

//status de_queue(link_queue *queue, q_elem_type *p_val)
status de_queue(link_queue *queue)
{
	if(queue_is_empty(queue))
		return ERROR;

	queue_node *p = queue->head->next;
	//*p_val = p->data;

	queue->head->next = p->next;
	free(p);
	if(p == queue->tail)
		queue->tail = queue->head;
	return OK;
}

status get_head(link_queue *queue, q_elem_type *p_val)
{
	if(queue_is_empty(queue))
		return ERROR;

	queue_node *p = queue->head->next;
	*p_val = p->data;
	return OK;
}

int get_length(link_queue *queue)
{
	int len = 0;

	queue_node *p = queue->head->next;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

status show_queue(link_queue *queue)
{
	queue_node *p = queue->head->next;
	printf("Head:>");
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<:Tail.\n");
	return OK;
}

status clear_queue(link_queue *queue)
{
	if(queue_is_empty(queue))
		return ERROR;

	queue_node *p = queue->head->next;
	while(p == NULL)
	{
		queue->head->next = p->next;
		free(p);
		p = queue->head->next;
	}
	queue->tail = queue->head;
	return OK;
}

status destroy_queue(link_queue *queue)
{
	clear_queue(queue);
	free(queue->head);
	queue->head = queue->tail = NULL;
	return OK;
}

