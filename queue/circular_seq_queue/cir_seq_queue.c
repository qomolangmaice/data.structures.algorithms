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
	if((queue->rear + 1) % MAXSIZE == queue->front)
		return TRUE;
	else
		return FALSE;
}

status en_queue(cir_seq_queue *queue, elem_type val)
{
 	if(is_full(queue))
		return ERROR;

	queue->base[queue->rear] = val;
	queue->rear =(queue->rear + 1) % MAXSIZE;
	return OK;
}

status de_queue(cir_seq_queue *queue)
{
	if(is_empty(queue))
		return ERROR;

	queue->front = (queue->front + 1) % MAXSIZE;
	return OK;
}

status show_queue(cir_seq_queue *queue)
{
	printf("队列中的所有数据元素为：");
	for(int i=queue->front; i !=queue->rear; )
	{
		printf("%d ", queue->base[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return OK;
}


