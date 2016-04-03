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

status str_concat(stack_string t, stack_string s1, stack_string s2)
{
	int len1 = str_length(s1);
	int len2 = str_length(s2);
	int i,j;

	if(len1 + len2 <= MAXSTRLEN)
	{
		for(i=0; i<len1; ++i)
			t[i] = s1[i];
		for(j=0; j<len2; ++j)
			t[i+j] = s2[j];
		t[len1 + len2] = '\0';
	}
	else if(len1 < MAXSTRLEN)
	{
		for(i=0; i<len1; ++i)
			t[i] = s1[i];
		for(j=0; j<MAXSTRLEN-len1; ++j)
			t[i + j] = s2[j];
		t[MAXSTRLEN] = '\0';
	}
	else
	{
		for(i=0; i<len1; ++i)
			t[i] = s1[i];
		t[MAXSTRLEN] = '\0';
	}
	return OK;
}

status sub_string(stack_string s, stack_string sub, int pos, int len)
{
	int s_len = str_length(s);
	if(pos<0 || pos>=s_len || len<0 || len>s_len)
		return ERROR;
	for(int i=0; i<len; ++i)
		sub[i] = s[pos+i];
	sub[len] = '\0';
	return OK;
}

status str_insert(stack_string s, int pos, stack_string t)
{
	int s_len = str_length(s);
	int t_len = str_length(t);

	if(s_len + t_len <= MAXSTRLEN)
	{
		for(int i=s_len-1; i>=pos; --i)
			s[i+t_len] = s[i];
		for(int i=0; i<t_len; ++i)
			s[pos+i] = t[i];
		s[s_len+t_len] = '\0';
	}
	else if(s_len < MAXSTRLEN)
	{
		t_len = MAXSTRLEN - s_len;
		for(int i=s_len-1; i>=pos; --i)
			s[i+t_len] = s[i];
		for(int i=0; i<t_len; ++i)
			s[pos+i] = t[i];
		s[s_len+t_len] = '\0';
	}
	return OK;
}

status str_delete(stack_string s, int pos, int len)
{
	int s_len = str_length(s);
	for(int i=pos; i<s_len; ++i)
		s[i] = s[i+len];
	s[s_len - len] = '\0';
	return OK;
}

status str_clear(stack_string s)
{
	s[0] = '\0';
	return OK;
}

status str_index(stack_string s, stack_string t, int pos)
{
	int i = pos; 
	int j = 0;
	while(s[i] != '\0' && t[j] != '\0')
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(t[j] == '\0')
		return i - j;
	return -1;
}

status str_replace(stack_string s, stack_string t, stack_string v)
{
	int s_len = str_length(s);
	int t_len = str_length(t);
	int v_len = str_length(v);

	int index = -1;
	int pos = 0;

	while(pos < s_len)
	{
		index = str_index(s, t, pos);
		if(index == -1)
			return ERROR;
		str_delete(s, index, t_len);
		str_insert(s, index, v);
		
		pos = index + v_len;
	}
	return OK;
}







