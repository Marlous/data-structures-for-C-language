/*
 * linear_list_modules.h
 *
 *  Created on: 2019/2/22
 *      Author: Mo
 */


#ifndef SRC_LINEAR_LIST_MODULES_LINEAR_LIST_MODULES_H_
#define SRC_LINEAR_LIST_MODULES_LINEAR_LIST_MODULES_H_


#define ElemType char
#define SEQLIST_INIT_SIZE 100 // 动态分配一维数组（本程序省略静态分配的，只用动态分配的）


typedef struct{
	ElemType *data; // 指示动态分配数组的指针
	int       max_size; // 储存元素的数组的最大容量
	int       length; // 当前的长度（当前存储数据元素的个数）
}seqlist_s;


/* Using module of SqList_SeqList */
Status SqListSeqList(void);

/* Using module of LNode */
Status LNode(void);

/* Using module of DNode */
Status DNode(void);


#endif /* SRC_LINEAR_LIST_MODULES_LINEAR_LIST_MODULES_H_ */
