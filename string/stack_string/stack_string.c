/*
 *  File Name: stack_string.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.03.29 20:00:50
 */

status init_string(stack_string str)
{
	str[0] = '\0';
	return OK;
}

status str_assign(stack_string s, char *string)
{
	int len = strlen(string);
	for(int i=0; i<len; ++i)
		s[i] = string[i];
	s[len] = '\0';
	return OK;
}

status print_string(stack_string s)
{
	printf("%s\n", s);
	return OK;
}

status str_copy(stack_string s, stack_string t)
{
	int len = str_length(s);
	for(int i=0; i<len; ++i)
		t[i] = s[i];
	t[len] = '\0';
	return OK;
}

status str_empty(stack_string s)
{
	return s[0] == '\0';
}

unsigned int str_compare(stack_string s, stack_string t)
{
	unsigned int result = 0;
 	while(*s != '\0' || *t != '\0')
	{
		result = *s - *t;
		if(result != 0)
			break;
		s++;
		t++;
	}

	if(result > 0)
		result = 1;
	else if(result < 0)
		result = -1;
	return result;
}

int str_length(stack_string s)
{
 	int len = 0; 
	while(*s != '\0')
	{
		len++;
		s++;
	}
	return len;
}










