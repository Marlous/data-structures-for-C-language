#include <core.h>
#include "linear_list.h"
#include "linear_list_modules.h"


void DisplayLinearList(void);


int linear_list(void)
{
	char selectnum;
	printf("# linear list #\n");
	DisplayLinearList();
	printf("Please enter number to select:");
	scanf("%c",&selectnum);
	getchar(); // 读入 scanf() 函数留下的回车
	switch(selectnum)
	{
		case '1':
			SqList_SeqList();break;
/*		case '2':
			LNode();break;*/
/*		case '3':
			DNode();break;*/
		case 'b':
			main();break;
		default:
			printf("ERROR!\n");
	}
	return 0;
}

void DisplayLinearList(void)
{
	printf("# 1 SqList and SeqList\n");
	printf("# 2 LNode\n");
	printf("# 3 DNode\n");
	printf("# b Back!\n");
}
