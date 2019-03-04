#include <config.h>
#include "linear_list.h"
#include "linear_list_modules.h"


/*
 * Declare of linear_list
 */
Status DisplayLinearListMenu(void);
Status LinearListMenuSelect(void);


/*
 * Main of linear_list
 */
Status linear_list(void)
{
	system("cls");
	DisplayLinearListMenu();
	LinearListMenuSelect();

	return OK;
}


/*
 * Sub of Main code
 */
/* Display LinearList Menu */
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

/* LinearList Menu Select */
Status LinearListMenuSelect(void)
{
	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c",&selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1':
				SqList_SeqList();
				break;
	/*		case '2':
					LNode();break;*/
	/*		case '3':
					DNode();break;*/
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
