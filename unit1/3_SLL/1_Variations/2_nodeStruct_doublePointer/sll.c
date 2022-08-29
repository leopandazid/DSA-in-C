#include<stdio.h>
#include"sll.h"

int main()
{
	NODE *head;
	
	initList(&head);
	
	if(head==NULL)
		printf("Empty List\n");
	else
		printf("Error\n");
}