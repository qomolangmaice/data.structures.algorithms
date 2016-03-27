/*
 *     File Name: cir_seq_queue.c
 *     Description: circular sequence queue 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.27 21:21:43
 */

status init_queue(cir_seq_queue *queue)
{
	queue->base = (elem_type*)malloc(sizeof(elem_type));
	assert(queue->base != NULL);
	queue->front = queue->rear = 0;
	return OK;
}

status is_empty(cir_seq_queue *queue)
{
	if(queue->rear == queue->front)
		return TRUE;
	else
		return FALSE;
}

status is_full(cir_seq_queue *queue)
{
	if(queue->rear - queue->front >= QUEUE_INIT_SIZE)
		return TRUE;
	else
		return FALSE;
}

status en_queue(cir_seq_queue *queue, elem_type val)
{
 	if(is_full(queue))
		return ERROR;

	queue->base[queue->rear++] = val;
}

status show_queue(cir_seq_queue *queue)
{
	for(int i=queue->front; i<queue->rear; ++i)
		printf("%d ", queue->base[i]);
	printf("\n");
	return OK;
}









