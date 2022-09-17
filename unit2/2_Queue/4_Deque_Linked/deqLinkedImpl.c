#include<stdio.h>
#include<stdlib.h>
#include"deqLinked.h"

void initQueue(QUEUE *pq)
{
	pq->front=NULL;
	pq->rear=NULL;
}

void enqueueFront(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->data=ele;
	newNode->prev=NULL;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		newNode->next=pq->front;
		pq->front->prev=newNode;
		pq->front=newNode;
	}
}
void enqueueRear(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->data=ele;
	newNode->prev=NULL;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		newNode->prev=pq->rear;
		pq->rear->next=newNode;
		pq->rear=newNode;
	}
}
int dequeueFront(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
		return 0;
	else if(pq->rear==pq->front)
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
		pq->front=pq->front->next;
		free(pq->front->prev);
		pq->front->prev=NULL;
		return 1;
	}
}
int dequeueRear(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
		return 0;
	else if(pq->rear==pq->front)
	{
		*pele=pq->rear->data;
		free(pq->front);
		pq->front=NULL;
		pq->rear=NULL;
		return 1;
	}
	else
	{
		*pele=pq->rear->data;
		pq->rear=pq->rear->prev;
		free(pq->rear->next);
		pq->rear->next=NULL;
		return 1;
	}	
}
int isEmpty(QUEUE *pq)
{
	return pq->front==NULL;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		NODE *p=pq->front;
		
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
	
	if(pq->front!=NULL)
	{
		while(pq->front != NULL)
		{
			pq->front=pq->front->next;
			free(p);
			p=pq->front;
		}
		pq->rear=NULL;
	}
}