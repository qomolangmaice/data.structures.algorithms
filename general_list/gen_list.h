/*
 *  File Name: gen_list.h
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.04 16:49:48
 */
#ifndef __GEN_LIST__
#define __GEN_LIST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int atom_type; 
typedef int status;

typedef enum {
	head, atom, child_list
} elem_tag;

typedef struct gl_node{ /* General list node */
	elem_tag tag;
	union {
		atom_type atom;
		struct gl_node *head_p; /* general list head pointer */
	};
	struct gl_node *tail_p; /* general list tail pointer */
} gl_node;

typedef gl_node* gen_list;

status init_gen_list(gen_list &gl); 	/* gl is a reference in this C++ project */
status create_gen_list(gen_list &gl, char *str);
status sever(char *sub, char *head_sub);
status show_gen_list(gen_list &gl);
status gen_list_empty(gen_list &gl);
int gen_list_length(gen_list &gl);
int gen_list_deepth(gen_list &gl);

#endif

