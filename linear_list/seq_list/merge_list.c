/*
 * File Name: merge_list.c
 * Description: 
 * Author: iczelion
 * Email: qomolangmaice@163.com 
 * Created: 2016.03.07 21:42:10
 */

#include "seq_list.h"
#include "seq_list.c"

void main()
{
	seq_list la, lb, lc;
	init_seq_list(&la);
	init_seq_list(&lb);

	push_back(&la, 1);
	push_back(&la, 3);
	push_back(&la, 5);
	push_back(&la, 7);
	push_back(&la, 9);

	push_back(&la, 2);
	push_back(&la, 4);
	push_back(&la, 6);
	push_back(&la, 8);
	push_back(&la, 10);

	merge_list(&lc, &la, &lb);
	show_list(&lc);
}
