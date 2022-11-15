//Create an ordered singly linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* getNode(int );
NODE* ordIns(NODE*,int);
void display(NODE*);

NODE* getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
}

NODE* ordIns(NODE* phead,int ele)
{
	NODE *p=phead,*q=NULL;
	NODE* temp=getNode(ele);
	
	while(p!=NULL && temp->info > p->info)
	{ 
		q=p;
		p=p->next;
	} 

	if(q==NULL)	
	{
		temp->next=phead;
		phead=temp; 		
		return phead;
	}
	
	q->next=temp;
	temp->next=p;
	return phead;
}

void display(NODE* phead)
{
	if(phead==NULL)
	{
		printf("Empty List\n");
		return;
	}
	NODE *p=phead;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	NODE* head=NULL;
	int choice,ele,pos;
	do{
		printf("1.Insert 2.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an ele\n");;
					scanf("%d",&ele);
					head=ordIns(head,ele);
					break;
			case 2:display(head);
					break;
		}
	}while(choice<2);
}