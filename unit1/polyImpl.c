#include<stdio.h>
#include<stdlib.h>
#include"poly2.h"

void initPolynomial(POLYNOMIAL *pl)
{
	pl->head=NULL;
}
void insertLast(POLYNOMIAL *pl,int cf,int px) // without using last node
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->coeff=cf;
	newNode->powx=px;
	newNode->next=NULL;
	
	NODE *p=pl->head;
	if(pl->head==NULL)
	{
		pl->head=newNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}

void insertLastusingLastNode(POLYNOMIAL *p1,int cf, int px){
    NODE* newNode = malloc (sizeof(NODE));
    newNode->coeff=cf;
	newNode->powx=px;
	newNode->next=NULL;
    if(p1->head==NULL)
	{
		p1->head=newNode;
        p1->last = newNode;
	}
	else
	{
        p1->last->next= newNode;
        p1->last = newNode;

	}

}

void createPolynomial(POLYNOMIAL *pl)
{
	int choice;
	int cf,px;
	
	do{
		printf("Enter coeff and power of x\n");
		scanf("%d%d",&cf,&px);
		insertLast(pl,cf,px);
		
		printf("Do you want to add one more term\n");
		scanf("%d",&choice);
		
	}while(choice);
}
int addPolynomial(POLYNOMIAL *pl1,POLYNOMIAL *pl2,POLYNOMIAL *pl3)
{
	NODE *p=pl1->head; // for traversal
	NODE *q=pl2->head;
	
	int cf,px;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->powx == q->powx)
		{
			cf=p->coeff+q->coeff;
			px=p->powx;
			p=p->next;
			q=q->next;
		}
		else if(p->powx > q->powx)
		{
			cf=p->coeff;
			px=p->powx;
			p=p->next;
		}
		else
		{
			cf=q->coeff;
			px=q->powx;
			q=q->next;
		}
		insertLast(pl3,cf,px);
	}
	while(p!=NULL)
	{
		insertLast(pl3,p->coeff,p->powx);
		p=p->next;
	}
	while(q!=NULL)
	{
		insertLast(pl3,q->coeff,q->powx);
		q=q->next;
	}
}

void display(POLYNOMIAL *pl)
{
	NODE *p=pl->head;
	
	while(p->next!=NULL)
	{
		printf("(%dx^%d)+",p->coeff,p->powx);
		p=p->next;
	}
	printf("(%dx^%d)\n",p->coeff,p->powx);
}