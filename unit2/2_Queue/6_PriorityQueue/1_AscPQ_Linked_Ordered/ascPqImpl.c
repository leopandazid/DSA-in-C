#include<stdio.h>
#include<stdlib.h>
#include"ascPq.h"

void initQueue(QUEUE *pq)
{
	pq->front=NULL;
}
void enqueue(QUEUE *pq,int ele,int pty)
{
	NODE *p=pq->front;
	NODE *q=NULL;
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->pri=pty;
	newNode->next=NULL;
	
	while(p!=NULL && newNode->pri > p->pri)
	{
		q=p;
		p=p->next;
	}
	
	if(q==NULL)
	{
		newNode->next=p;
		pq->front=newNode;
	}
	else
	{
		newNode->next=p;
		q->next=newNode;
	}
}

int minDelete(QUEUE *pq)
{
	NODE *p=pq->front;
	int ele=pq->front->info;
	pq->front=pq->front->next;
	free(p);
	
	return ele;
}
void destroyQueue(QUEUE *pq)
{
	NODE *p=pq->front;
	while(pq->front!=NULL)
	{
		pq->front=pq->front->next;
		printf("%d freed\n",p->info);
		free(p);
		p=pq->front;
	}
}