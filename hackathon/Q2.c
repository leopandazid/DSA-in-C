//Reverse the given singly linked list
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

void reverseList(LLIST *pl)
{
	NODE *prev=NULL,*cur=pl->head,*next=NULL;
	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	pl->head=prev;
}