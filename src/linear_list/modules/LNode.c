/*
 * linear_list.c
 *
 *  Created on: 2019/5/04
 *      Author: Mo
 */


#include "common.h"
#include "linear_list_modules.h"
#include "linear_list.h"


Status DisplayLNodeMenu(void);
Status LNodeMenuSelect(void);

l_node_s *CreateList();


/*
 * Main function
 */
Status SqListSeqList(void)
{
	system("cls");
	DisplayLNodeMenu();
	LNodeMenuSelect();

	return OK;
}


/*
 * Sub function
 */
Status DisplayLNodeMenu(void)
{
	printf("# LNode #\n");
	printf("# 1 CreateList()\n");

	printf("# b Back!\n");
	printf("# q Exit!\n");

	return OK;
}


Status LNodeMenuSelect(void)
{
	l_node_s *listcase; // 定义一个单链表类型的指针变量 listcase，注意，在之后指向头节点地址才表示该单链表存在
	listcase = NULL; // 暂时设置此单链表还未被创建（还没指向头节点）

	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c", &selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1': // 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量）
				listcase = CreateList();
				if(listcase != NULL)
				{
					printf("CreateList successed!");
				}
				else
				{
					printf("CreateList false!");
				}
				break;

			case '2': // 单链表的某个节点创建并插入（头插法）
				break;

			case '3': // 单链表的某个节点创建并插入（尾插法）
				break;

			case '4': // 单链表的某个节点创建并插入到指定位置
				break;

			case '5': // 单链表的销毁
				if(DestroyList(&listcase) == OK)
				{
					printf("DestroyList successes!\n");
				}
				else
				{
					printf("DestroyList false!\n");
				}
				break;
		}

	}

}


/* 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量） */
l_node_s *CreateList()
{
	l_node_s *node;
	node = (l_node_s *)malloc(sizeof(l_node_s));
	if(node != NULL)
	{
		node->next = NULL;
	}

	return node; // 返回存放头节点地址的指针变量
}


/* 单链表的销毁 */
Status DestroyList(l_node_s *L)
{
	循环从前到后释放掉每个节点

	free(*L);  // 单链表类型的指针变量 listcase 释放掉（传入的是 listcase 指针变量的地址）。


	return OK;
}
