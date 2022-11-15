//Create a priority queue
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	int pri;
	struct node *next;
}NODE;

typedef struct priqueue
{
	NODE *head;
}PRIQ;

void initQueue(PRIQ* pq)
{
	pq->head=NULL;
}
void pqInsert(PRIQ* pq,int ele,int pri)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->pri=pri;
	temp->next=NULL;
	
	NODE *p=pq->head,*q=NULL;
	
	while(p!=NULL && temp->pri>p->pri)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)  //or if(p==pq->head)
	{
		temp->next=pq->head;
		pq->head=temp;
		return;
	}
	temp->next=p;
	q->next=temp;
}

int isEmpty(PRIQ* pq)
{
	return pq->head==NULL;
}

int minDelete(PRIQ* pq)
{
	NODE *p=pq->head;
	int ele=pq->head->info;
	
	pq->head=pq->head->next;
	free(p);
	return ele;
}

void display(PRIQ* pq)
{
	NODE *p=pq->head;
	if(p==NULL)
	{
		printf("Queue is Empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d %d |",p->info,p->pri);
		p=p->next;
	}	
	printf("\n");
}

void destroyQueue(PRIQ* pq)
{
	NODE *p=pq->head;

	while(p!=NULL)
	{
		pq->head=pq->head->next;
		free(p);
		p=pq->head;
	}
}

int main()
{
	PRIQ q;

	initQueue(&q);
	int choice,ele,pri;
	
	printf("1.Insert 2.minDelete 3.Display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter the ele and pri\n");
					scanf("%d%d",&ele,&pri);
					pqInsert(&q,ele,pri);
					break;
			case 2: if(!isEmpty(&q))	
						printf("Deqd %d\n",minDelete(&q));
					else
						printf("Q is already empty\n");
					break;
			
			case 3:display(&q);
					break;
		}
		printf("1.Insert 2.minDelete 3.Display\n");
		scanf("%d",&choice);	
	}while(choice<4);
	destroyQueue(&q);
}