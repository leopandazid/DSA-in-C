#include<stdio.h>
#include"deqArray.h"

void initQueue(QUEUE *pq)
{
	pq->front=-1;
	pq->rear=-1;
}
void enqueueRear(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[pq->rear]=ele;
	}
	else
	{
		pq->rear=(pq->rear+1)%MAX;
		pq->q[pq->rear]=ele;
	}
}
void enqueueFront(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[pq->front]=ele;
	}
	else
	{
		pq->front=(pq->front-1+MAX)%MAX;
		pq->q[pq->front]=ele;
	}	
}
int dequeueRear(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
		return 0;
	else if(pq->front==pq->rear)	//Single element
	{
		*pele=pq->q[pq->rear];
		initQueue(pq);
		return 1;
	}
	else
	{
		*pele=pq->q[pq->rear];
		pq->rear=(pq->rear-1+MAX)%MAX;
		return 1;
	}	
}

int dequeueFront(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
		return 0;
	else if(pq->front==pq->rear)	//Single element
	{
		*pele=pq->q[pq->front];
		initQueue(pq);
		return 1;
	}
	else
	{
		*pele=pq->q[pq->front];
		pq->front=(pq->front+1)%MAX;
		return 1;
	}
}
int isEmpty(QUEUE *pq)
{
	return pq->front==-1;		//return pq->rear==-1;
}
int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		int i;
		for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
		{
			printf("%d ",pq->q[i]);
		}
		printf("%d\n",pq->q[i]);
	}
}