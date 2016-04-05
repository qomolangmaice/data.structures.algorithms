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

status create_gen_list(gen_list &gl, char *str)
{
 	int n = strlen(str);
	char *sub = (char*)malloc(sizeof(char) * (n - 2));
	char *head_sub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && head_sub != NULL);

	/* sub = "1, 2, 3" */
	strncpy(sub, str+1, n-2);
	sub[n - 2] = '\0';

	/* Create head node */
	if(gl == NULL)
	{
		gl = (gl_node*)malloc(sizeof(gl_node));
		assert(gl != NULL);
		gl->tag = head;
		gl->head_p = gl->tail_p = NULL;
	}

	/* Create general list */
	gl_node *p = gl;
	while(strlen(sub) != 0)
	{
		p = p->tail_p = (gl_node*)malloc(sizeof(gl_node));
		assert(p != NULL);
		p->head_p = p->tail_p = NULL;

		/* 1, 2, 3 ==> head_sub = "1", sub = "2, 3" */
		/* (1, 2), 3, 4 ==> head_sub = "(1, 2)", sub = "3, 4" */
		/* Separate sub string and head_sub string */
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
/* Separate sub string and head_sub string */
status sever(char *sub, char *head_sub)
{
	if(*sub == '\0' || strcmp(sub, "()") == 0)
	{
		head_sub[0] = '\0';
		return true;
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
	return true;
}

status show_gen_list(gen_list &gl)
{
 	gl_node *p = gl->head_p;
	printf("(");
	while(p != NULL)
	{
		if(p->tag == atom)
		{
			printf("%d", p->atom);
			if(p->tail_p != NULL)
				printf(",");
			p = p->tail_p;
		}
		else if(p->tag == child_list)
		{
			show_gen_list(p->head_p);
			p = p->tail_p;
		}
	}
	printf("),");
}

status gen_list_empty(gen_list &gl)
{
	return gl->tail_p == NULL;
}

int gen_list_length(gen_list &gl)
{
	int length = 0;
	gl_node *p = gl->tail_p;
	while(p != NULL)
	{
		length++;
		p = p->tail_p;
	}
	return length;
}

int gen_list_deepth(gen_list &gl)
{
 	if(gl->tail_p == NULL)
		return 1;
	gl_node *p = gl->tail_p;
	int maxdeepth = 0;

	int dep;
	while(p != NULL)
	{
		if(p->tag == child_list)
		{
			dep = gen_list_deepth(p->head_p->tail_p);
			if(dep > maxdeepth)
				maxdeepth = dep;
		}
		p = p->tail_p;
	}
	return maxdeepth + 1;
}










