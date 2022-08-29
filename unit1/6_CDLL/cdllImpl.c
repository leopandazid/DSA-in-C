#include<stdio.h>
#include<stdlib.h>
#include"cdll.h"

void initList(CDLL* pl)
{
	pl->head=NULL;
}
void insertFront(CDLL* pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->head==NULL)	//Empty List
	{
		newNode->next=newNode;
		newNode->prev=newNode;
		pl->head=newNode;
	}
	else
	{
		NODE *last=pl->head->prev;
		
		newNode->next=pl->head;
		newNode->prev=last;
		last->next=newNode;
		pl->head->prev=newNode;
		pl->head=newNode;
	}
}
void insertLast(CDLL* pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->head==NULL)	//Empty List
	{
		newNode->next=newNode;
		newNode->prev=newNode;
		pl->head=newNode;
	}
	else
	{
		NODE *last=pl->head->prev;
		
		newNode->next=pl->head;
		newNode->prev=last;
		last->next=newNode;
		pl->head->prev=newNode;
	}		
}
int countNodes(CDLL* pl)
{
	NODE *last;
	NODE* p=pl->head;
	int count=0;
	if(pl->head==NULL)
		return count;
	else
	{
		last=pl->head->prev;
		while(p!=last)
		{
			count++;
			p=p->next;
		}
		count++;
		return count;
	}
}
int insertAtPos(CDLL* pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 ||pos>n)
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
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=ele;
		NODE *p=pl->head;
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		newNode->prev=p;
		p->next->prev=newNode;
		p->next=newNode;
		return 1;
		
	}
}
void destroyList(CDLL* pl)
{
	if(pl->head==NULL)
		return;
	else
	{
		NODE *last=pl->head->prev;
		
		while(pl->head!=last)
		{
			printf("Freed %d\n",pl->head->info);
			pl->head=pl->head->next;
			free(pl->head->prev);
		}
		printf("Freed %d\n",pl->head->info);
		free(pl->head);
		pl->head=NULL;
	}
}
void display(CDLL* pl)
{
	if(pl->head==NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=pl->head;
		NODE *last=pl->head->prev;
		
		while(p!=last)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("%d\n",p->info);
	}
}
int deleteFront(CDLL* pl,int *pele)
{
	if(pl->head==NULL)
		return 0;
	if(pl->head==pl->head->next)
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}
	else
	{
		*pele=pl->head->info;
		NODE *last=pl->head->prev;
		pl->head->next->prev=last;
		last->next=pl->head->next;
		free(pl->head);
		pl->head=last->next;
		return 1;
	}
}
int deleteLast(CDLL* pl,int *pele)
{
	if(pl->head==NULL)
		return 0;
	if(pl->head==pl->head->next)
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}
	else
	{
		NODE *last=pl->head->prev;
		
		last->prev->next=pl->head;
		pl->head->prev=last->prev;
		*pele=last->info;
		free(last);
		return 1;
	}
}
int deleteAtPos(CDLL* pl,int *pele,int pos)
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
		for(int i=1;i<pos;i++)
			p=p->next;
		
		*pele=p->info;
		p->next->prev=p->prev;
		p->prev->next=p->next;
		free(p);
		return 1;
	}
}