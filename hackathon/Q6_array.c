#include<stdio.h>

#define MAX 5
typedef struct priQ
{
	int info;
	int pri;
}PRIQ;

void insert(PRIQ *pq,int ele,int pty,int *count)
{
	int i=*count-1;
	
	PRIQ key;
	key.info=ele;
	key.pri=pty;
		
	while(i>=0 && key.pri>pq[i].pri)
	{
		pq[i+1]=pq[i];
		i--;
	}
	pq[i+1]=key;
	(*count)++;
}
PRIQ maxDelete(PRIQ *pq,int *count)
{
	PRIQ key=pq[0];
	
	for(int i=1;i<*count;i++)
		pq[i-1]=pq[i];
	(*count)--;
	
	return key;
}
void display(PRIQ *pq,int *count)
{
	if(*count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	for(int i=0;i<*count;i++)
		printf("Data:%d Pri:%d|",pq[i].info,pq[i].pri);
}

int main()
{
	PRIQ pq[MAX];
	
	int choice,ele,pri,count=0;
	PRIQ temp;
	printf("1.Enq 2.MaxDelete 3.Display\n");
	scanf("%d",&choice);
	do{
	
	switch(choice)
	{
		case 1:if(count!=MAX)
				{
				printf("Enter ele & pri\n");
				scanf("%d%d",&ele,&pri);
				insert(pq,ele,pri,&count);
				}
				else
					printf("Queue is already full\n");
				break;
		case 2:if(count)
				{
					temp=maxDelete(pq,&count);
					printf("Data:%d Pri:%d",temp.info,temp.pri);
				}
				else
					printf("Queue is already empty\n");
				break;
		case 3:display(pq,&count);
				break;
	}
	printf("\n1.Enq 2.MaxDelete 3.Display\n");
	scanf("%d",&choice);
	}while(choice<4);
}