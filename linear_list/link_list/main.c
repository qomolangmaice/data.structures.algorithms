/*
* File Name: main.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.10 21:42:40
*/

#include "link_list.h"
#include "link_list.c"

void main()
{
	link_list mylist;

	init_list(&mylist);

	int select = 1;
	elem_type item;
	while(select)
	{
		printf("*************************************************\n");
		printf("*  [1] push_back	 [2] push_front 	*\n");
		printf("*  [3] show_list	 [4] pop_back    	*\n");
		printf("*  [5] pop_front	 [6] insert_val 	*\n");
		printf("*  [7] find 	 	 [8] get_length 	*\n");
		printf("*  [9] delete_val	 [10] sort   	 	*\n");
		printf("*  [11] resever		 [12] clear 	 	*\n");
		printf("*  [13] destroy		 [0] quit_system 	*\n");
		printf("*************************************************\n");

		printf("请选择:> ");
		scanf("%d", &select);

		if(select == 0)
			break;

		switch(select)
		{
			case 1:
				printf("请输入要插入的数据(-1结束):>");
				while(scanf("%d", &item), item != -1)
				{
					push_back(&mylist, item);
				}
				break;
			case 2:
				printf("请输入要插入的数据(头插法, -1结束);>");
				while(scanf("%d", &item), item != -1)
				{
					push_front(&mylist, item);
				}
				break;
			case 3:
				show_list(&mylist);
				break;
			case 4:
				pop_back(&mylist);
				break;
			case 5:
				pop_front(&mylist);
				break;
			default:
				printf("输入的选择有误，请重新输入.\n");
				break;
		}
	}
}
