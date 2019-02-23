#include <core.h>
#include <config.h>


int main()
{
	setvbuf(stdout,NULL,_IONBF,0);  // Eclipse CDT console debug output.
	printf("main c test!\n");
	linear_list();
	SqList_SeqList();
	return 0;
}
