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
Status ListDelete(seq_list_s *L, int i, ElemType *e);
int LocateElem(seq_list_s L, ElemType e);


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
	int i;
	ElemType e;

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

			case '3': // 顺序表的插入。按位置插入。插入一次只插入一个元素，依次添加进顺序表
				printf("Please enter i and e to insert:");
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

			case '4': // 顺序表的元素删除。按位置删除
				printf("Please enter i to delete:");
				scanf("%d", &i);
				getchar();
				if(ListDelete(&listcase, i, &e) == OK)
				{
					printf("ListDelete successes! Deleted %c !\n", e);
				}
				else
				{
					printf("ListDelete false!\n");
				}
				break;

			case '5': // 顺序表按值查找
				printf("Please enter e to locate:");
				scanf("%c", &e);
				getchar();
				i = LocateElem(listcase, e);
				if(i != 0)
				{
					printf("LocateElem successes! i is %d !\n", i);
				}
				else
				{
					printf("LocateElem false!\n");
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

	ElemType *newbase, *p, *q; // newbase 为新分配的地址。 p 为插入的位置，q 为最后一个元素的位置。q 一直减到  p 的位置

	if(i < 1 || i > L->length + 1) // 插入位置不合法，i 应该大于等于 1 且 小于等于 length + 1
	{
		return ERROR;
	}

	if(L->length == L->max_size) // 顺序表已满，需要增加存储容量（会自动复制原内存中的数据到新的地址）
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

	p = L->data + i - 1; // 算出 p 插入位置的地址。q 是最后一个元素的位置
	for(q = L->data + L->length -1; q >= p; q--) // 从最后一个元素开始，一个一个向后移动，直到将插入位置上的元素移到后一个，空出来插入位置
	{
		*(q + 1) = *q;  // 插入位置 q 在最后一个元素 p 之前，才执行此代码，即 p >= q
	}

	*p = e; // 插入元素
	L->length = L->length + 1; // 表长加一

	return OK;
}


/* 顺序表的删除 */
Status ListDelete(seq_list_s *L, int i, ElemType *e) // 顺序表已存在，删除 i 位置元素值。与插入操作正好相反。被删除的元素值赋给 e
{
	if(L->data == NULL) // 顺序表不存在返回错误
	{
		return ERROR;
	}

	ElemType *p, *q; //  p 为删除的位置，q 为最后一个元素的位置。p 一直减到  q 的位置

	if(i < 1 || i > L->length) // 位置不合法，i 应该大于等于 1 且 小于等于 length
	{
		return ERROR;
	}

	p = L->data + i - 1; // 删除元素位置
	*e = *p; // 删除的元素值赋给 e（通过指针引用，不用担心局部变量无法传出本函数）
	for(q = L->data + L->length - 1; p <= q; p++) // 从删除位置的下一个元素依次向前移动，直到将末尾元素移到前一个
	{
		*p = *(p + 1); // 删除位置下一个元素依次向前移动
	}
	L->length = L->length - 1; // 顺序表长度减一

	return OK;
}


/* 顺序表按值查找 */
int LocateElem(seq_list_s L, ElemType e) // 找到（第一个符合的）返回位置，没找到返回 0
{
	int site; // 类似于数组下标位置，从 0 开始
	int i; // i 为元素的位置

	if(L.data == NULL)
	{
		return 0;
	}

	for(site = 0; site < L.length; site++)
	{
		if(*(L.data + site) == e)
		{
			i = site + 1;
			return i;
		}
		else if((site + 1) != L.length)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}
