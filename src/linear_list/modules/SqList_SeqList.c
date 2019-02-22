#include <core.h>
#include "linear_list_modules.h"

// 静态分配一维数组
#define SQLIST_DATA_MAX_SIZE 50
typedef struct{
	ElemType data[SQLIST_DATA_MAX_SIZE];
	int length;
}SqList;

// 动态分配一维数组
#define INIT_SIZE 100
typedef struct{
	ElemType *data;
	int MAX_SIZE;
	int length;
}SeqList;
