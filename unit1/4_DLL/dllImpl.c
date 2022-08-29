#include<stdio.h>
#include<stdlib.h>
#include"dll.h"

void initList(DLIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(int ele)
{
	NODE* newNode=malloc(sizeof(NODE));
	newNode->prev=NULL;
	newNode->next=NULL;
	newNode->info=ele;
	
	return newNode;
}

void insertFront(DLIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)
		pl->head=newNode;
	else
	{
		newNode->next=pl->head;
		pl->head->prev=newNode;
		
		pl->head=newNode;
	}
}

void insertLast(DLIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	NODE*p=pl->head;
	
	if(pl->head==NULL)
		pl->head=newNode;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		newNode->prev=p;
		p->next=newNode;
	}
}
void display(DLIST *pl)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)
		printf("List is empty\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
}

int deleteFront(DLIST *pl,int *pele)
{
	if(pl->head==NULL)	//List empty
		return 0;
	else if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}		//Multiple node case
	else
	{
		*pele=pl->head->info;
		pl->head=pl->head->next;
		free(pl->head->prev);
		pl->head->prev=NULL;
		return 1;
	}
}
void destroyList(DLIST *pl)
{
	if(pl->head==NULL)
		return;
	else
	{
		while(pl->head->next!=NULL)
		{
			printf("%d freed\n",pl->head->info);
			pl->head=pl->head->next;
			free(pl->head->prev);
		}
		printf("%d freed\n",pl->head->info);
		free(pl->head);
		pl->head=NULL;
	}
}
int deleteLast(DLIST *pl,int *pele)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)	//List empty
		return 0;
	else if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}		//Multiple node case
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		*pele=p->info;
		p->prev->next=NULL;
		free(p);
		return 1;
	}
}

int countNodes(DLIST *pl)
{
	NODE *p=pl->head;
	int count=0;
	
	if(pl->head==NULL)
		return count;
	else
	{
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		return count;
	}
}

int insertAtPos(DLIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>n)
		return 0;
	else if(pos==0)
	{
		insertFront(pl,ele);
		return 1;
	}
	else if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
	}
	else
	{
		NODE *p=pl->head;
		
		NODE *newNode=createNode(ele);
		
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		newNode->prev=p;
		p->next->prev=newNode;
		p->next=newNode;
	}
}
int deleteAtPos(DLIST *pl,int *pele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>=n)
		return 0;
	else if(pos==0)
		return deleteFront(pl,pele);
	else if(pos==n-1)
		return deleteLast(pl,pele);
	else
	{
		NODE *p=pl->head;
		for(int i=0;i<pos;i++)
			p=p->next; // p will be at current pos
		
		*pele=p->info;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		return 1;
	}
}