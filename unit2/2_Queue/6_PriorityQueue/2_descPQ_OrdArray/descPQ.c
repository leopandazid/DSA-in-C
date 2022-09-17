#include<stdio.h>
#include"descPQ.h"

void enqueue(QUEUE pq[],int info,int pri,int *count)
{
	int i=(*count)-1;
	
	QUEUE key;
	key.data=info;
	key.priority=pri;
	
	while(i>=0 && key.priority<pq[i].priority)
	{
		pq[i+1]=pq[i];
		i--;
	}
	pq[i+1]=key;
	(*count)++;
}

QUEUE dequeue(QUEUE pq[],int *count)
{
	QUEUE ele=pq[*count-1];
	
	--(*count);
	
	return ele;
}

void display(QUEUE pq[],int *count)
{
	if(*count==0)
		printf("Empty Queue\n");
	
	else
	{
		for(int i=0;i<*count;i++)
			printf("Data:%d Priority:%d | ",pq[i].data,pq[i].priority);
	}
}