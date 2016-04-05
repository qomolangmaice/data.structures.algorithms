/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.04 16:49:58
 */

#include "gen_list.h"
#include "gen_list.c"

//int main(int argc, char **argv)
int main()
{
	gen_list gl;
	init_gen_list(gl);

	char *ga = "(1,2,3)";
	char *gb = "(1,(2,3))";
	char *gc = "(1,(2),3)";
	char *gd = "((1,2),3)";
	char *ge = "((1,2,3))";
	char *gf = "()";
	char *gg = "(1,(2,(3,4)),5)";
	create_gen_list(gl, gd);
	show_gen_list(gl);
	int length = gen_list_length(gl);
	printf("%d", length);

	int depth = gen_list_deepth(gl);
	printf("deepth = %d\n", depth);
}
