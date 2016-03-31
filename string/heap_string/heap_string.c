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
