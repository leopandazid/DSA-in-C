/*

1. 

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;

}Node;

Node* newNode (int data){
    Node *temp;
    temp->data= data;
    temp->next=NULL;
    temp->prev= NULL;
    return temp;
}

void insertBegin(Node **head,int data){
    Node *nNode = newNode(data);
    if ((*head)==NULL){
        (*head)= nNode;
    }
    else{
        nNode->next= (*head);
        (*head)->prev= nNode;
        (*head)=nNode;
    }
}

void InsertLast(Node **head,int data){
    Node *nNode= newNode(data); 
    Node *temp=(*head);
    if ((*head)==NULL){
        (*head)= newNode;
    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        // temp will contain the last node now
        nNode->prev = temp;
        temp->next = nNode;
    }
}

void display (Node *head){

}

// deletes the first element and returns 1 if the operation is successful
// 0 if not successful
// and returns num which stores the data which was deleted
int deleteFront(Node **head, int *num){

}

int deleteLast(Node *head, int *num){

}




