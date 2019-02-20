#include "SqList_SeqList.h"

// 静态分配一维数组
#define MAX_SIZE 50
typedef struct{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

// 动态分配一维数组
#define INIT_SIZE 100
typedef struct{
	ElemType *data;
	int MAX_SIZE,length;
}SeqList;
