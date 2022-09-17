#include<stdio.h>
#include"josephus.h"

int main()
{
	LIST lobj;
	
	initList(&lobj);
	createList(&lobj);
	display(&lobj);
	
	int start,skip;
	
	printf("Enter start and skip value\n");
	scanf("%d%d",&start,&skip);
	printf("Winner is %d\n",winner(&lobj,start,skip));
}