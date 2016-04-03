/*
 *  File Name: heap_string.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.03.31 21:07:02
 */

status init_string(heap_string *s)
{
	s->ch = NULL;
	s->length = 0;
	return OK;
}

status print_string(heap_string *s)
{
	for(int i=0; i<s->length; ++i)
		printf("%c", s->ch[i]);
	printf("\n");
	return OK;
}

status str_assign(heap_string *s, char *str)
{
	int len = strlen(str);
	if(s->ch != NULL)
		free(s->ch);
	s->ch = (char*)malloc(sizeof(char) * len);
	assert(s->ch != NULL);
	for(int i=0; i<len; i++)
		s->ch[i] = str[i];
	s->length = len;
	return OK;
}

int str_length(heap_string *s)
{
	return s->length;
}

status str_copy(heap_string *s, heap_string *t)
{
	int len = str_length(t);
	if(s->ch != NULL)
		free(s->ch);
 	s->ch = (char *)malloc(sizeof(char) * len);
	assert(s->ch != NULL);
	for(int i=0; i<len; ++i)
		s->ch[i] = t->ch[i];
	s->length = len;
}

status is_empty(heap_string *s)
{
	return s->length == 0;
}

status str_compare(heap_string *s, heap_string *t)
{
	if(s->length == 0 || t->length == 0)
		return ERROR;

	int result = 0;
	int i = 0;
	int j = 0;
	while(i<s->length && j<t->length)
	{
		if(s->ch[i] > t->ch[i])
			return 1;
		else if(s->ch[i] < t->ch[i])
			return -1;
		else
		{
			i++;
			j++;
		}
	}

	if(i < s->length)
		result = 1;
	if(j < t->length)
		result = -1;
	return result;
}

status str_concat(heap_string *s, heap_string *s1, heap_string *s2)
{
	if(s->ch != NULL)
		return ERROR;
	int len1 = str_length(s1);
	int len2 = str_length(s2);

	s->ch = (char*)malloc(sizeof(char) * (len1 + len2));
	assert(s->ch != NULL);
	int i = 0;
	int j = 0;
	for(i=0; i<len1; ++i)
		s->ch[i] = s1->ch[i];
	for(j=0; j<len2; ++j)
		s->ch[i+j] = s2->ch[j]; 
	s->length = len1 + len2;
	return OK;
}

status sub_string(heap_string *s, heap_string *sub, int pos, int len)
{
	if(pos < 0 || pos > s->length || len < 0 || len > s->length - pos)
		return ERROR;
	if(sub->ch != NULL)
		free(sub->ch);

	sub->ch = (char*)malloc(sizeof(char) * len);
	assert(sub->ch != NULL);
	for(int i=0; i<len; ++i)
		sub->ch[i] = s->ch[pos + i];
	sub->length = len;
	return OK;
}

status str_insert(heap_string *s, int pos, heap_string *t)
{
	if(t->length == 0)
		return ERROR;
	if(pos < 0 || pos > s->length)
		return ERROR;
	char *ch = (char*)realloc(s->ch, sizeof(char) * (s->length + t->length));
	assert(ch != NULL);
	s->ch = ch;

	for(int i=s->length-1; i>=pos; --i)
		s->ch[i + t->length + 1] = s->ch[i];
	for(int i=0; i<t->length; ++i)
		s->ch[pos+i] = t->ch[i];
	s->length += t->length;
	return OK;
}

status str_clear(heap_string *s)
{
	s->length = 0;
	if(s->ch != NULL)
		free(s->ch);
	s->ch = NULL;
	return OK;
}

status str_delete(heap_string *s, int pos, int len)
{
	if(pos < 0 || pos > s->length)
		return ERROR;

	if(len <= 0 || len > s->length)
		return ERROR;
	for(int i=0; i<len; ++i)
		s->ch[pos + i] = s->ch[pos + len];
	s->length -= len;
	return OK;
}


