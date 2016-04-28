/*
 *     File Name: link_stack.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 16:31:23
 */

status init_stack(link_stack *stack)
{
	*stack = NULL;
	return OK;
}

status push(link_stack *stack, s_elem_type val)
{
	stack_node *t = (stack_node*)malloc(sizeof(stack_node));
	assert(t != NULL);
	t->data = val;

	if(*stack == NULL)
	{
		*stack = t;
		t->next = NULL;
	}
	else
	{
		t->next = *stack;
		*stack = t;
	}
	return OK;
}

status show_stack(link_stack *stack)
{
 	stack_node *p = *stack; 
	printf("链栈中的数据元素为:\n");
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//status pop(link_stack *stack, s_elem_type *p_val)
status pop(link_stack *stack)
{
	stack_node *p = *stack;
 	//*p_val = p->data;

	*stack = p->next;
	free(p);
	p = NULL;
	return OK;
}

status stack_is_empty(link_stack *stack)
{
	return *stack == NULL;
}

s_elem_type get_stack_top(link_stack *stack)
{
	stack_node *p = *stack;
	assert(p != NULL);
	return p->data;
}

