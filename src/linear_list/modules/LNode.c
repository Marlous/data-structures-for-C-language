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

Status CreateList_LNode(l_node_s *L); // 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量）
Status HeadInsert_LNode(l_node_s *L); // 单链表的多个节点创建并插入（头插法）
Status FootInsert_LNode(l_node_s *L); // 单链表的多个节点创建并插入（尾插法）
l_node_s *GetElem_LNode(l_node_s *L, int i);
int Length_LNode(l_node_s *L);


/*
 * Main function
 */
Status LNode(void)
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
	printf("# 2 HeadInsert(l_node_s *L)\n");
	printf("# 3 FootInsert(l_node_s *L)\n");



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
				if(CreateList_LNode(listcase) == OK)
				{
					printf("CreateList successed!");
				}
				else
				{
					printf("CreateList false!");
				}
				break;

			case '2': // 单链表的多个节点创建并插入（头插法）
				if(HeadInsert_LNode(listcase) == OK)
				{
					printf("HeadInsert successed!");
				}
				else
				{
					printf("HeadInsert false!");
				}
				break;

			case '3': // 单链表的多个节点创建并插入（尾插法）
				if(FootInsert_LNode(listcase) == OK)
				{
					printf("FootInsert successed!");
				}
				else
				{
					printf("FootInsert false!");
				}
				break;

			case '4': // 单链表的按序号查找节点
				break;

			case '5': // 单链表的按值查找节点
				break;

			case '6': // 单链表的插入节点
				break;

			case '7': // 单链表的删除节点
				break;

			case '8': // 单链表的求表长
				break;

			case '9': // 单链表的销毁
				break;
		}

	}

}


/* 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量） */
Status CreateList_LNode(l_node_s *L)
{
	l_node_s *head_node;
	head_node = (l_node_s *)malloc(sizeof(l_node_s));
	L = head_node;
	if(L != NULL)
	{
		L->next = NULL;
		return OK;
	}
	else
	{
		return ERROR;
	}
}


/* 单链表的多个节点创建并插入（头插法） */
Status HeadInsert_LNode(l_node_s *L)
{
	l_node_s *one_node;
	ElemType e;

	printf("Please enter e, enter \'q\' to end input!");
	scanf("%c", &e);
	getchar();

	while(e != 'q')
	{
		one_node = (l_node_s *)malloc(sizeof(l_node_s));
		one_node->data = e;
		one_node->next = L->next; // 将头节点的 next 域赋给往头节点后面插入的节点
		L->next = one_node; // 将插入节点的地址赋给头节点的 next 域

		scanf("%c", &e);
		getchar();
	}

	return OK;
}


/* 单链表的多个节点创建并插入（尾插法） */
Status FootInsert_LNode(l_node_s *L)
{
	l_node_s *one_node;
	ElemType e;

	printf("Please enter e, enter \'q\' to end input!");
	scanf("%c", &e);
	getchar();

	while(e != 'q')
	{
		one_node = (l_node_s *)malloc(sizeof(l_node_s));
		one_node->data = e;
		one_node->next = NULL;

		l_node_s *end_node;
		end_node = L; // 先将头节点当作是最后一个节点
		while(end_node->next != NULL) // 如果不是最后一个节点的话
		{
			end_node = end_node->next; // 将下一个节点当作是最后一个节点
		}

		end_node->next = one_node; // 将此节点地址赋给最后一个节点的指针域

		scanf("%c", &e);
		getchar();
	}

	return OK;
}


/* 单链表的按序号查找节点 */
l_node_s *GetElem_LNode(l_node_s *L, int i) // 传入指针变量即可，找到返回节点地址
{
	l_node_s *p;
	int j;

	if(i >= 1 && i <= Length_LNode(L)) // 位置值合法
	{
		for(j = 1; j <= i; j++)
			{
				if(j == 1)
				{
					p = L->next;
				}
				if(p->next != NULL)
				{
					p = p->next;
				}
			}
		return p;
	}
	else // 位置值不合法
	{
		return NULL;
	}
}


/* 单链表的按值查找节点 */




/* 单链表的插入节点 */



/* 单链表的删除节点 */



/* 单链表的求表长 */
int Length_LNode(l_node_s *L)
{
	l_node_s *p;
	int count = 0;

	if(L->next != NULL)
	{
		count = 1;
		p = L->next;
	}
	while(p->next != NULL)
	{
		count = count + 1;
		p = L->next;
	}

	return count;
}


/* 单链表的销毁 */

