#include<stdio.h>
#include"queueArray.h"

void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}
int enqueue(QUEUE *pq,int ele)
{
	if(isFull(pq))
		return 0;
	else
	{
		pq->a[++pq->rear]=ele;
		return 1;
	}
}
int dequeue(QUEUE *pq,int *pele)
{
	if(isEmpty(pq))
		return 0;
	else
	{
		*pele=pq->a[pq->front++];
		
		if(pq->front >pq->rear)
		{
			pq->front=0;
			pq->rear=-1;
		}
		return 1;
	}
}
int isEmpty(QUEUE *pq)
{
	return pq->front>pq->rear;
}
int isFull(QUEUE *pq)
{
	return pq->rear==MAX-1;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		for(int i=pq->front;i<=pq->rear;i++)
		{
			printf("%d ",pq->a[i]);
		}
	}
}