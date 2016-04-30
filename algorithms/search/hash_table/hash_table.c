/*
 *  File Name: hash_table.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.30 22:58:38
 */

void init_hash_table(hash_table ht)
{
	for(int i=0; i < prime; ++i)
	{
		ht[i] = NULL;
	}
}

int hash(elem_type key)
{
	return key % prime;
}

/* 除留余数法创建哈希表 */
/* 使用链地址法避免哈希表数组下边冲突 */
void insert_hash_table(hash_table ht, elem_type value)
{
	/* 求哈希表数组下标 */
	int index = hash(value);

	hash_node *s = (hash_node*)malloc(sizeof(hash_node));
	assert(s != NULL);
	s->data = value;

	/* 头插法插入数据到哈希表中 */
	s->link = ht[index];
	ht[index] = s;
}

void show_hash_table(hash_table ht)
{
 	for(int i=0; i < prime; ++i)
	{
		printf("%2d : ", i);
		hash_node *p = ht[i];

		while(p != NULL)
		{
			printf("%d-->", p->data);
			p = p->link;
		}
		printf("Nul. \n");
	}
}

hash_node* search_hash_table(hash_table ht, elem_type key)
{
	int index = hash(key);
	hash_node *p = ht[index];

	while(p != NULL && p->data != key)
		p = p->link;
	return p;
}

boolean delete_hash_table(hash_table ht, elem_type key)
{
	hash_node *p = search_hash_table(ht, key);
	if(p == NULL)
		return FALSE;

	int index = hash(key);
	hash_node *prior = ht[index];

	/* 若链表中只存在一个数据元素 */
	if(prior == p)
	{
		ht[index] = p->link;
		free(p);
		return TRUE;
	}

	/* 若链表中的数据元素个数大于1 */
	while(prior->link != p)
		prior = prior->link;
	prior->link = p->link;
	free(p);

	return TRUE;
}













