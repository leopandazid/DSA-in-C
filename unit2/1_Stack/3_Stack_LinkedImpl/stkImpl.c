#include<stdio.h>
#include<stdlib.h>
#include"stk.h"

void initStack(STACK *ps)
{
	ps->top=NULL;
}

NODE* createNode(int ele)
{
	NODE* newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}
void push(STACK *ps,int ele)
{
	NODE* newNode=createNode(ele);
	
	newNode->next=ps->top;
	ps->top=newNode;	
}

void display(STACK *ps)
{
	if(ps->top==NULL)
		printf("List is Empty\n");
	else
	{
		NODE* p=ps->top;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		
	}
}

void destroyStack(STACK *ps)
{
	NODE *p;
	
	while(ps->top!=NULL)
	{
		p=ps->top;
		ps->top=ps->top->next;	//ps->top=p->next;
		printf("%d freed\n",p->info);
		free(p);
	}
}

/*precondition: List is not empty,
deleted ele info is returned back*/
int pop(STACK *ps)
{
	int delEle;
	NODE *p=ps->top;
	delEle=p->info;		//delEle=ps->top->info;
	ps->top=ps->top->next;
	free(p);
	return delEle;
}

int stackTop(STACK *ps)
{
	return ps->top->info;
}
int isEmpty(STACK *ps)
{
	return ps->top==NULL;
}