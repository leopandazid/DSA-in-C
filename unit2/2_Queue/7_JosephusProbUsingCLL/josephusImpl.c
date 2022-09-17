#include<stdio.h>
#include<stdlib.h>
#include"josephus.h"

void initList(LIST *pl)
{
	pl->head=pl->tail=NULL;
}
void createList(LIST *pl)
{
	int n;
	printf("Enter the no. of soldiers\n");
	scanf("%d",&n);
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=1;
	newNode->next=newNode;
	pl->head=pl->tail=newNode;
	
	for(int i=2;i<=n;i++)
	{
		newNode=malloc(sizeof(NODE));
		newNode->info=i;
		
		newNode->next=pl->head;
		pl->tail->next=newNode;
		pl->tail=newNode;
	}
}
void display(LIST *pl)
{
	NODE *p=pl->head;
	do
	{
		printf("%d ",p->info);
		p=p->next;
	}while(p!=pl->head);
}

int winner(LIST *pl,int start,int skip)
{
	NODE *p=pl->head;
	NODE *q=pl->tail;
	
	int count=1;
	while(count!=start)
	{
		q=p;
		p=p->next;
		count++;
	}
	
	while(p!=p->next)
	{
		for(int i=1;i!=skip;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		printf("%d killed\n",p->info);
		free(p);
		p=q->next;
	}
	int ele=p->info;
	free(p);
	pl->head=pl->tail=NULL;
	return ele;
}