#include<stdio.h>
#include"sll.h"

int main()
{
	LLIST lobj;
	
	initList(&lobj);
	
	if(lobj.head==NULL)
		printf("Empty List\n");
	else
		printf("Error\n");
}