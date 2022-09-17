#include<stdio.h>
#include"descPQ.h"

int main()
{
	QUEUE pq[MAX];
	int count=0;
	
	if(count==MAX)
		printf("Queue is Full\n");
	else
		enqueue(pq,100,100,&count);
	
	if(count==MAX)
		printf("Queue is Full\n");
	else
		enqueue(pq,10,10,&count);
	
	if(count==MAX)
		printf("Queue is Full\n");
	else
		enqueue(pq,50,50,&count);
	
	if(count==MAX)
		printf("Queue is Full\n");
	else
		enqueue(pq,1000,1000,&count);
	
	display(pq,&count);
	
	QUEUE deqEle;
	if(count==0)
		printf("Empty Queue\n");
	else{
		deqEle=dequeue(pq,&count);
		printf("\nDeqd ele: info:%d pri:%d",deqEle.data,deqEle.priority);
	}
	
	if(count==0)
		printf("Empty Queue\n");
	else{
		deqEle=dequeue(pq,&count);
		printf("\nDeqd ele: info:%d pri:%d",deqEle.data,deqEle.priority);
	}
	
	if(count==0)
		printf("Empty Queue\n");
	else{
		deqEle=dequeue(pq,&count);
		printf("\nDeqd ele: info:%d pri:%d",deqEle.data,deqEle.priority);
	}
	
	if(count==0)
		printf("Empty Queue\n");
	else{
		deqEle=dequeue(pq,&count);
		printf("\nDeqd ele: info:%d pri:%d",deqEle.data,deqEle.priority);
	}
}