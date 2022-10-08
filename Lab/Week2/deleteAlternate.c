#include<stdio.h>
#include<stdlib.h>
#include"deleteAlternate.h"

void initList(Node **head)
{
    (*head) = NULL;
}

Node* newNode(int data){
    Node *temp;
    temp->data=data;
    temp->next=NULL;
}

// Function to push node at the head
void push (Node **head,int data){
    Node *temp= newNode(data);
    if ((*head)==NULL){
        (*head)=temp;
    }
    else{
        temp->next=(*head);
        (*head)=temp;
    }
}

void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
    }
    printf("\n");
}

void deleteAlt(Node **head){
    // Code here
    if ((*head)== NULL || (*head)->next==NULL){
        (*head)=NULL;
        return;
    }
    // deleting the head ptr
    Node *temp=(*head);
    (*head)=(*head)->next;
    free(temp);

    int k=1;
    Node *prev=(*head);
    Node *curr = (*head);
    // delete the alternate nodes skipping the head pointer
    while(curr!=NULL){
        if (k%2==0){
            // delete the node
            prev->next = curr->next;
            free(curr);
            k++;
            curr = prev->next;
            continue;
        }
        k++;
        prev = curr;
        curr =curr->next;
    }
    
}

void destroyList(Node **head){
    Node *p;
	
	while((*head)!=NULL)
	{
		p=(*head);
		(*head)=(*head)->next;
		printf("%d freed\n",p->data);
		free(p);
	}
}


