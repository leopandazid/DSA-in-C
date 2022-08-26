#include<stdio.h>
#include<stdlib.h>

// circular doubly linked list
// CDLL
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}Node;


// initialize the head pointer as null 
void initList(Node **head){
    (*head)=NULL;
}

Node* newNode(int data){
    Node *n = malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    return n;
}

void InsertFront(Node **head,int ele){
    Node *temp= newNode(ele);
    if ((*head)==NULL){
        temp->prev= temp;
        temp->next= temp;
        (*head)= temp;
    }
    else{
        Node *last = (*head)->prev;
        temp->next= (*head);
        temp->prev = last;
        last->next =temp;
        (*head)->prev= temp;
        (*head)=temp;
    }
}

void InsertLast(Node **head,int ele){
    Node *temp= newNode(ele);
    if ((*head)==NULL){
        temp->prev= temp;
        temp->next= temp;
        (*head)= temp;
    }
    else{
        Node *last = (*head)->prev;
        temp->prev= last;
        temp->next = (*head);
        last->next = temp;
        (*head)->prev= temp;
    }
        
}

void InsertAtPos(Node **head, int ele,int pos){
    Node *temp= newNode(ele);
    if (pos<= 0){
        return;
    }
    if ((*head)==NULL || pos==1){
        temp->prev= temp;
        temp->next= temp;
        (*head)= temp;
    }
    else{
        int c=1;
        Node *p= (*head)->next;
        while (c!=pos && p !=(*head)){
            c++;
            p=p->next; // p will have the current pos
        }

    }

}

void DestroyList (Node **head){
    if ((*head)==NULL)
        return;
    else{
        Node *last = (*head)->prev;
        while((*head)!=last){
            last->next = (*head)->next;
            (*head)= (*head)->next;
            free((*head)->prev);
            (*head)->prev =last;
        }
    }
}

int DeleteFront(Node **head,int *ele){
    if ((*head)==NULL){
        return 0;
    }
    else if ((*head)== (*head)->next){ // only one element
        *ele = (*head)->data;
        free((*head));
        (*head)=NULL;
        return 1;
    } 
    else{
        Node *last = (*head)->prev;
        
    }
}




