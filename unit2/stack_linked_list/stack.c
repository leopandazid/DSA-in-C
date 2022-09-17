#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

void initList(STACK *ps)
{
	ps->head=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}
void push(STACK *ps,int ele)
{
	NODE* newNode=createNode(ele);
	
	newNode->next=ps->head;
	ps->head=newNode;
}


void display(STACK *ps)
{
	NODE *p=ps->head;
	
	if(ps->head==NULL)
		printf("List is empty\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
}

int pop(STACK *ps)
{
	NODE *p=ps->head;
	int ele;
	
	ele=p->info;				//ele=ps->head->info;
	ps->head=ps->head->next;	//ps->head=p->next;
	free(p);
	return ele;
}

void destroyList(STACK *ps)
{
	NODE *p;
	
	while(ps->head!=NULL)
	{
		p=ps->head;
		ps->head=ps->head->next;	//ps->head=p->next;
		printf("%d freed\n",p->info);
		free(p);
	}
}

int countNodes(STACK *ps)
{
	/*
	Think of hare and tortoise algo to find count nodes
	*/
	NODE *p=ps->head;
	int count=0;
	
	if(ps->head==NULL)
		return count;
	else
	{
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		return count;
	}
}

int insertAtPos(STACK *ps,int ele,int pos)
{
	int n=countNodes(ps);
	
	NODE *p,*newNode;
	if(pos<0 || pos>n)
		return 0;
	else if(pos==0)
	{
		insertFront(ps,ele);
		return 1;
	}
	else
	{
		p=ps->head;
		newNode=createNode(ele);
		
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		p->next=newNode;
		return 1;
	}
}
int deleteAtPos(STACK *ps,int *pele,int pos)
{
	int n=countNodes(ps); // not efficient
	
	NODE *q=NULL,*p=ps->head;
	
	if(pos<0 || pos>=n)
		return 0;
	else if(pos==0)
	{
		return deleteFront2(ps,pele);
	}
	else
	{
		for(int i=0;i<pos;i++)
		{
			q=p;// prev
			p=p->next; //next ptr
		}
		*pele=p->info;
		q->next=p->next;
		free(p);
		return 1;
	}
}