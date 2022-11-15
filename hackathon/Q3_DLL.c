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
	struct node *prev,*next;
}NODE;

typedef struct dlist
{
	struct node* head;
}DLIST;

//a)
void insertAtPos(DLIST* pdl,int ele,int pos)
{
	int n=countNodes(pdl);
	if(pos<0 || pos>n)
		return;
	if(pos==0)
	{
		insertFront(pdl,ele);
		return;
	}
	if(pos==n)
	{
		insertLast(pdl,ele);
		return;
	}
	NODE *temp=getNode(ele);
	NODE *p=pdl->head;
	for(int i=0;i<pos;i++)
		p=p->next;
	temp->prev=p->prev;
	temp->next=p;
	p->prev->next=temp;
	p->prev=temp;
}

//b)
int countNodes(DLIST *pdl)
{
	int count=0;
	if(pdl->head==NULL)
		return count;
	NODE *p=pdl->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

//c)
void delete_Alt(DLIST *pdl){
    if (pdl->head == NULL)
        printf("Empty list...ERROR");

    NODE *previous, *current, *next;    
    previous = pdl->head;
    current = pdl->head->next;
    while (previous !=NULL && current != NULL) 
    {
        previous->next = current->next; 
        next = current->next;
        free(current);
        if(next) 
        {
            next->prev = previous;
            current = next->next;
        }
        else 
        current = NULL;
        previous = next;
    }
}