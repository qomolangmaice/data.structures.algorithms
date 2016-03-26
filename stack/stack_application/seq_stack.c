/*
 *     File Name: seq_stack.c
 *     Description: sequence stack
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.03.26 13:57:30
 */

status init_stack(seq_stack *stack)
{
	stack->base = (elem_type*)malloc(sizeof(elem_type) * STACK_INIT_SIZE);
	assert(stack->base != NULL);
	stack->top = stack->base;
	stack->stacksize = STACK_INIT_SIZE;
	return OK;
}

status is_empty(seq_stack *stack)
{
	if(stack->top == stack->base)
		return TRUE;
	else
		return FALSE;
}

status is_full(seq_stack *stack)
{
	if(stack->top - stack->base == stack->stacksize)
		return TRUE;
	else
		return FALSE;
}

status push(seq_stack *stack, elem_type val)
{
	if(is_full(stack))
	{
		stack->base = (elem_type*)realloc(stack->base, sizeof(elem_type) * (stack->stacksize + STACKINCREMENT));
		assert(stack->base != NULL);
		stack->top = stack->base + stack->stacksize;
		stack->stacksize += STACKINCREMENT;
	}

	*(stack->top) = val;
	stack->top++;
	return OK;
}

status pop(seq_stack *stack, elem_type *p_val)
{
	if(is_empty(stack))
		return ERROR;

	stack->top--;
	*p_val = *(stack->top);
	return OK;
}

status get_top(seq_stack *stack, elem_type *p_val)
{
	if(is_empty(stack))
		return ERROR;

	*p_val = *(stack->top - 1);
	return OK;
}

int get_length(seq_stack *stack)
{
	return stack->top - stack->base;
}

status show_stack(seq_stack *stack)
{
	elem_type *p = stack->base;
	
	printf("栈中的数据元素为:");
	while(p < stack->top)
	{
 	 	printf("%d ", *p++);
	}
	printf("\n");
	return OK;
}

status destroy_stack(seq_stack *stack)
{
	free(stack->base);
	stack->base = stack->top = NULL;
	stack->stacksize = 0;
	return OK;
}


