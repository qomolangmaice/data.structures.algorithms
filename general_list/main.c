/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.04 16:49:58
 */

#include "gen_list.h"
#include "gen_list.c"

int main(int argc, char **argv)
{
	gen_list gl;
	init_gen_list(gl);

	const char *ga = "(1,2,3)";
	const char *gb = "(1,(2,3))";
	const char *gc = "(1,(2),3)";
	const char *gd = "(1,2),3)";
	const char *ge = "((1,2,3))";
	const char *gf = "()";
	const char *gg = "(1,(2,(3,4)),5)";
	create_gen_list(gl, gd);
}
