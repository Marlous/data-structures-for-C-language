/*
 * SqList_SeqList.c
 *
 *  Created on: 2019/3/20
 *      Author: Mo
 */


#include "common.h"
#include "linear_list_modules.h"
#include "linear_list.h"


Status DisplaySqListSeqListMenu(void);
Status SqListSeqListMenuSelect(void);


Status InitList(seq_list_s *L);
Status DestroyList(seq_list_s *L);
Status ListInsert(seq_list_s *L, int i, ElemType e);


/*
 * Main function
 */
Status SqListSeqList(void)
{
	system("cls");
	DisplaySqListSeqListMenu();
	SqListSeqListMenuSelect();

	return OK;
}


/*
 * Sub function
 */
Status DisplaySqListSeqListMenu(void)
{
	printf("# SqList and SeqList #\n");
	printf("# 1 InitList(&L)\n");
	printf("# 2 DestroyList(&L)\n");
	printf("# 3 ListInsert(&L, i, e)\n");
	printf("# 4 ListDelete(&L, i, &e)\n");
	printf("# 5 LocateElem(L, e)\n");
	printf("# 6 GetElem(L, i)\n");
	printf("# 7 Length(L)\n");
	printf("# 8 Empty(L)\n");
	printf("# 9 PrintList(L)\n");
	printf("# b Back!\n");
	printf("# q Exit!\n");

	return OK;
}


Status SqListSeqListMenuSelect(void)
{
	seq_list_s listcase; // 定义一个顺序表类型的变量 listcase
	listcase.data = NULL; // 先初始化为 NULL，表示还没进行任何操作，顺序表实例还不存在

	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c", &selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1': // 初始化顺序表
				if(InitList(&listcase) == OK)
				{
					printf("InitList successes!\n");
				}
				else
				{
					printf("InitList false!\n");
				}
				break;

			case '2': // 销毁顺序表
				if(DestroyList(&listcase) == OK)
				{
					printf("DestroyList successes!\n");
				}
				else
				{
					printf("DestroyList false!\n");
				}
				break;

			case '3': // 顺序表的插入。插入一次只插入一个元素，依次添加进顺序表
				printf("Please enter i and e to insert:");
				int i;
				ElemType e;
				scanf("%d %c", &i, &e);
				getchar();
				if(ListInsert(&listcase, i, e) == OK)
				{
					printf("ListInsert successes!\n");
				}
				else
				{
					printf("ListInsert false!\n");
				}
				break;

			case 'b':
				LinearList();
				break;

			case 'q':
				system("cls");
				exit(0);
				break;

			default:
				printf("ERROR!\n");
				break;
		}
	}
	return OK;
}


/* 顺序表的初始化 */
Status InitList(seq_list_s *L) // 接收一个定义好的变量的地址（实参是变量的地址，形参是指针变量）
{
	L->data = NULL; // 先将成员体变量 data 初始化。这里 L 前的星号表示引用实参 listcase 变量
	L->data = (ElemType *)malloc(SEQLIST_INIT_SIZE * sizeof(ElemType)); // 申请 SEQLIST_INIT_SIZE 个数的  ElemType 类型长度的空间，将指针变量（地址值）赋给 SeqList 类型的变量的成员变量（指针变量）*data

	if(L->data == NULL) // 如果分配失败（malloc 函数分配失败返回 NULL）则退出
	{
		return ERROR;
	}

	L->max_size = SEQLIST_INIT_SIZE; // 初始化表容量为 SEQLIST_INIT_SIZE
	L->length = 0; // 初始化表长度为 0

	return OK;
}


/* 顺序表的销毁 */
Status DestroyList(seq_list_s *L)
{
	free(L->data);

	L->data = NULL;
	L->max_size = 0;
	L->length = 0;

	return OK;
}


/* 顺序表的插入 */
Status ListInsert(seq_list_s *L, int i, ElemType e) // 顺序线性表已存在，在 i 位置插入元素数据元素 e，长度加一，从后向前逐个移动之后和 i 位置的元素
{
	if(L->data == NULL) // 顺序表实例不存在，则返回错误
	{
		return ERROR;
	}

	ElemType *newbase, *q, *p; // newbase 为新分配的地址。 q 为插入的位置，p 为最后一个元素的位置。p 一直减到  q 的位置

	if(i < 1 || i > L->length + 1) // 插入位置不合法，i 应该大于等于 1 且 小于等于 length + 1
		{
			return ERROR;
		}

	if(L->length == L->max_size) // 顺序表已满，需要增加存储容量
	{
		newbase = (ElemType *)realloc(L->data, (L->max_size + LIST_INCREMENT) * sizeof(ElemType)); // 重新分配更多的容量
		if(newbase == NULL)
		{
			return ERROR;
		}
		else
		{
			L->data = newbase; // 新的扩容后的地址
			L->max_size = L->max_size + LIST_INCREMENT; // 容量增加
		}
	}

	q = L->data + i - 1; // 算出 q 插入位置的地址。p 是最后一个元素的位置
	for(p = L->data + L->length -1; p >= q; p--) // 从最后一个元素开始，一个一个向后移动，直到将插入位置上的元素移到后一个，空出来插入位置
	{
		*(p + 1) = *p;  // 插入位置 q 在最后一个元素 p 之前，才执行此代码，即 p >= q
	}

	*q = e; // 插入元素
	L->length = L->length + 1; // 表长加一

	return OK;
}
