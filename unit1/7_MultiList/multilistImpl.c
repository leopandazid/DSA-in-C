#include<stdio.h>
#include<stdlib.h>
#include"multilist.h"

void initList(LIST **pl)
{
	*pl=NULL;
}

void createList(LIST **pl)
{
	LIST *p;
	int choice;
	int row=0;
	
	do
	{
		printf("Row %d added\n",row);
		row++;
		LIST *newNode=malloc(sizeof(LIST));
		newNode->down=NULL;
		newNode->head=NULL;
		newNode->tail=NULL;
		
		if(*pl==NULL)
		{
			*pl=newNode;
			p=newNode;
		}
		else
		{
			p->down=newNode;
			p=p->down;
		}
		printf("Do you want to add one more row\n");
		scanf("%d",&choice);
	}while(choice);
	
	p=*pl;
	row=0;
	
	while(p!=NULL)
	{
		printf("Do you want to add entries to row %d\n",row);
		scanf("%d",&choice);
		
		if(choice)
		{
			do
			{
				NODE *newNode=malloc(sizeof(NODE));
				printf("Enter the col No. and value\n");
				scanf("%d%d",&newNode->col,&newNode->val);
				newNode->next=NULL;
				
				if(p->head==NULL)
				{
					p->head=newNode;
					p->tail=newNode;
				}
				else
				{
					p->tail->next=newNode;
					p->tail=p->tail->next;	//p->tail=newNode;
				}
				
				printf("Do you want to add more entries to row %d\n",row);
				scanf("%d",&choice);
			}while(choice);
		}
		p=p->down;
		row++;
	}
}

void display(LIST **pl)
{
	LIST *p=*pl;
	int row=0;
	
	while(p!=NULL)
	{
		NODE *q=p->head;
		printf("\nRow %d\n",row);
		while(q!=NULL)
		{
			printf("Col:%d, Val:%d",q->col,q->val);
			q=q->next;
		}
		row++;
		p=p->down;
	}
}