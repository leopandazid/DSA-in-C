#include<stdio.h>
#include"deqLinked.h"
//To be edited
int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	int ele,choice,status;
	
	do
	{
		printf("1.EnqueueFront 2.EnqueueRear 3.DequeueFront 4.DequeueRear 5.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueFront(&qobj,ele);
					break;
			case 2: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueRear(&qobj,ele);
					break;
			case 3:status=dequeueFront(&qobj,&ele);
					if(status==0)
						printf("Queue is already empty\n");
					else
						printf("Deqd %d\n",ele);
					break;
			case 4:status=dequeueRear(&qobj,&ele);
					if(status==0)
						printf("Queue is already empty\n");
					else
						printf("Deqd %d\n",ele);
					break;
			case 5:display(&qobj);
					break;
		}
	}while(choice<6);
	destroyQueue(&qobj);
}