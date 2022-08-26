#include<stdio.h>
#include <stdlib.h>

// circular linked list with head implementation

typedef struct node{
    int data;
    struct node *next;
}Node;

// CLL operations

// create a new node
Node* newNode(int data){
    Node *n=malloc(sizeof(Node));
    n->data=data; 
} 

// insert at head
void InsertFront(Node **head,int ele){
    
}



// delete a node with given element

