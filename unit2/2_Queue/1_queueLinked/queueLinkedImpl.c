#include<stdio.h>
#include<stdlib.h>
#include"queueLinked.h"

void initQueue(QUEUE *pq)
{
	pq->front=NULL;
	pq->rear=NULL;
}

void enqueue(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->data=ele;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=pq->rear=newNode;
	}
	else
	{
		pq->rear->next=newNode;
		pq->rear=newNode;	//pq->rear=pq->rear->next;
	}
}
int dequeue(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
	{
		return 0;
	}
	else if(pq->front==pq->rear)	//Single node
	{
		*pele=pq->front->data;
		free(pq->front);
		pq->front=NULL;
		pq->rear=NULL;
		return 1;
	}
	else
	{
		*pele=pq->front->data;
		NODE *p=pq->front;
		
		pq->front=pq->front->next;
		free(p);
		return 1;
	}
}
int isEmpty(QUEUE *pq)
{
	return pq->front==NULL;	//return pq->rear==NULL;
}
void display(QUEUE *pq)
{
	NODE *p=pq->front;
	
	if(p==NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
	}
}
void destroyQueue(QUEUE *pq)
{
	NODE *p=pq->front;
	
	if(p==NULL)
		return;
	else
	{
		while(pq->front!=NULL)
		{
			pq->front=pq->front->next;
			free(p);
			p=pq->front;
		}
	}
	pq->rear=NULL;
}