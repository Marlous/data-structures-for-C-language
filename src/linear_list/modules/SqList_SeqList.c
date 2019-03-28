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


Status InitList(seqlist_s *L);


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
	printf("# 2 ListInsert(&L,i,e)\n");
	printf("# 3 DestroyList(&L)\n");
	printf("# 4 ListDelete(&L,i,&e)\n");
	printf("# 5 LocateElem(L,e)\n");
	printf("# 6 GetElem(L,i)\n");
	printf("# 7 Length(L)\n");
	printf("# 8 Empty(L)\n");
	printf("# 9 PrintList(L)\n");
	printf("# b Back!\n");
	printf("# q Exit!\n");

	return OK;
}


Status SqListSeqListMenuSelect(void)
{
	seqlist_s listcase; // 定义一个顺序表类型的变量 listcase

	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c", &selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1':
				if(InitList(&listcase) == OK)
				{
					printf("InitList successes!\n");
				}
				else
				{
					printf("InitList false!\n");
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
Status InitList(seqlist_s *L) // 接收一个定义好的变量的地址（实参是变量的地址，形参是指针变量）
{
	L->data = NULL; // 先将成员体变量 data 初始化。这里 L 前的星号表示引用实参 listcase 变量
	L->data = (ElemType *)malloc(SEQLIST_INIT_SIZE * sizeof(ElemType)); // 申请 SEQLIST_INIT_SIZE 个数的  ElemType 类型长度的空间，将指针变量（地址值）赋给 SeqList 类型的变量的成员变量（指针变量）*data

	if(L->data == NULL) // 如果分配失败（malloc 函数分配失败返回 NULL）则退出
	{
		exit(1);
	}

	L->max_size = SEQLIST_INIT_SIZE; // 初始化表容量为 SEQLIST_INIT_SIZE
	L->length = 0; // 初始化表长度为 0

	return OK;
}


/* 顺序表的插入 */
/*
void ListInsert(SeqList *L,int i,ElemType e) // 顺序线性表已存在，在 i 位置插入元素数据元素 e，长度加一
{

}
*/
