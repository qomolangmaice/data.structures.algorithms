/*
 * File Name: seq_list.c
 * Description: 
 * Author: iczelion
 * Email: qomolangmaice@163.com 
 * Created: 2016.03.05 23:57:36
 */

boolean inc(seq_list *list)
{
	elem_type *newbase = (elem_type *)realloc(list->base, sizeof(elem_type)*(list->capacity+INC_SIZE));
	if(newbase == NULL)
	{
		printf("程序增配空间失败,内存不足.\n");
		return FALSE;
	}
	list->base = newbase;
	list->capacity += INC_SIZE;
	return TRUE;
}
status init_seq_list(seq_list *list)
{
	list->base = (elem_type *)malloc(sizeof(elem_type) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
	return OK;
}

status push_back(seq_list *list, elem_type item)
{
	if(list->size >= list->capacity && !inc(list))
	{
		printf("顺序表空间已满，不能在顺序表尾部插入数据.\n");
		return ERROR;
	}
	list->base[list->size] = item;
	list->size++;
	return OK;
}

status push_front(seq_list *list, elem_type item)
{
	if(list->size >= list->capacity && !inc(list))
	{
		printf("顺序表空间已满，不能在顺序表头部插入数据.\n");
	 	return ERROR;
	}

	for(int count=list->size; count>0; --count)
	{
		list->base[count] = list->base[count-1];
	}
	list->base[0] = item;
	list->size++;
	return OK;
}

status show_list(seq_list *list)
{
	for(int count=0; count < list->size; ++count)
		printf("%d ", list->base[count]);
	printf("\n");
	return OK;
}

status pop_back(seq_list *list)
{
	if(list->size == 0)
	{
		printf("顺序表已空，不能在尾部删除数据.\n");
		return ERROR;
	}
	
	list->size--;
	return OK;
}

status pop_front(seq_list *list)
{
	if(list->size == 0)
	{
		printf("顺序表已空，不能在尾部删除数据.\n");
		return ERROR;
	}

	for(int count=0; count<list->size-1; ++count)
		list->base[count] = list->base[count+1];

	list->size--;
	return OK;
}

status insert_pos(seq_list *list, int pos, elem_type item)
{
	if(pos<0 || pos>list->size)
	{
		printf("待插入的位置不存在, 不能插入数据.\n");
		return ERROR;
	}

	if(list->size >= list->capacity && !inc(list))
	{
		printf("顺序表存储空间已满, %d不能头部插入数据.\n", item);
		return ERROR;
	}

	for(int count=list->size; count>pos; --count)
	 	list->base[count] = list->base[count-1];
	list->base[pos] = item;
	list->size++;
	return OK;
}

status find(seq_list *list, elem_type key)
{
	for(int count=0; count<list->size; ++count)
	{
		if(list->base[count] == key)
			return count;
	}
	return -1;
}

int get_length(seq_list *list)
{
	return list->size;
}

status delete_pos(seq_list *list, int pos)
{
	if(pos<0 || pos>=list->size)
	{
		printf("要删除的数据的位置不存在,不能删除数据.\n");
		return ERROR;
	}

	for(int count=pos; count<list->size; ++count)
		list->base[count] = list->base[count+1];

	list->size--;
	return OK;
}

status delelte_val(seq_list *list, elem_type val)
{
	int pos = find(list, val);
	if(pos == -1)
	{
		printf("要删除的数据不存在.\n");
		return ERROR;
	}
	delete_pos(list, pos);
	return OK;
}

status sort(seq_list *list)
{
	elem_type tmp;
	for(int i=0; i<list->size-1; ++i)
	{
		for(int j=0; j<list->size-i-1; ++j)
	 	{
			if(list->base[j] > list->base[j+1])
			{
				tmp = list->base[j];
				list->base[j] = list->base[j+1];
				list->base[j+1] = tmp;
			}
		}
	}
}

status resver(seq_list *list)
{
	if(list->size == 0 || list->size == 1)
		return ERROR;

	int low = 0;
	int high = list->size - 1;
	elem_type tmp;
	while(low < high)
	{
		tmp = list->base[low];
		list->base[low] = list->base[high];
		list->base[high] = tmp;
		low++;
		high--;
	}
	return OK;
}

status clear(seq_list *list)
{
	list->size = 0;
	return OK;
}

status destroy(seq_list *list)
{
	free(list->base);
	list->base = NULL;
	list->capacity = 0;
	list->size = 0;
	return OK;
}
/*
status merge_list(seq_list *lc, seq_list *la, seq_list *lb)
{
  	lc->capacity = la->size + lb->size;
	lc->base = (elem_type *)malloc(sizeof(elem_type) * lc->capacity);
	assert(lc->base != NULL);	

	int ia = 0;
	int ib = 0;
	int ic = 0;

	while(ia < la->size && ib < lb->size)
	{
		if(la->size[ia] < lb->size[ib])
		{
	 	 	lc->base[ic++] = la->size[ia++];
	 	}
		else
		{
			lc->base[ic++] = lb->size[ib++];
	 	}
	}

	while(ia < la->size)
	{
		lc->size[ic++] = la->size[ia++];
	}

	while(ib < lb->size)
	{
		lc->size[ic++] = lb->size[ib++];
	}

	lc->size = la->size + lb->size;
	return OK;
}
*/

