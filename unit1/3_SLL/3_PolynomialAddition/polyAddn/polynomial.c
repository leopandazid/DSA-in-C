#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void initList(poly **head)
{
    (*head) = NULL;
}

void insertLast(poly **head,int cf,int px,int py)
{
	poly *newNode=malloc(sizeof(poly));
	newNode->coeff=cf;
	newNode->px=px;
    newNode->py=py;
	newNode->next=NULL;
	
	poly *p=(*head);
	if((*head)==NULL)
	{
		(*head)=newNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}

void createList(poly **head)
{
    int choice;
    int cf, px,py;

    do
    {
        printf("Enter coeff and power of x and power of y \n");
        scanf("%d%d%d", &cf, &px,&py);
        insertLast((head), cf, px,&py);

        printf("Do you want to add one more term\n");
        scanf("%d", &choice);

    } while (choice);
}

void addPoly(poly *head1, poly *head2, poly **ans)
{
    
}
void display(poly *head)
{
    poly *p=head;
	
	while(p->next!=NULL)
	{
		printf("(%dx^%dy^%d)+",p->coeff,p->px,p->py);
		p=p->next;
	}
	printf("(%dx^%dy^%d)\n",p->coeff,p->px,p->py);
}
void destroyPolynomial(poly **head)
{
    poly *p;
	
	while((*head)!=NULL)
	{
		p=(*head);
		(*head)=(*head)->next;
		free(p);
	}
}
