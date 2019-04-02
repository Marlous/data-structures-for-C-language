/*
 * linear_list.c
 *
 *  Created on: 2019/3/20
 *      Author: Mo
 */


#include "common.h"
#include "main.h"
#include "linear_list.h"
#include "linear_list_modules.h"


Status DisplayLinearListMenu(void);
Status LinearListMenuSelect(void);


/*
 * Main function
 */
Status LinearList(void)
{
	system("cls");
	DisplayLinearListMenu();
	LinearListMenuSelect();

	return OK;
}


/*
 * Sub function
 */
Status DisplayLinearListMenu(void)
{
	printf("# linear list #\n");
	printf("# 1 SqList and SeqList\n");
	printf("# 2 LNode\n");
	printf("# 3 DNode\n");
	printf("# b Back!\n");
	printf("# q Exit!\n");

	return OK;
}


Status LinearListMenuSelect(void)
{
	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c", &selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1':
				SqListSeqList();
				break;

	/*		case '2':
					LNode();
					break;*/

	/*		case '3':
					DNode();
					break;*/

			case 'b':
				main();
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
