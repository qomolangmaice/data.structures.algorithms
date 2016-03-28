/*
 *     File Name: seq_queue.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 17:25:52
 */

status init_queue(seq_queue *queue)
{
	queue->base = (elem_type*)malloc(QUEUE_INIT_SIZE * sizeof(elem_type));
	assert(queue->base != NULL);
	queue->front = queue->rear = 0;
	return OK;
}

status is_empty(seq_queue *queue)
{
	if(queue->rear == queue->front)
		return TRUE;
	else
		return FALSE;
}

status is_full(seq_queue *queue)
{
	if(queue->rear - queue->front >= QUEUE_INIT_SIZE)
		return TRUE;
	else
		return FALSE;
}

status en_queue(seq_queue *queue, elem_type val)
{
	if(is_full(queue))
	{
		return ERROR;
	}

	queue->base[queue->rear++]= val;
	return OK;
}

status de_queue(seq_queue *queue, elem_type *p_val)
{
	if(is_empty(queue))
		return ERROR;

	*p_val = queue->base[queue->front];
	queue->front++;
	return OK;
}

status get_head(seq_queue *queue, elem_type *p_val)
{
	if(is_empty(queue))
		return ERROR;
	*p_val = queue->base[queue->front];
	return OK;
}

int get_length(seq_queue *queue)
{
	return (queue->rear - queue->front);
}

status show_queue(seq_queue *queue)
{
	for(int i=queue->front; i<queue->rear; ++i)
		printf("%d ", queue->base[i]);
	printf("\n");
}

status clear_queue(seq_queue *queue)
{
	queue->rear = queue->front = 0;
	return OK;
}

status destroy_queue(seq_queue *queue)
{
	clear_queue(queue);
	free(queue->base);
	return ERROR;
}


