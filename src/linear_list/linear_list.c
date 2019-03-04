#include <core.h>
#include "linear_list.h"
#include "linear_list_modules.h"


/*
 * Declare of linear_list
 */
void DisplayLinearListMenu(void);
void LinearListMenuSelect(void);


/*
 * Main of linear_list
 */
int linear_list(void)
{
	system("cls");
	DisplayLinearListMenu();
	LinearListMenuSelect();

	return 0;
}


/*
 * Sub of Main code
 */
/* Display LinearList Menu */
void DisplayLinearListMenu(void)
{
	printf("# linear list #\n");
	printf("# 1 SqList and SeqList\n");
	printf("# 2 LNode\n");
	printf("# 3 DNode\n");
	printf("# b Back!\n");
	printf("# q Exit!\n");
}

/* LinearList Menu Select */
void LinearListMenuSelect(void)
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
				system("cls");
				main();
				break;
			case 'q':
				exit(0);
				break;
			default:
				printf("ERROR!\n");
				break;
		}
	}

}
