/*
 *     File Name: link_queue.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 13:01:10
 */

queue_node* _malloc_node(elem_type val)
{
	queue_node *s = (queue_node*)malloc(sizeof(queue_node)); 
	assert(s != NULL);
	s->data = val;
	s->next = NULL;
}
status init_queue(link_queue *queue)
{
	queue_node *s = (queue_node*)malloc(sizeof(queue_node));
	assert(s != NULL);
	queue->front = queue->tail = s;
	queue->tail->next = NULL;
	return OK;
}

status en_queue(link_queue *queue, elem_type val)
{
	queue_node *s = _malloc_node(val);

	queue->tail->next =s;
	queue->tail = s;
	return OK;
}

status show_queue(link_queue *queue)
{
	queue_node *p = queue->front->next;
	printf("Front:>");
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<Tail.\n");
	return OK;
}








