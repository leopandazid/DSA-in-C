#include<stdio.h>
#include<stdlib.h>

/*


*/

typedef struct node{
    int col;
    int data;
    struct node *next;
}Node;

typedef struct plist{
    struct plist *down;
    struct node *head;
    struct node *tail;
}List;

void initList(List *p){
    p = NULL;
    p->down= NULL;
    p->head=NULL;
    
}

void display(List **p1){
    List *p = *p1;
    int row=0;
    while (p!=NULL){
        printf("row %d \n",row);
        Node *q = p->head;
        while (q!=NULL){
            printf("Col=%d val=%d\n", q->col,q->data);
            q=q->next;
        }
        row++;
        p= p->down;

    }
}

void InsertRow(List **obj){
    if ((*obj)->down==NULL){

    }
}



