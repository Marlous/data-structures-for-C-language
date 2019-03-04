#include <config.h>
#include<main.h>


/*
 * Declare of Main code
 */
Status DisplayCopyrightInfo(void);
Status DisplayMainMenu(void);
Status MainMenuSelect(void);


/*
 * Main of Main code
 */
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);  // Eclipse CDT console debug output.

	system("cls");
	DisplayCopyrightInfo();
	DisplayMainMenu();
	MainMenuSelect();

	return 0;
}


/*
 * Sub of Main code
 */
/* Display Copyright Info */
Status DisplayCopyrightInfo(void)
{
	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);

	printf("# # # # # # # # # # # # # # # # # #\n");
	printf("# Data Structures for C language  #\n");
	printf("# Copyright (c) Marlous %d      #\n",1900+p->tm_year);
	printf("# # # # # # # # # # # # # # # # # #\n");

	return OK;
}

/* Display Main Menu */
Status DisplayMainMenu(void)
{
	printf("\n# Main menu #\n");
	printf("# 1 Linear List\n");
	printf("# q Exit!\n");

	return OK;
}

/* Main Menu Select */
Status MainMenuSelect(void)
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
				linear_list();
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
