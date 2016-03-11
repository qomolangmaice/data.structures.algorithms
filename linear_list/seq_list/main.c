/*
 * File Name: test_seq_list.c
 * Description: 
 * Author: iczelion
 * Email: qomolangmaice@163.com 
 * Created: 2016.03.05 23:34:17
 */

#include "seq_list.h"
#include "seq_list.c"

void main()
{
	seq_list mylist; 
	init_seq_list(&mylist);

	elem_type item;
	int pos;
	int select = 1;

	while(select)
	{
		printf("*************************************************\n");
		printf("*   [1] push_back 	[2] push_front    	*\n");
		printf("*   [3] show_list 	[4] pop_back 	  	*\n");
		printf("*   [5] pop_front 	[6] insert_pos    	*\n");
		printf("*   [7] find 	 	[8] get_length 	   	*\n");
		printf("*   [9] delete_pos 	[10] delelte_val  	*\n");
		printf("*   [11] sort 	 	[12] resver 	 	*\n");
		printf("*   [13] clear  	[14*] destroy      	*\n");
		printf("*   [0] quit_system  	 	 		*\n");
		printf("*************************************************\n");
		printf("请选择:> ");

		scanf("%d", &select);

		if(select == 0)
			break;

		switch(select)
		{
			case 1:
				printf("请输入要插入的数据(尾插法, -1结束):>");
				while(scanf("%d", &item), item != -1) 	/* while( , ) 逗号表达式 */
				{
	 	 	 	 	push_back(&mylist, item);
				}
				break;
			case 2:
				printf("请输入要插入的数据(头插法, -1结束):>");
	 	 	 	while(scanf("%d", &item), item != -1) 	/* while( , ) 逗号表达式 */
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
			case 6:
				printf("请输入要插入的数据:>");
				scanf("%d", &item);
				printf("请输入要插入的位置:>");
				scanf("%d", &pos);
				insert_pos(&mylist, pos, item);
				break;
			case 7:
				printf("请输入要查找的数据:>");
				scanf("%d", &item);
				pos = find(&mylist, item);
				if(pos == -1)
					printf("查找的数据%d在顺序表中不存在.\n", item);
				else
					printf("查找的数据%d在顺序表中的下标位置为%d.\n", item, pos);
				break;
			case 8:
				printf("顺序表的长度为:>%d\n.", get_length(&mylist));
				break;
			case 9:
				printf("请输入要删除数据的位置:>");
				scanf("%d", &pos);
				delete_pos(&mylist, pos);
				break;
			case 10:
				printf("请输入要删除的数据:>");
				scanf("%d", &item);
				delelte_val(&mylist, item);
				break;
			case 11:
				sort(&mylist);
				break;
			case 12:
				resver(&mylist);
				break;
			case 13:
				clear(&mylist);
				break;
			default:
				printf("输入的选择错误，请重新输入.\n\n");
				break;
		}
	}
	destroy(&mylist);
}
