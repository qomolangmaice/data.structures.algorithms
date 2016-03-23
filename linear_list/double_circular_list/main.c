/*
* File Name: main.c
* Description: 
* Author: iczelion
* Email: qomolangmaice@163.com 
* Created: 2016.03.22 20:58:34
*/

#include "double_circular_list.h"
#include "double_circular_list.c"

void main()
{
	dou_cir_list mylist;
	init_list(&mylist);

	int select = 1;
	elem_type item;
	node *p = NULL;
	while(select)
	{
		printf("*************************************************\n");
		printf("*  [1] push_back	 [2] push_front 	*\n");
		printf("*  [3] show_list	 [4] pop_back    	*\n");
		printf("*  [5] pop_front	 [6] insert_val 	*\n");
		printf("*  [7] find 	 	 [8] get_length 	*\n");
		printf("*  [9] delete_val	 [10] sort   	 	*\n");
		printf("*  [11] resever		 [12] clear 	 	*\n");
		printf("*  [13*] destroy	 [0] quit_system 	*\n");
		printf("*  [14] prior_node 	 [15] next_node 	*\n");
		printf("*************************************************\n");

		printf("请选择操作选项:> ");
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
				/*
			case 5:
				pop_front(&mylist);
				break;
			case 6:
				printf("请输入要插入的数据:>");
				scanf("%d", &item);
				insert_val(&mylist, item);
				break;
			case 7:
				printf("请输入要查找的数据:>");
				scanf("%d", &item);
				p = find(&mylist, item);
				printf("在双向链表查找到数据: %d\n", p->data);
				if (p == NULL)
				{
					printf("要查找的数据在双向链表中不存在.");
				}
				break;
			case 8:
				printf("双向链表的长度为: %d\n", get_length(&mylist));
				break;
			case 9:
				printf("请输入要删除的值:> ");
				scanf("%d", &item);
				delete_val(&mylist, item);
				break;
			case 10:
				sort(&mylist);
				break;
			case 11:
				resver(&mylist);
				break;
			case 12:
				clear(&mylist);
				break;
			case 14:
				printf("请输入要查找的数据:>");
				scanf("%d", &item);
				p = prior_node(&mylist, item);
				if (p == NULL || p == (&mylist)->head)
				{
					printf("要查找的数据在双向链表中不存在前驱.\n");
				}
				else
				{
			 	 	printf("要查找的数据在双向链表中的前驱为:%d.\n", p->data);	
				}
				break;
 	 	 	case 15:
				printf("请输入要查找的数据:>");
				scanf("%d", &item);
				p = next_node(&mylist, item);
				if (p == NULL)
				{
					printf("要查找的数据在双向链表中不存在后继.\n");
				}
				else
				{
			 	 	printf("要查找的数据在双向链表中的后继为:%d.\n", p->data);	
				}
				break;
 	 	 	*/
			default:
				printf("输入的选择有误，请重新输入.\n");
				break;
		}
	}
	//destroy(&mylist);
}
