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

l_node_s *CreateList_LNode(); // 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量）
Status HeadInsert_LNode(l_node_s *L); // 单链表的多个节点创建并插入（头插法）
Status FootInsert_LNode(l_node_s *L); // 单链表的多个节点创建并插入（尾插法）
l_node_s *GetElem_LNode(l_node_s *L, int i); // 单链表的按序号查找节点
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
	printf("# 4 GetElem_LNode(l_node_s *L, int i)\n");
	printf("# 8 Length_LNode(l_node_s *L)\n");

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
				listcase = CreateList_LNode();
				if(listcase != NULL)
				{
					printf("CreateList successed!\n");
				}
				else
				{
					printf("CreateList false!\n");
				}
				break;

			case '2': // 单链表的多个节点创建并插入（头插法）
				if(HeadInsert_LNode(listcase) == OK)
				{
					printf("HeadInsert successed!\n");
				}
				else
				{
					printf("HeadInsert false!\n");
				}
				break;

			case '3': // 单链表的多个节点创建并插入（尾插法）
				if(FootInsert_LNode(listcase) == OK)
				{
					printf("FootInsert successed!\n");
				}
				else
				{
					printf("FootInsert false!\n");
				}
				break;

			case '4': // 单链表的按序号查找节点
				printf("Please enter i to get element:");
				int i;
				l_node_s *p;
				scanf("%d", &i);
				p = GetElem_LNode(listcase, i);
				getchar();
				if(p != NULL)
				{
					printf("GetElem success! e is %c !\n", p->data);
				}
				else
				{
					printf("GetElem false!\n");
				}
				break;

			case '5': // 单链表的按值查找节点
				break;

			case '6': // 单链表的插入节点
				break;

			case '7': // 单链表的删除节点
				break;

			case '8': // 单链表的求表长
				printf("Length_LNode: %d\n", Length_LNode(listcase));
				break;

			case '9': // 单链表的销毁
				break;
		}

	}

}


/* 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量） */
l_node_s *CreateList_LNode()
{
	l_node_s *head_node;
	head_node = (l_node_s *)malloc(sizeof(l_node_s));
	if(head_node != NULL)
	{
		head_node->next = NULL;
		return head_node;
	}
	else
	{
		return NULL;
	}
}


/* 单链表的多个节点创建并插入（头插法） */
Status HeadInsert_LNode(l_node_s *L)
{
	l_node_s *one_node;
	ElemType e;

	printf("Please enter e, enter \'q\' to end input!\n");
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

	printf("Please enter e, enter \'q\' to end input!\n");
	scanf("%c", &e);
	getchar();

	while(e != 'q')
	{
		one_node = (l_node_s *)malloc(sizeof(l_node_s)); // 创建尾节点
		one_node->data = e;
		one_node->next = NULL;

		l_node_s *end_node_maybe; // 用来存储节点地址
		end_node_maybe = L; // 先将头节点当作是最后一个节点，遍历寻找最后一个节点
		while(end_node_maybe->next != NULL) // 如果不是最后一个节点的话
		{
			end_node_maybe = end_node_maybe->next; // 将下一个节点当作是最后一个节点
		}

		end_node_maybe->next = one_node; // 将此节点地址赋给最后一个节点的指针域

		scanf("%c", &e);
		getchar();
	}

	return OK;
}


/* 单链表的按序号查找节点 */
l_node_s *GetElem_LNode(l_node_s *L, int i) // 传入指针变量即可，找到返回节点地址
{
	l_node_s *p;
	int count;

	if(i >= 1 && i <= Length_LNode(L)) // 位置值合法
	{
		p = L->next;
		if(i == 1)
		{
			return p;
		}
		else
		{
			for(count = 1; count < i; count++)
			{
				p = p->next;
			}
			return p;
		}
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
		while(p->next != NULL)
		{
			count = count + 1;
			p = p->next;
		}
	}

	return count;
}


/* 单链表的销毁 */

