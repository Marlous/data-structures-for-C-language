#include "SqList_SeqList.h"

// 静态分配的一维数组实现。
#define MAX_SIZE 50
typedef struct{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

// 动态分配的一维数组实现。
#define INIT_SIZE 100
typedef struct{
	ElemType *data;
	int MAX_SIZE,length;
}SeqList;
