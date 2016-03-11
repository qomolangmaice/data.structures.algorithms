/*
* File Name: link_list.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:42:35
*/

status init_list(link_list *head)
{
	*head = NULL;
	return OK;
}

status create_list(link_list *head)
{
	/* create the head joint in link_list and initialize it */
	*head = (list_node *)malloc(sizeof(list_node));
	(*head)->data = 1;
	(*head)->next = NULL;

	list_node *p = *head;
	for (int i=2; i<10; ++i)
	{
		/* create the next link_list joint and initialize it */
		list_node *s = (list_node *)malloc(sizeof(list_node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
	return OK;
}

status show_list(link_list head)
{
	list_node *p = head;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Nil.\n");
	return OK;
}
