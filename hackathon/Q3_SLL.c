/*Perform the following operations on a singly/doubly linked list.

    a) Insert at the given position

    b) Delete alternate nodes, starting from the first node in the given list

    c) Count the number of nodes
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node*next;
}NODE;

typedef struct llist
{
	NODE* head;
}LLIST;

//a)
void insertAtPos(LLIST* pl,int ele,int pos)
{
	int n=countNodes(pl);
	NODE *temp=getNode(ele);
	if(pos<0 || pos>n) return;
	if(pos==0)
	{
		temp->next=pl->head;
		pl->head=temp;
		return;
	}
	NODE *p=pl->head,*q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}

//b)
void deleteAlternate(LLIST *pl)
{
	if(pl->head==NULL)
		return;
	NODE *p=pl->head,*toDelete=NULL;
	while(p!=NULL)
	{
		if(p->info%2==0)
		{
			toDelete=p;
			p=p->next;
			deleteNode(pl,toDelete);
		}
		else
			p=p->next;
	}
}

//c)
int countNodes(LLIST *pl)
{
	NODE *p=pl->head;
	int count=0;
	
	if(pl->head==NULL)
		return count;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}