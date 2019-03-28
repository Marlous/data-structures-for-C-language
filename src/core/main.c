/*
 * main.c
 *
 *  Created on: 2019/3/20
 *      Author: Mo
 */


#include "common.h"
#include "main.h"
#include "linear_list.h"


Status DisplayCopyrightInfo(void);
Status DisplayMainMenu(void);
Status MainMenuSelect(void);


/*
 * Main function
 */
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0); // Eclipse CDT console debug output

	system("cls");
	DisplayCopyrightInfo();
	DisplayMainMenu();
	MainMenuSelect();

	return 0;
}


/*
 * Sub function
 */
Status DisplayCopyrightInfo(void)
{
	struct tm *p;
	time_t     timep;

	time(&timep);
	p = gmtime(&timep);

	printf("# # # # # # # # # # # # # # # # # #\n");
	printf("# Data Structures for C language  #\n");
	printf("# Copyright (c) Marlous %d      #\n", 1900 + p->tm_year);
	printf("# # # # # # # # # # # # # # # # # #\n");

	return OK;
}


Status DisplayMainMenu(void)
{
	printf("\n# Main menu #\n");
	printf("# 1 Linear List\n");
	printf("# q Exit!\n");

	return OK;
}


Status MainMenuSelect(void)
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
