/*
 *  File Name: main.c
 *  Description: 
 *  Author: iczelion
 *  Email: qomolangmaice@163.com 
 *  Created: 2016.04.24 19:02:15
 */

#include "seq_search_and_bin_search.h"
#include "seq_search_and_bin_search.c"

void main()
{
	seq_table st;

	init_seq_table(&st);

	create_seq_table(&st);

	show_seq_table(&st);

	sequential_search(&st, 3);

	binary_search(&st, 2);
	//sequential_search(&st, 6);
	//
	destroy_seq_table(&st);
}
