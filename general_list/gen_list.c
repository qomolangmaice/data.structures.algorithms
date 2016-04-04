/*
 *  File Name: gen_list.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.04 16:49:41
 */

status init_gen_list(gen_list &gl)
{
	gl = NULL;
	return OK;
}

status create_gen_list(gen_list &gl, const char *str)
{
 	int n = strlen(str);
	char *sub = (char*)malloc(sizeof(char) * (n - 2));
	char *head_sub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && head_sub != NULL);

	/* sub = "1, 2, 3" */
	strncpy(sub, str+1, n-2);
	sub[n - 2] = '\0';

	if(gl == NULL)
	{
		gl = (gl_node*)malloc(sizeof(gl_node));
		assert(gl != NULL);
		gl->tag = head;
		gl->head_p = gl->tail_p = NULL;
	}

	gl_node *p = gl;
	while(strlen(sub) != 0)
	{
		p = p->head_p = (gl_node*)malloc(sizeof(gl_node));
		assert(p != NULL);
		p->head_p = p->tail_p = NULL;

		/* 1, 2, 3 ==> head_sub = "1", sub = "2, 3" */
		/* (1, 2), 3, 4 ==> head_sub = "(1, 2)", sub = "3, 4" */
		if(sever(sub, head_sub))
		{
			if(head_sub[0] == '(')
			{
				p->tag = child_list;
				create_gen_list(p->head_p, head_sub);
			}
			else
			{
				p->tag = atom;
				p->atom = atoi(head_sub);
			}
		}
	}
}

/* 1, 2, 3 ==> head_sub = "1", sub = "2, 3" */
/* (1, 2), 3, 4 ==> head_sub = "(1, 2)", sub = "3, 4" */
/* (1, 2) ==> head_sub = "(1, 2)", sub = "" */
status sever(char *sub, char *head_sub)
{
	if(*sub == '\0' || strcmp(sub, "()") == 0)
	{
		head_sub[0] = '\0';
		return TRUE;
	}

	int n = strlen(sub);
	int i = 0;
	char ch = sub[0];
	int k = 0;
	while(i<n && (ch != ',' || k != 0))
	{
		if(ch == '(')
			k++;
		else if(ch == ')')
			k--;
		i++;
		ch = sub[i];
	}

	if(i < n)
	{
		sub[i] = '\0';
		strcpy(head_sub, sub);
		strcpy(sub, sub + i + 1);
	}
	else if(k != 0)
	{
		strcpy(head_sub, sub);
		sub[0] = '\0';
	}
	return TRUE;
}












