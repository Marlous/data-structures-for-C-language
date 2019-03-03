#include <core.h>
#include <config.h>


void DisplayMainMeun(void);


int main()
{
	setvbuf(stdout,NULL,_IONBF,0);  // Eclipse CDT console debug output.

	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);

	printf("# # # # # # # # # # # # # # # # # #\n");
	printf("# Data Structures for C language  #\n");
	printf("# Copyright (c) Marlous %d      #\n",1900+p->tm_year);
	printf("# # # # # # # # # # # # # # # # # #\n");

	char selectnum;
	printf("# Main menu #\n");
	DisplayMainMeun();
	printf("Please number to select:");
	scanf("%c",&selectnum);
	getchar(); // 读入 scanf() 函数留下的回车
	switch(selectnum)
	{
		case '1':
			linear_list();break;
		default:
			printf("ERROR!\n");
	}
	return 0;
}

void DisplayMainMeun(void)
{
	printf("# 1 Linear List\n");
}
